/*
 * ==========================================================================
 * UVa 377 - Cowmulting
 * Title-CN: 牛之四進制運算器
 * Difficulty: Medium
 * Tags: Simulation, Base Conversion, Math
 * URL: https://onlinejudge.org/external/3/377.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate a base-4 arithmetic processor with symbols 'V'=0, 'U'=1, 'C'=2, 'D'=3 and operations A, S, R, N.
 *
 * [中文] 題目描述:
 *     模擬以四進制字元 'V'=0, 'U'=1, 'C'=2, 'D'=3 表示的 8 位數運算器，支援加法、左移、右移與空操作。
 *
 * [EN] Approach:
 *     Convert cow string to integer, perform simulated operations (Add, Shift left with 'V', Shift right, Nop), compare with expected result.
 *
 * [中文] 解題思維:
 *     將符號轉換為 4 進制整數，按指令執行加法、左移填 0、右移等操作，並判斷最終暫存器數值是否與期望相符。
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

static int cow_to_val(char c) {
    if (c == 'V') return 0;
    if (c == 'U') return 1;
    if (c == 'C') return 2;
    if (c == 'D') return 3;
    return 0;
}

static long long cow_str_to_ll(const char *s) {
    long long v = 0;
    for (int i = 0; s[i]; i++) v = v * 4 + cow_to_val(s[i]);
    return v;
}

int exec_cowmulting(const char *num1_str, const char *num2_str, const char ops[3], const char *res_str) {
    long long r1 = cow_str_to_ll(num1_str);
    long long r2 = cow_str_to_ll(num2_str);
    long long expected = cow_str_to_ll(res_str);

    for (int i = 0; i < 3; i++) {
        char op = ops[i];
        if (op == 'A') r2 = r2 + r1;
        else if (op == 'R') r2 = r2 / 4;
        else if (op == 'S') r2 = r2 * 4;
    }
    return (r2 == expected);
}

int main(void) {

    // 'V'=0, 'U'=1, 'C'=2, 'D'=3
    // "U" (1), "U" (1), op 'A' (1+1=2='C'), 'N', 'N' -> result "C"
    int ok = exec_cowmulting("U", "U", "ANN", "C");
    printf("%s: UVa 377 - Cowmulting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
