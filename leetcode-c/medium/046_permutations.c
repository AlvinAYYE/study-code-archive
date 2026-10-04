/*
 * ==========================================================================
 * LeetCode 046. Permutations
 * Title-CN: 全排列
 * Difficulty: Medium
 * Tags: array, backtracking
 * URL: https://leetcode.com/problems/permutations/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an array nums of distinct integers, return all the possible
 *     permutations. You can return the answer in any order.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     回傳一個不含重複數字陣列的所有排列。
 *
 * Examples:
 *   Example 1:
 *     Input: nums = [1,2,3]
 *     Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *   Example 2:
 *     Input: nums = [0,1]
 *     Output: [[0,1],[1,0]]
 *   Example 3:
 *     Input: nums = [1]
 *     Output: [[1]]
 *
 * Constraints:
 *   - 1 <= nums.length <= 6
 *   - -10 <= nums[i] <= 10
 *   - All the integers of nums are unique.
 *
 * LeetCode official C stub (函式簽名):
 *   int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [EN] Approach: Backtracking with a used[] bitmap, swapping into position or appending unused elements recursively. n! outputs, O(n*n!).
 * [中文] 思路: 回溯：維護 used[] 布林陣列依序選元素；共 n! 個排列，時間 O(n·n!)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static void bt(int *nums, int n, int *cur, int pos, char *used, int **out, int *cnt) {
    int i;
    if (pos == n) {
        int *row = (int *)malloc((size_t)n * sizeof(int));
        memcpy(row, cur, (size_t)n * sizeof(int));
        out[(*cnt)++] = row;
        return;
    }
    for (i = 0; i < n; ++i) {
        if (used[i]) continue;
        used[i] = 1; cur[pos] = nums[i];
        bt(nums, n, cur, pos + 1, used, out, cnt);
        used[i] = 0;
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int total = 1, i, cnt = 0;
    int **out, *cols, *cur; char *used;
    for (i = 2; i <= numsSize; ++i) total *= i;
    out  = (int **)malloc((size_t)total * sizeof(int *));
    cols = (int *)malloc((size_t)total * sizeof(int));
    cur  = (int *)malloc((size_t)numsSize * sizeof(int));
    used = (char *)calloc((size_t)numsSize, 1);
    bt(nums, numsSize, cur, 0, used, out, &cnt);
    for (i = 0; i < cnt; ++i) cols[i] = numsSize;
    *returnSize = cnt;
    *returnColumnSizes = cols;
    free(cur); free(used);
    return out;
}
/* ---------- end submission ---------- */

static int gN;
static int cmprow(const void *a, const void *b) {
    const int *x = *(const int * const *)a, *y = *(const int * const *)b;
    int i;
    for (i = 0; i < gN; ++i)
        if (x[i] != y[i]) return x[i] < y[i] ? -1 : 1;
    return 0;
}
static int run(const char *tag, int *a, int n) {
    int rs = 0; int *cols = NULL; int **out; int i, j, total = 1;
    gN = n;
    out = permute(a, n, &rs, &cols);
    for (i = 2; i <= n; ++i) total *= i;
    if (rs != total) { printf("  fail %s: got %d want %d\n", tag, rs, total); return 0; }
    qsort(out, (size_t)rs, sizeof(int *), cmprow);
    for (i = 1; i < rs; ++i)
        if (cmprow(&out[i - 1], &out[i]) == 0) { printf("  fail %s: duplicate rows\n", tag); return 0; }
    for (i = 0; i < rs; ++i) {            /* each row must be a permutation */
        int sum = 0, want = 0, okrow = 1;
        for (j = 0; j < n; ++j) { sum += out[i][j]; want += a[j]; }
        okrow = (sum == want);
        if (!okrow) { printf("  fail %s: bad row sum\n", tag); return 0; }
    }
    for (i = 0; i < rs; ++i) free(out[i]);
    free(out); free(cols);
    return 1;
}

int main(void) {
    int ok = 1;
    int a1[] = {1, 2, 3};
    int a2[] = {0, 1};
    int a3[] = {1, 2, 3, 4};
    ok = ok && run("ex1", a1, 3);
    ok = ok && run("ex2", a2, 2);
    ok = ok && run("ex3", a3, 4);
    printf("%s: 046 permutations\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
