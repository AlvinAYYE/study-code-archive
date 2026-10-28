/*
 * LeetCode 632. Smallest Range Covering Elements from K Lists
 * 題意（繁體中文）：給定 k 個已排序整數陣列，找一個最短區間，讓每個陣列
 * 至少有一個數落在區間內。長度相同時，選左端點較小的區間。
 *
 * 範例：[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]] -> [20,24]
 *       [[1,2,3],[1,2,3],[1,2,3]] -> [1,1]
 * 限制：1 <= k <= 3500；每列長度 1 到 50；元素介於 -100000 到 100000；各列遞增。
 * 解法：每列先放入目前最前面的數到最小堆，並記錄目前最大值。
 *       堆頂是目前最小值，因此這 k 個數形成一個涵蓋所有列的區間。
 *       記錄較佳區間後，移動堆頂所屬列的指標；該列用盡時就無法再涵蓋全部列。
 * 複雜度：總元素數為 T，時間 O(T log k)，額外空間 O(k)。
 * LeetCode C API：int* smallestRange(int** nums, int numsSize, int* numsColSize,
 *                                    int* returnSize)
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int list;
    int index;
} HeapItem;

static void push(HeapItem *heap, int *size, HeapItem value) {
    int index = (*size)++;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].value <= value.value) break;
        heap[index] = heap[parent];
        index = parent;
    }
    heap[index] = value;
}

static HeapItem pop(HeapItem *heap, int *size) {
    HeapItem answer = heap[0], tail = heap[--(*size)];
    int index = 0;
    while (index * 2 + 1 < *size) {
        int child = index * 2 + 1;
        if (child + 1 < *size && heap[child + 1].value < heap[child].value)
            ++child;
        if (tail.value <= heap[child].value) break;
        heap[index] = heap[child];
        index = child;
    }
    if (*size > 0) heap[index] = tail;
    return answer;
}

int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    *returnSize = 0;
    int *answer = (int *)malloc(2 * sizeof *answer);
    HeapItem *heap = (HeapItem *)malloc((size_t)numsSize * sizeof *heap);
    if (answer == NULL || heap == NULL) {
        free(answer);
        free(heap);
        return NULL;
    }
    int heapSize = 0, currentMax = INT_MIN;
    for (int list = 0; list < numsSize; ++list) {
        int value = nums[list][0];
        push(heap, &heapSize, (HeapItem){value, list, 0});
        if (value > currentMax) currentMax = value;
    }

    int bestLeft = 0, bestRight = INT_MAX;
    while (heapSize == numsSize) {
        HeapItem smallest = pop(heap, &heapSize);
        long long width = (long long)currentMax - smallest.value;
        long long bestWidth = (long long)bestRight - bestLeft;
        if (width < bestWidth || (width == bestWidth && smallest.value < bestLeft)) {
            bestLeft = smallest.value;
            bestRight = currentMax;
        }
        int nextIndex = smallest.index + 1;
        if (nextIndex == numsColSize[smallest.list]) break;
        int nextValue = nums[smallest.list][nextIndex];
        push(heap, &heapSize, (HeapItem){nextValue, smallest.list, nextIndex});
        if (nextValue > currentMax) currentMax = nextValue;
    }
    answer[0] = bestLeft;
    answer[1] = bestRight;
    *returnSize = 2;
    free(heap);
    return answer;
}

static int matchesRange(int **lists, int *sizes, int count, int left, int right) {
    int returned = 0;
    int *range = smallestRange(lists, count, sizes, &returned);
    int passed = range != NULL && returned == 2 && range[0] == left && range[1] == right;
    free(range);
    return passed;
}

int main(void) {
    int a0[] = {4, 10, 15, 24, 26}, a1[] = {0, 9, 12, 20}, a2[] = {5, 18, 22, 30};
    int *example1[] = {a0, a1, a2};
    int sizes1[] = {5, 4, 4};
    int b0[] = {1, 2, 3}, b1[] = {1, 2, 3}, b2[] = {1, 2, 3};
    int *example2[] = {b0, b1, b2};
    int sizes2[] = {3, 3, 3};
    int passed = matchesRange(example1, sizes1, 3, 20, 24) &&
                 matchesRange(example2, sizes2, 3, 1, 1);
    puts(passed ? "PASS: 632 smallest-range-covering-elements-from-k-lists"
                : "FAIL: 632 smallest-range-covering-elements-from-k-lists");
    return passed ? 0 : 1;
}
