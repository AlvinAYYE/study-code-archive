/*
 * ==========================================================================
 * UVa 900 - Brick Wall Patterns
 * Title-CN: 磚牆砌法圖案數 (費氏數列 DP)
 * Difficulty: UVa Star 1
 * Tags: math, dynamic-programming, fibonacci
 * URL: https://onlinejudge.org/external/9/900.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count ways to build a 2 x n wall using 1 x 2 and 2 x 1 bricks.
 *
 * [中文] 題目說明:
 *     用 1x2 與 2x1 的骨牌磚塊鋪滿 2 x n 的牆面，求相異排法總數 (即費氏數列 F(n))。
 *
 * [EN] Approach:
 *     F(n) = F(n-1) + F(n-2) with F(1) = 1, F(2) = 2. Precompute up to n = 50.
 * [中文] 思路:
 *     標準骨牌鋪磚動態規劃：最後一塊直放有 F(n-1) 種，兩塊橫放有 F(n-2) 種，為費氏數列。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva900(int n) {
    long long f[55] = {0, 1, 2};
    for (int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int main(void) {

    int ok = (solve_uva900(1) == 1) && (solve_uva900(2) == 2) && (solve_uva900(3) == 3);
    printf("%s: UVa 900 - Brick Wall Patterns\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
