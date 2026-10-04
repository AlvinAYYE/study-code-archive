/*
 * ==========================================================================
 * LeetCode 015. 3Sum
 * Title-CN: 三數之和
 * Difficulty: Medium
 * Tags: array, two-pointers, sorting
 * URL: https://leetcode.com/problems/3sum/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an integer array nums, return all the triplets [nums[i], nums[j],
 *     nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 *     nums[k] == 0.
 *     Notice that the solution set must not contain duplicate triplets.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     找出陣列中所有和為 0 且不重複的三元組。
 *
 * Examples:
 *   Example 1:
 *     Input: nums = [-1,0,1,2,-1,-4]
 *     Output: [[-1,-1,2],[-1,0,1]]
 *     Explanation:
 *     nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 *     nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 *     nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 *     The distinct triplets are [-1,0,1] and [-1,-1,2].
 *     Notice that the order of the output and the order of the triplets
 *     does not matter.
 *   Example 2:
 *     Input: nums = [0,1,1]
 *     Output: []
 *     Explanation: The only possible triplet does not sum up to 0.
 *   Example 3:
 *     Input: nums = [0,0,0]
 *     Output: [[0,0,0]]
 *     Explanation: The only possible triplet sums up to 0.
 *
 * Constraints:
 *   - 3 <= nums.length <= 3000
 *   - -10^5 <= nums[i] <= 10^5
 *
 * LeetCode official C stub (函式簽名):
 *   int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [EN] Approach: Sort, then for each i use two pointers on the suffix; skip duplicates on all three positions. Time O(n^2), space O(1) besides output.
 * [中文] 思路: 先排序，固定 i 後在尾段用雙指針湊 -nums[i]，三個位置都跳過重複。時間 O(n^2)、除輸出外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static int cmpint(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int **out = NULL; int *cols = NULL; int cap = 0, cnt = 0, i, j, k;
    *returnSize = 0; *returnColumnSizes = NULL;
    qsort(nums, (size_t)numsSize, sizeof(int), cmpint);
    for (i = 0; i + 2 < numsSize; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        if (nums[i] > 0) break;
        j = i + 1; k = numsSize - 1;
        while (j < k) {
            int s = nums[i] + nums[j] + nums[k];
            if (s > 0) --k;
            else if (s < 0) ++j;
            else {
                int *row = (int *)malloc(3 * sizeof(int));
                row[0] = nums[i]; row[1] = nums[j]; row[2] = nums[k];
                if (cnt == cap) {
                    cap = cap ? cap * 2 : 16;
                    out  = (int **)realloc(out, (size_t)cap * sizeof(int *));
                    cols = (int *)realloc(cols, (size_t)cap * sizeof(int));
                }
                out[cnt] = row; cols[cnt] = 3; ++cnt;
                do { ++j; } while (j < k && nums[j] == nums[j - 1]);
                do { --k; } while (j < k && nums[k] == nums[k + 1]);
            }
        }
    }
    *returnSize = cnt;
    *returnColumnSizes = cols;
    return out;
}
/* ---------- end submission ---------- */

static int cmprow(const void *a, const void *b) {
    const int *x = *(const int * const *)a, *y = *(const int * const *)b;
    if (x[0] != y[0]) return (x[0] > y[0]) - (x[0] < y[0]);
    if (x[1] != y[1]) return (x[1] > y[1]) - (x[1] < y[1]);
    return (x[2] > y[2]) - (x[2] < y[2]);
}

static int run(const char *tag, int *a, int n, const int *exp, int expCnt) {
    int rs = 0; int *cols = NULL; int **out = threeSum(a, n, &rs, &cols);
    int i, j;    if (rs != expCnt) { printf("  fail %s: got %d rows want %d\n", tag, rs, expCnt); return 0; }
    if (rs) qsort(out, (size_t)rs, sizeof(int *), cmprow);
    for (i = 0; i < rs; ++i) {
        if (cols[i] != 3) { printf("  fail %s: cols\n", tag); return 0; }
        for (j = 0; j < 3; ++j)
            if (out[i][j] != exp[i * 3 + j]) { printf("  fail %s row %d\n", tag, i); return 0; }
    }
    return 1;
}

int main(void) {
    int ok = 1;
    int a1[] = {-1, 0, 1, 2, -1, -4};
    const int e1[] = { -1, -1, 2, -1, 0, 1 };
    ok = ok && run("ex1", a1, 6, e1, 2);
    int a2[] = {0, 1, 1};
    ok = ok && run("ex2", a2, 3, NULL, 0);
    int a3[] = {0, 0, 0, 0};
    const int e3[] = { 0, 0, 0 };
    ok = ok && run("ex3", a3, 4, e3, 1);
    int a4[] = {-2, 0, 1, 1, 2};
    const int e4[] = { -2, 0, 2, -2, 1, 1 };
    ok = ok && run("ex4", a4, 5, e4, 2);
    printf("%s: 015 3sum\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
