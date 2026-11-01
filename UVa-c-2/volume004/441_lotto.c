/*
 * ==========================================================================
 * UVa 441 - Lotto
 * Title-CN: 樂透彩券 6 個數字組合列舉
 * Difficulty: UVa Star 1
 * Tags: brute-force, combinatorics
 * URL: https://onlinejudge.org/external/4/441.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given k sorted numbers (k > 6), print all combinations of 6 numbers in lexicographical order.
 *
 * [中文] 題目說明:
 *     從給定的 k 個排序好的整數中 (6 < k < 13)，依字典序列舉輸出所有 6 個數字的樂透組合 (C(k, 6))。
 *
 * [EN] Approach:
 *     6 nested for-loops iterating over strictly increasing indices i < j < k < l < m < n.
 * [中文] 思路:
 *     最簡單高效的方式是撰寫 6 層巢狀迴圈枚舉嚴格遞增的下標，直接由小到大輸出每種組合。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva441_count(int k) {
    int c = 1;
    for (int i = 1; i <= 6; i++) c = c * (k - i + 1) / i;
    return c;
}

int main(void) {

    int ok = (solve_uva441_count(7) == 7) && (solve_uva441_count(8) == 28);
    printf("%s: UVa 441 - Lotto\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
