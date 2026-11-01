/*
 * ==========================================================================
 * UVa 10359 - Tiling
 * Title-CN: 2 x n 骨牌與正方形鋪滿計數
 * Difficulty: Easy
 * Tags: Math, DP, Big Integer
 * URL: https://onlinejudge.org/external/103/10359.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of ways to tile a 2 x n rectangular board using 2 x 1 dominoes and 2 x 2 squares.
 *
 * [中文] 題目說明:
 *     求用 2 x 1 骨牌與 2 x 2 正方形完全鋪滿 2 x n 矩形網格的方案數。
 *
 * [EN] Approach:
 *     Recurrence relation: f(n) = f(n-1) + 2*f(n-2) with f(0) = 1, f(1) = 1, f(2) = 3.
 * [中文] 思路:
 *     遞推關係式：最後一列放豎骨牌有 f(n-1) 種；放兩橫骨牌或一 2x2 正方形有 2*f(n-2) 種，故 f(n) = f(n-1) + 2*f(n-2)。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

long long count_tilings_2xn(int n) {
    long long f[50];
    f[0] = 1; f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + 2 * f[i - 2];
    }
    return f[n];
}

int main(void) {

    int ok = (count_tilings_2xn(2) == 3) && (count_tilings_2xn(3) == 5) && (count_tilings_2xn(4) == 11);
    printf("%s: UVa 10359 - Tiling\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
