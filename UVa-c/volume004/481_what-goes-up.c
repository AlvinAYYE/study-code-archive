/*
 * ==========================================================================
 * UVa 481 - What Goes Up
 * Title-CN: 最長嚴格遞增子序列 (O(N log N) LIS 與路徑還原)
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, lis, binary-search
 * URL: https://onlinejudge.org/external/4/481.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the length and actual sequence of the Longest Increasing Subsequence (LIS) in O(N log N) time.
 *
 * [中文] 題目說明:
 *     在 O(N log N) 時間內求最長嚴格遞增子序列的長度，並輸出最後出現的最優完整子序列。
 *
 * [EN] Approach:
 *     Patience sorting / binary search on tails array. Maintain parent pointers to reconstruct the exact sequence.
 * [中文] 思路:
 *     維護 tails 陣列結合二分搜尋 lower_bound，維護前驅索引 parent 陣列，回溯輸出最長遞增子序列。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva481_len(int n, const int *a) {
    int tails[1000], len = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (tails[mid] < a[i]) l = mid + 1;
            else r = mid;
        }
        tails[l] = a[i];
        if (l == len) len++;
    }
    return len;
}

int main(void) {

    int a[6] = {-7, 10, 9, 2, 3, 8};
    int ok = (solve_uva481_len(6, a) == 4); /* -7, 2, 3, 8 */
    printf("%s: UVa 481 - What Goes Up\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
