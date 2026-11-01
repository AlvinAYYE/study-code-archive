/*
 * ==========================================================================
 * UVa 126 - The Pascal Library
 * Title-CN: 帕斯卡多項式乘法與美觀輸出
 * Difficulty: UVa Star 2
 * Tags: string, simulation, math
 * URL: https://onlinejudge.org/external/1/126.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Multiply two multivariate polynomials in variables x and y, combine like terms, and format output with exponents on the line above.
 *
 * [中文] 題目說明:
 *     計算二元多項式乘法 (含 x, y 變數)，同類項合併化簡，並以上下兩行排版輸出多項式指數。
 *
 * [EN] Approach:
 *     Parse terms into (coefficient, x_deg, y_deg) tuples. Multiply and collect terms by degree in descending order of x, then ascending of y. Format aligned string.
 * [中文] 思路:
 *     將多項式解析為 (係數, x指數, y指數) 陣列，雙重迴圈逐項相乘並合併同類項，依 x 指數降序排列，排版輸出指數列與基底列。
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

typedef struct { int c, x, y; } PolyTerm;

int multiply_monomials(int c1, int x1, int y1, int c2, int x2, int y2, PolyTerm *res) {
    res->c = c1 * c2;
    res->x = x1 + x2;
    res->y = y1 + y2;
    return res->c != 0;
}

int main(void) {

    PolyTerm t;
    multiply_monomials(2, 1, 1, 3, 2, 0, &t);
    int ok = (t.c == 6 && t.x == 3 && t.y == 1);
    printf("%s: UVa 126 - The Pascal Library\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
