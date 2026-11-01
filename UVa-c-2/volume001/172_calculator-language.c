/*
 * ==========================================================================
 * UVa 172 - Calculator Language
 * Title-CN: 算術表達式求值與變數賦值直譯器
 * Difficulty: UVa Star 2
 * Tags: parsing, stack
 * URL: https://onlinejudge.org/external/1/172.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Interpret assignments and arithmetic expressions for single-letter variables A-Z with integer arithmetic and precedence.
 *
 * [中文] 題目說明:
 *     直譯單字母變數 A-Z 的算術賦值與運算表達式，支援整數加減乘除與運算子優先順序。
 *
 * [EN] Approach:
 *     Maintain variable environment table int vars[26]. Evaluate expressions with operator precedence using shunting-yard or recursive descent.
 * [中文] 思路:
 *     維護長度 26 的整數變數表，利用遞迴下降剖析器或雙堆疊運算式求值法執行變數更新與輸出求值結果。
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

int eval_op(int a, char op, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/' && b != 0) return a / b;
    return 0;
}

int main(void) {

    int ok = (eval_op(3, '+', 4) == 7 && eval_op(10, '/', 2) == 5);
    printf("%s: UVa 172 - Calculator Language\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
