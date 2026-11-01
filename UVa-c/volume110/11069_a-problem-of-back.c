/*
 * ==========================================================================
 * UVa 11069 - A Problem of Back
 * Title-CN: 背包無連續相鄰選取方案數
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, recurrence
 * URL: https://onlinejudge.org/external/110/11069.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find number of subsets of {1..n} such that no two elements differ by 1, and difference between adjacent chosen elements is <= 2.
 *
 * [中文] 題目說明:
 *     從 1 到 n 中選取子集，要求任兩元素差不能為 1 (不能相鄰)，且相鄰被選元素差不能超過 2，求合法子集數。
 *
 * [EN] Approach:
 *     Recurrence relation: dp[n] = dp[n - 2] + dp[n - 3].
 * [中文] 思路:
 *     線性遞迴動態規劃：結尾元素若為 n，前一個元素必為 n-2 或 n-3。滿足轉移方程 dp[n] = dp[n-2] + dp[n-3]。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva11069(int n) {
    long long dp[80] = {0, 1, 2, 2};
    for (int i = 4; i <= n; i++) dp[i] = dp[i - 2] + dp[i - 3];
    return dp[n];
}

int main(void) {

    int ok = (solve_uva11069(1) == 1) && (solve_uva11069(2) == 2) && (solve_uva11069(3) == 2) && (solve_uva11069(4) == 3);
    printf("%s: UVa 11069 - A Problem of Back\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
