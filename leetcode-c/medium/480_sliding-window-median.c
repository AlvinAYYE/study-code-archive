/*
 * LeetCode 480. Sliding Window Median／滑動視窗中位數
 *
 * 題目（繁體中文）
 *   給定整數陣列 nums 和視窗大小 k。大小為 k 的視窗從陣列左端開始，每次
 *   向右移一格。對每個視窗回傳其中位數；若 k 為偶數，中位數是中間兩數的
 *   平均值。
 *
 * 範例 1：nums=[1,3,-1,-3,5,3,6,7]、k=3，輸出
 *   [1,-1,-1,3,5,6]。
 * 範例 2：nums=[1,2,3,4,2,3,1,4,2]、k=3，輸出
 *   [2,3,3,3,2,3,2]。
 * 限制：1 <= k <= nums.length <= 10^5；nums[i] 為 32 位元有號整數；
 *   答案與正確中位數相差不超過 10^-5 即視為正確。
 *
 * 解題步驟：
 *   1. 先排序一份 nums 複本並去重，作為所有可能數值的座標表。
 *   2. 用 Fenwick Tree 記錄目前視窗中每個座標出現幾次；移動視窗時，舊值
 *      次數減一、新值次數加一。
 *   3. 用 Fenwick Tree 的前綴頻率查找第 k/2 個與第 k/2+1 個元素；奇數視窗
 *      取中間一個，偶數視窗取兩者平均。
 *   排序及每次更新/查詢共 O(n log n)，空間 O(n)，原陣列不會被修改。
 *
 * LeetCode C API：double* medianSlidingWindow(int* nums, int numsSize,
 * int k, int* returnSize)。回傳陣列由呼叫端釋放。
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

static int compareIntegers(const void *left, const void *right) {
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b);
}

static int lowerBound(const int *values, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (values[middle] < target) left = middle + 1;
        else right = middle;
    }
    return left;
}

static void fenwickAdd(int *tree, int size, int index, int delta) {
    for (int i = index + 1; i <= size; i += i & -i) tree[i] += delta;
}

/* 回傳 0-based 座標中第 rank 小的值；rank 使用 1-based 名次。 */
static int fenwickFindByRank(const int *tree, int size, int rank) {
    int index = 0;
    int step = 1;
    while (step <= size / 2) step <<= 1;
    for (; step > 0; step >>= 1) {
        int next = index + step;
        if (next <= size && tree[next] < rank) {
            index = next;
            rank -= tree[next];
        }
    }
    return index;
}

/* ---------- LeetCode submission / 提交區 ---------- */
double *medianSlidingWindow(int *nums, int numsSize, int k, int *returnSize) {
    if (returnSize == NULL) return NULL;
    *returnSize = 0;
    if (nums == NULL || numsSize <= 0 || k <= 0 || k > numsSize) return NULL;

    int resultCount = numsSize - k + 1;
    double *result = (double *)malloc((size_t)resultCount * sizeof *result);
    int *coordinates = (int *)malloc((size_t)numsSize * sizeof *coordinates);
    int *tree = (int *)calloc((size_t)numsSize + 1, sizeof *tree);
    if (result == NULL || coordinates == NULL || tree == NULL) {
        free(result);
        free(coordinates);
        free(tree);
        return NULL;
    }

    memcpy(coordinates, nums, (size_t)numsSize * sizeof *coordinates);
    qsort(coordinates, (size_t)numsSize, sizeof *coordinates, compareIntegers);
    int uniqueCount = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (uniqueCount == 0 || coordinates[i] != coordinates[uniqueCount - 1])
            coordinates[uniqueCount++] = coordinates[i];
    }

    for (int i = 0; i < k; ++i) {
        int index = lowerBound(coordinates, uniqueCount, nums[i]);
        fenwickAdd(tree, uniqueCount, index, 1);
    }

    for (int start = 0; start < resultCount; ++start) {
        if (k % 2 == 1) {
            int middleIndex = fenwickFindByRank(tree, uniqueCount, k / 2 + 1);
            result[start] = coordinates[middleIndex];
        } else {
            int lowerIndex = fenwickFindByRank(tree, uniqueCount, k / 2);
            int upperIndex = fenwickFindByRank(tree, uniqueCount, k / 2 + 1);
            /* 先轉成 long long，避免兩個極端 int 相加時溢位。 */
            result[start] = ((long long)coordinates[lowerIndex] +
                             coordinates[upperIndex]) / 2.0;
        }

        if (start + 1 < resultCount) {
            int leaving = lowerBound(coordinates, uniqueCount, nums[start]);
            int entering = lowerBound(coordinates, uniqueCount, nums[start + k]);
            fenwickAdd(tree, uniqueCount, leaving, -1);
            fenwickAdd(tree, uniqueCount, entering, 1);
        }
    }

    free(coordinates);
    free(tree);
    *returnSize = resultCount;
    return result;
}
/* ---------- end submission ---------- */

static int closeEnough(double actual, double expected) {
    double difference = actual - expected;
    if (difference < 0.0) difference = -difference;
    return difference < 1e-9;
}

static int checkMedians(int *nums, int size, int k,
                        const double *expected, int expectedSize) {
    int resultSize = 0;
    double *actual = medianSlidingWindow(nums, size, k, &resultSize);
    int passed = actual != NULL && resultSize == expectedSize;
    for (int i = 0; passed && i < expectedSize; ++i)
        passed = closeEnough(actual[i], expected[i]);
    free(actual);
    return passed;
}

int main(void) {
    int example1[] = {1, 3, -1, -3, 5, 3, 6, 7};
    const double expected1[] = {1, -1, -1, 3, 5, 6};
    int example2[] = {1, 2, 3, 4, 2, 3, 1, 4, 2};
    const double expected2[] = {2, 3, 3, 3, 2, 3, 2};
    int evenWindow[] = {1, 4, 2, 3};
    const double expectedEven[] = {2.5, 3.0, 2.5};
    int singleton[] = {INT_MIN, INT_MAX};
    const double expectedSingleton[] = {INT_MIN, INT_MAX};
    int passed = checkMedians(example1, 8, 3, expected1, 6) &&
                 checkMedians(example2, 9, 3, expected2, 7) &&
                 checkMedians(evenWindow, 4, 2, expectedEven, 3) &&
                 checkMedians(singleton, 2, 1, expectedSingleton, 2);

    puts(passed ? "PASS: 480 sliding-window-median"
                : "FAIL: 480 sliding-window-median");
    return passed ? 0 : 1;
}
