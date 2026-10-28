/*
 * Title-CN: 資料流中的第 K 大元素
 * LeetCode 703. Kth Largest Element in a Stream
 *
 * 題意完整翻譯：
 *   設計 KthLargest 資料結構，持續接收整數。建立時會給定 k 與初始陣列 nums；每次 add(val)
 *   加入新數字後，回傳目前所有數字排序後第 k 大的值。相同數值也要分別計入名次。
 *
 * 範例：
 *   1. k = 3，初始 nums = [4,5,8,2]。依序加入 3、5、10、9、4，回傳值依序為 4、5、5、8、8。
 *   2. k = 4，初始 nums = [7,7,7,7,8,3]。依序加入 2、10、9、9，回傳值依序為 7、7、7、8。
 *
 * 限制：
 *   - 0 <= nums.length <= 10^4
 *   - 1 <= k <= nums.length + 1
 *   - -10^4 <= nums[i], val <= 10^4
 *   - add 最多呼叫 10^4 次
 *
 * 解題步驟：
 *   1. 維護一個最多放 k 個元素的最小堆；堆頂是目前保留下來的 k 個最大數字中最小的，也就是第 k 大。
 *   2. 若堆還不到 k 個元素，就把新值放入堆並向上調整。
 *   3. 若堆已滿且新值大於堆頂，用新值取代堆頂，再向下調整；否則新值不可能進入前 k 大，忽略即可。
 *   4. 每次 add 後回傳堆頂。初始資料也用相同的加入方式處理。
 *
 * 複雜度：
 *   時間：建立需 O(m log k)，m 是初始元素數；每次 add 為 O(log k)。
 *   空間：O(k)，最小堆最多保存 k 個數字。
 *
 * LeetCode C API：
 *   KthLargest* kthLargestCreate(int k, int* nums, int numsSize); int
 *   kthLargestAdd(KthLargest* obj, int val); void kthLargestFree(KthLargest*
 *   obj);
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int k;
    int size;
    int* heap;
} KthLargest;

static void heapSwap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

static void siftUp(KthLargest* obj, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (obj->heap[parent] <= obj->heap[index]) {
            break;
        }
        heapSwap(&obj->heap[parent], &obj->heap[index]);
        index = parent;
    }
}

static void siftDown(KthLargest* obj, int index) {
    while (1) {
        int smallest = index;
        int left = index * 2 + 1;
        int right = left + 1;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest]) {
            smallest = left;
        }
        if (right < obj->size && obj->heap[right] < obj->heap[smallest]) {
            smallest = right;
        }
        if (smallest == index) {
            break;
        }

        heapSwap(&obj->heap[index], &obj->heap[smallest]);
        index = smallest;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    int i;

    obj->k = k;
    obj->size = 0;
    obj->heap = (int*)malloc(sizeof(int) * (size_t)k);

    for (i = 0; i < numsSize; ++i) {
        kthLargestAdd(obj, nums[i]);
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size] = val;
        ++obj->size;
        siftUp(obj, obj->size - 1);
    } else if (val > obj->heap[0]) {
        // 堆頂是目前前 k 大數字中最小的一個。
        obj->heap[0] = val;
        siftDown(obj, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    if (obj == NULL) return;
    free(obj->heap);
    free(obj);
}

int main(void) {
    int nums[] = {4, 5, 8, 2};
    KthLargest* stream = kthLargestCreate(3, nums, 4);
    assert(kthLargestAdd(stream, 3) == 4);
    assert(kthLargestAdd(stream, 5) == 5);
    assert(kthLargestAdd(stream, 10) == 5);
    assert(kthLargestAdd(stream, 9) == 8);
    assert(kthLargestAdd(stream, 4) == 8);
    kthLargestFree(stream);

    puts("PASS 0703 KthLargest");
    return 0;
}
