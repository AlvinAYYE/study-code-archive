/*
 * LeetCode 462. Minimum Moves to Equal Array Elements II／讓陣列元素相等的最少移動次數 II
 *
 * 題目（繁體中文）
 *   給定整數陣列 nums。一次操作可以將任一元素加 1 或減 1，請回傳讓所有
 *   元素都相等所需的最少操作次數。
 *
 * 範例 1：nums=[1,2,3]，最佳目標值是 2，總共移動 2 次，輸出 2。
 * 範例 2：nums=[1,10,2,9]，最佳目標可選 2 或 9，最少移動次數為 16。
 * 限制：1 <= nums.length <= 10^5；-10^9 <= nums[i] <= 10^9；
 *   題目保證答案可放入 32 位元整數。
 *
 * 解題步驟：
 *   1. 對任一目標值 x，總操作數是所有 |nums[i]-x| 的總和。
 *   2. 絕對差總和在中位數處最小，因此先排序，選排序後的中間元素作目標。
 *   3. 用 64 位元累加每個元素到中位數的距離，最後依題目保證轉回 int。
 *   排序時間 O(n log n)，複製陣列與排序需要 O(n) 額外空間；輸入陣列保持不變。
 *
 * LeetCode C API：int minMoves2(int* nums, int numsSize)。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compareIntegers(const void *left, const void *right) {
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b); /* 不以相減比較，避免整數溢位。 */
}

/* ---------- LeetCode submission / 提交區 ---------- */
int minMoves2(int *nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) return 0;
    int *sorted = (int *)malloc((size_t)numsSize * sizeof *sorted);
    if (sorted == NULL) return 0;
    memcpy(sorted, nums, (size_t)numsSize * sizeof *sorted);
    qsort(sorted, (size_t)numsSize, sizeof *sorted, compareIntegers);

    int median = sorted[numsSize / 2];
    long long moves = 0;
    for (int i = 0; i < numsSize; ++i) {
        long long difference = (long long)sorted[i] - median;
        moves += difference < 0 ? -difference : difference;
    }
    free(sorted);
    return (int)moves; /* 題目保證答案符合 int 範圍。 */
}
/* ---------- end submission ---------- */

int main(void) {
    int example1[] = {1, 2, 3};
    int example2[] = {1, 10, 2, 9};
    int example3[] = {5};
    int passed = minMoves2(example1, 3) == 2 &&
                 minMoves2(example2, 4) == 16 &&
                 minMoves2(example3, 1) == 0 &&
                 example1[0] == 1 && example2[0] == 1;

    puts(passed ? "PASS: 462 minimum-moves-to-equal-array-elements-ii"
                : "FAIL: 462 minimum-moves-to-equal-array-elements-ii");
    return passed ? 0 : 1;
}
