/*
 * ==========================================================================
 * UVa 11455 - Behold my quadrangle
 * Title-CN: 四邊形幾何形態分類判定
 * Difficulty: UVa Star 1
 * Tags: geometry
 * URL: https://onlinejudge.org/external/114/11455.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given 4 positive segment lengths, classify the quadrangle into square, rectangle, generic quadrangle, or banana (impossible).
 *
 * [中文] 題目說明:
 *     給定四條正線段長度，判斷其是否可構成正方形、長方形、普通四邊形或根本無法構成四邊形 (banana)。
 *
 * [EN] Approach:
 *     Sort 4 lengths. Check square: all equal. Rectangle: a=b and c=d. Quadrangle: longest < sum of other three.
 * [中文] 思路:
 *     將四邊由小到大排序：四邊皆等為 square；兩兩相等為 rectangle；最大邊小於其餘三邊之和為 quadrangle；否則為 banana。
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

int solve_uva11455(int a, int b, int c, int d) {
    int s[4] = {a, b, c, d};
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (s[i] > s[j]) { int tmp = s[i]; s[i] = s[j]; s[j] = tmp; }
    if (s[0] == s[3]) return 1; // square
    if (s[0] == s[1] && s[2] == s[3]) return 2; // rectangle
    if (s[3] < s[0] + s[1] + s[2]) return 3; // quadrangle
    return 4; // banana
}

int main(void) {

    int ok = (solve_uva11455(10, 10, 10, 10) == 1 &&
              solve_uva11455(10, 20, 10, 20) == 2 &&
              solve_uva11455(2, 3, 4, 5) == 3 &&
              solve_uva11455(1, 1, 1, 10) == 4);
    printf("%s: UVa 11455 - Behold my quadrangle\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
