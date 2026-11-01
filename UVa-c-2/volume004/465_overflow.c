/*
 * ==========================================================================
 * UVa 465 - Overflow
 * Title-CN: 32位元整數運算溢位檢測
 * Difficulty: UVa Star 1
 * Tags: math, big-integer, parsing
 * URL: https://onlinejudge.org/external/4/465.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if either operand or the result of 'A + B' or 'A * B' overflows 32-bit signed integer (2147483647).
 *
 * [中文] 題目說明:
 *     檢測運算式 'A + B' 或 'A * B' 的運算元或運算結果是否超出 32 位元有號整數最大值 (2^31 - 1 = 2147483647)。
 *
 * [EN] Approach:
 *     Read operands as double or BigInt. Compare each operand and result with 2147483647.0.
 * [中文] 思路:
 *     使用 double 讀取超長數值 (浮點數尾數範圍可輕鬆判斷是否大於 2147483647)，分別檢查第一數、第二數與計算結果。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INT32_MAX_VAL 2147483647.0

void solve_uva465(double a, char op, double b, int *o1, int *o2, int *or_) {
    *o1 = (a > INT32_MAX_VAL);
    *o2 = (b > INT32_MAX_VAL);
    double r = (op == '+') ? (a + b) : (a * b);
    *or_ = (r > INT32_MAX_VAL);
}

int main(void) {

    int o1, o2, or_;
    solve_uva465(3000000000.0, '+', 1.0, &o1, &o2, &or_);
    int ok = (o1 == 1 && o2 == 0 && or_ == 1);
    printf("%s: UVa 465 - Overflow\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
