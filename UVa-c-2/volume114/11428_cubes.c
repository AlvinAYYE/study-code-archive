/*
 * ==========================================================================
 * UVa 11428 - Cubes
 * Title-CN: 立方之差等式枚舉 (x^3 - y^3 = N)
 * Difficulty: UVa Star 1
 * Tags: math, brute-force
 * URL: https://onlinejudge.org/external/114/11428.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given integer N, find smallest integers x > y > 0 such that x^3 - y^3 = N.
 *
 * [中文] 題目說明:
 *     給定整數 N，尋找滿足 x^3 - y^3 = N 且 y 最小的正整數解 (x, y)。
 *
 * [EN] Approach:
 *     Loop y from 1 upwards, then loop x > y until x^3 - y^3 >= N. Return first match.
 * [中文] 思路:
 *     雙重枚舉 y 與 x (x > y)，當立方差等於 N 時立即回傳；若立方差已大於 N 則跳出內層迴圈，以確保 y 最小。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11428(int n, int *ans_x, int *ans_y) {
    for (int y = 1; y * y * y <= 100000; y++) {
        for (int x = y + 1; ; x++) {
            int diff = x * x * x - y * y * y;
            if (diff == n) { *ans_x = x; *ans_y = y; return 1; }
            if (diff > n) break;
        }
    }
    return 0;
}

int main(void) {

    int x, y;
    int ok = solve_uva11428(37, &x, &y) && (x == 4 && y == 3);
    printf("%s: UVa 11428 - Cubes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
