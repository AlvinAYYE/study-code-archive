/*
 * LeetCode 295. Find Median from Data Stream
 * Title-CN: 從資料串流中找中位數
 *
 * 題目翻譯：設計 MedianFinder，讓資料可以逐筆加入，並隨時查詢目前所有數字的中位數。
 * 若數量是奇數，中位數是排序後正中間的值；若數量是偶數，中位數是中間兩值的平均數。
 *
 * 範例：addNum(1)、addNum(2)、findMedian() -> 1.5；再 addNum(3)，
 * findMedian() -> 2.0。另一個例子：[2,3,4] 的中位數是 3；[2,3] 的中位數是 2.5。
 *
 * 限制：-10^5 <= num <= 10^5；呼叫 findMedian 前至少加入一個數；addNum 與 findMedian
 * 的總呼叫次數最多 5 * 10^4。回傳值與正確答案相差不超過 10^-5 即可。
 * 進階追問：若所有數字都在 [0,100]，或其中 99% 都在 [0,100]，如何利用值域改善解法？
 *
 * 解題思路：把已加入的數分成兩個堆。low 是最大堆，存較小的一半；high 是最小堆，存較大的一半。
 * 維持 low 的元素數量等於 high，或比 high 多一個，且 low 的最大值不大於 high 的最小值。
 * 1. 加入數字時，先依 low 堆頂決定放入哪一堆。
 * 2. 若兩堆大小差超過 1，就把較多那一堆的堆頂移到另一堆，恢復平衡。
 * 3. 奇數個數時回傳 low 堆頂；偶數個數時取兩堆堆頂平均。先轉成 double 再相加，避免整數溢位。
 *
 * 複雜度：addNum O(log n)，findMedian O(1)，空間 O(n)。
 *
 * LeetCode C API：
 * MedianFinder *medianFinderCreate(void);
 * void medianFinderAddNum(MedianFinder *obj, int num);
 * double medianFinderFindMedian(MedianFinder *obj);
 * void medianFinderFree(MedianFinder *obj);
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *values;
    size_t size;
    size_t capacity;
    int isMaxHeap;
} IntHeap;

typedef struct {
    IntHeap lower; /* 最大堆：較小的一半 */
    IntHeap upper; /* 最小堆：較大的一半 */
} MedianFinder;

static int hasHigherPriority(const IntHeap *heap, int left, int right) {
    return heap->isMaxHeap ? left > right : left < right;
}

static int heapReserve(IntHeap *heap, size_t needed) {
    if (heap->capacity >= needed) return 1;

    size_t newCapacity = heap->capacity == 0 ? 16 : heap->capacity;
    while (newCapacity < needed) newCapacity *= 2;

    int *newValues = (int *)realloc(heap->values, newCapacity * sizeof *newValues);
    if (newValues == NULL) return 0;
    heap->values = newValues;
    heap->capacity = newCapacity;
    return 1;
}

static void heapPushReserved(IntHeap *heap, int value) {
    size_t index = heap->size++;
    while (index > 0) {
        size_t parent = (index - 1) / 2;
        if (!hasHigherPriority(heap, value, heap->values[parent])) break;
        heap->values[index] = heap->values[parent];
        index = parent;
    }
    heap->values[index] = value;
}

static int heapPop(IntHeap *heap) {
    int result = heap->values[0];
    int last = heap->values[--heap->size];
    if (heap->size == 0) return result;

    size_t index = 0;
    while (index * 2 + 1 < heap->size) {
        size_t child = index * 2 + 1;
        if (child + 1 < heap->size &&
            hasHigherPriority(heap, heap->values[child + 1], heap->values[child])) {
            ++child;
        }
        if (!hasHigherPriority(heap, heap->values[child], last)) break;
        heap->values[index] = heap->values[child];
        index = child;
    }
    heap->values[index] = last;
    return result;
}

MedianFinder *medianFinderCreate(void) {
    MedianFinder *obj = (MedianFinder *)calloc(1, sizeof *obj);
    if (obj != NULL) {
        obj->lower.isMaxHeap = 1;
        obj->upper.isMaxHeap = 0;
    }
    return obj;
}

void medianFinderAddNum(MedianFinder *obj, int num) {
    if (obj == NULL) return;

    /* 預先確保任一邊需要接收新值或搬移值時都有容量。 */
    if (!heapReserve(&obj->lower, obj->lower.size + 1) ||
        !heapReserve(&obj->upper, obj->upper.size + 1)) {
        return;
    }

    if (obj->lower.size == 0 || num <= obj->lower.values[0]) {
        heapPushReserved(&obj->lower, num);
    } else {
        heapPushReserved(&obj->upper, num);
    }

    if (obj->lower.size > obj->upper.size + 1) {
        heapPushReserved(&obj->upper, heapPop(&obj->lower));
    } else if (obj->upper.size > obj->lower.size) {
        heapPushReserved(&obj->lower, heapPop(&obj->upper));
    }
}

double medianFinderFindMedian(MedianFinder *obj) {
    if (obj == NULL || obj->lower.size == 0) return 0.0;
    if (obj->lower.size > obj->upper.size) return (double)obj->lower.values[0];
    return ((double)obj->lower.values[0] + (double)obj->upper.values[0]) / 2.0;
}

void medianFinderFree(MedianFinder *obj) {
    if (obj == NULL) return;
    free(obj->lower.values);
    free(obj->upper.values);
    free(obj);
}

static int approximatelyEqual(double actual, double expected) {
    return fabs(actual - expected) < 1e-9;
}

int main(void) {
    MedianFinder *finder = medianFinderCreate();
    if (finder == NULL) return 1;

    medianFinderAddNum(finder, 1);
    medianFinderAddNum(finder, 2);
    int passed = approximatelyEqual(medianFinderFindMedian(finder), 1.5);
    medianFinderAddNum(finder, 3);
    passed = passed && approximatelyEqual(medianFinderFindMedian(finder), 2.0);

    medianFinderAddNum(finder, -10);
    passed = passed && approximatelyEqual(medianFinderFindMedian(finder), 1.5);
    medianFinderAddNum(finder, 10);
    passed = passed && approximatelyEqual(medianFinderFindMedian(finder), 2.0);
    medianFinderFree(finder);

    finder = medianFinderCreate();
    if (finder == NULL) return 1;
    medianFinderAddNum(finder, -100000);
    medianFinderAddNum(finder, 100000);
    passed = passed && approximatelyEqual(medianFinderFindMedian(finder), 0.0);
    medianFinderFree(finder);

    finder = medianFinderCreate();
    if (finder == NULL) return 1;
    const int stream[] = {-5, -3, -3, 0, 4, 8, 1, 9, 2};
    const double medians[] = {-5, -4, -3, -3, -3, -1.5, 0, 0.5, 1};
    for (size_t i = 0; i < sizeof stream / sizeof stream[0]; ++i) {
        medianFinderAddNum(finder, stream[i]);
        if (!approximatelyEqual(medianFinderFindMedian(finder), medians[i])) passed = 0;
    }
    medianFinderFree(finder);

    puts(passed ? "PASS: 295 find-median-from-data-stream"
                : "FAIL: 295 find-median-from-data-stream");
    return passed ? 0 : 1;
}
