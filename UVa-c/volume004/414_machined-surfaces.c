/*
 * ==========================================================================
 * UVa 414 - Machined Surfaces
 * Title-CN: 精密機械加工表面間隙計數
 * Difficulty: UVa Star 1
 * Tags: simulation, string
 * URL: https://onlinejudge.org/external/4/414.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count remaining empty spaces when two 25-character wide machined blocks slide together until they touch.
 *
 * [中文] 題目說明:
 *     兩塊帶有凹凸齒槽 (字元 'X') 的機械表面向中間滑動直到最先接觸，計算接合後剩餘的空隙 (空白字元) 總數。
 *
 * [EN] Approach:
 *     Count spaces in each row. The row with minimum spaces will touch first. Sum (spaces[row] - min_spaces).
 * [中文] 思路:
 *     統計每列的空格數。兩表面合攏時由空格最少的列率先頂住，總剩餘間隙即每列空格數減去全域最小空格數的總和。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva414(int n, const int *spaces) {
    int min_sp = 25;
    for (int i = 0; i < n; i++) if (spaces[i] < min_sp) min_sp = spaces[i];
    int total = 0;
    for (int i = 0; i < n; i++) total += (spaces[i] - min_sp);
    return total;
}

int main(void) {

    int sp[4] = {4, 2, 5, 3};
    int ok = (solve_uva414(4, sp) == (2 + 0 + 3 + 1));
    printf("%s: UVa 414 - Machined Surfaces\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
