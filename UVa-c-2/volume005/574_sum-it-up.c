/*
 * ==========================================================================
 * UVa 574 - Sum It Up
 * Title-CN: 子集總和全部組合列舉 (剪枝與去重回溯)
 * Difficulty: UVa Star 2
 * Tags: backtracking, recursion, subset-sum
 * URL: https://onlinejudge.org/external/5/574.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all unique combinations of a multiset of integers that sum up to target t, outputting in non-increasing order.
 *
 * [中文] 題目說明:
 *     給定目標和 t 與整數多重集，回溯列舉出所有總和恰為 t 的不重複子集，並按降序排列輸出。
 *
 * [EN] Approach:
 *     Backtracking recursion with duplicate skipping: if adjacent elements are identical, only pick the first occurrence in the current branch.
 * [中文] 思路:
 *     對陣列由大到小排序後回溯搜尋。若遇到相鄰相同數值且未被選中，則跳過避免輸出重複相同的加法表達式。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int found_574;
static int cur_574[15];

void dfs_574(int idx, int cur_sum, int target, int n, const int *a, int count) {
    if (cur_sum == target) {
        found_574++;
        return;
    }
    for (int i = idx; i < n; i++) {
        if (i > idx && a[i] == a[i - 1]) continue; /* Skip duplicate */
        if (cur_sum + a[i] <= target) {
            cur_574[count] = a[i];
            dfs_574(i + 1, cur_sum + a[i], target, n, a, count + 1);
        }
    }
}

int solve_uva574(int target, int n, const int *a) {
    found_574 = 0;
    dfs_574(0, 0, target, n, a, 0);
    return found_574;
}

int main(void) {

    int a[6] = {4, 3, 2, 2, 1, 1};
    int ok = (solve_uva574(4, 6, a) == 4); /* 4, 3+1, 2+2, 2+1+1 */
    printf("%s: UVa 574 - Sum It Up\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
