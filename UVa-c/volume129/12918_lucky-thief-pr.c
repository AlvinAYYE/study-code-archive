/*
 * ==========================================================================
 * UVa 12918 - Lucky Thief
 * Title-CN: 幸運竊賊鑰匙嘗試次數
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/129/12918.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find maximum number of failed key attempts to open n doors using m keys (n <= m).
 *
 * [中文] 題目說明:
 *     手中有 m 把鑰匙要開 n 扇門 (每扇門對應一把鑰匙)。求開完所有門最多可能嘗試失敗的總次數。
 *
 * [EN] Approach:
 *     Formula: sum_{i=0}^{n-1} (m - 1 - i) = n*(m - 1) - n*(n - 1)/2.
 * [中文] 思路:
 *     最壞嘗試次數：第一扇門最多試 m-1 次，第二扇門試 m-2 次... 第 n 扇門試 m-n 次，等差級數求和公式求解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva12918(long long n, long long m) {
    return n * (m - 1) - n * (n - 1) / 2;
}

int main(void) {

    int ok = (solve_uva12918(1, 3) == 2) && (solve_uva12918(2, 3) == 3);
    printf("%s: UVa 12918 - Lucky Thief\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
