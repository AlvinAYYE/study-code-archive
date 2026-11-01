/*
 * ==========================================================================
 * UVa 11854 - Egypt
 * Title-CN: 埃及直角三角形判定 (畢氏定理逆定理)
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/118/11854.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if triangle with given sides a, b, c is a right triangle (Pythagorean theorem).
 *
 * [中文] 題目說明:
 *     給定三角形三邊長，判定其是否為直角三角形 (畢氏定理逆定理 a^2 + b^2 = c^2)。
 *
 * [EN] Approach:
 *     Sort sides so that c is largest. Check if a^2 + b^2 == c^2.
 * [中文] 思路:
 *     找出最大邊作為斜邊，檢驗兩較小邊的平方和是否恰等於最大邊的平方。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11854(int a, int b, int c) {
    int s[3] = {a, b, c};
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (s[i] > s[j]) { int t = s[i]; s[i] = s[j]; s[j] = t; }
        }
    }
    return (s[0] * s[0] + s[1] * s[1] == s[2] * s[2]);
}

int main(void) {

    int ok = solve_uva11854(6, 8, 10) && !solve_uva11854(25, 52, 60);
    printf("%s: UVa 11854 - Egypt\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
