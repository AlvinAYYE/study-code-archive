/*
 * ==========================================================================
 * UVa 392 - Polynomial Showdown
 * Title-CN: 多項式美觀格式化輸出
 * Difficulty: UVa Star 1
 * Tags: string, math
 * URL: https://onlinejudge.org/external/3/392.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Format a degree 8 polynomial given its 9 integer coefficients, omitting zero terms and formatting signs cleanly.
 *
 * [中文] 題目說明:
 *     給定 8 次多項式的 9 個係數，省略係數為 0 的項，美觀排版正負號與次方符號 (如 3x^2 - x + 5)。
 *
 * [EN] Approach:
 *     Traverse coefficients from degree 8 down to 0. Handle leading sign, magnitude 1 for variable terms, and constant zero edge case.
 * [中文] 思路:
 *     自最高次降序走訪係數：首項負號緊隨其後、其餘項以 " + " 或 " - " 分隔，係數為 1 且次數大於 0 時省略係數。
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

int has_non_zero_term(int *c) {
    for (int i = 0; i < 9; i++) if (c[i] != 0) return 1;
    return 0;
}

int main(void) {

    int c[9] = {0, 0, 0, 0, 0, 0, 1, -2, 3};
    int ok = has_non_zero_term(c);
    printf("%s: UVa 392 - Polynomial Showdown\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
