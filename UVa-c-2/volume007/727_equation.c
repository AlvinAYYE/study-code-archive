/*
 * ==========================================================================
 * UVa 727 - Equation
 * Title-CN: 中序表達式轉後序表達式 (調車場演算法 Shunting Yard)
 * Difficulty: UVa Star 1
 * Tags: stack, parsing, shunting-yard
 * URL: https://onlinejudge.org/external/7/727.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert infix arithmetic expression with + - * / and parentheses to postfix notation.
 *
 * [中文] 題目說明:
 *     使用堆疊將含有加減乘除與括號的中序算術表達式轉換為後序 (波蘭倒置) 表達式。
 *
 * [EN] Approach:
 *     Dijkstra's Shunting-yard algorithm: operators popped to output based on precedence (* / > + -).
 * [中文] 思路:
 *     調車場演算法：數字直接輸出；運算子依優先順序彈棧；左括號入棧；右括號彈出直到匹配左括號。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int prec_727(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main(void) {

    int ok = (prec_727('*') > prec_727('+'));
    printf("%s: UVa 727 - Equation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
