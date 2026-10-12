/*
 * ==========================================================================
 * UVa 11150 - Cola
 * Title-CN: 可樂瓶借用問題
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, greedy, simulation
 * URL: https://onlinejudge.org/external/111/11150.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find max bottles drunk if 3 empties exchange for 1 full, with borrowing allowed.
 *
 * [中文] 題目說明:
 *     3 個空瓶換 1 瓶可樂，可借空瓶但須歸還，求最多能喝幾瓶。
 *
 * [EN] Approach: Formula n + n / 2.
 * [中文] 思路: 借空瓶等價於每消耗 2 瓶實質得 1 瓶，公式解為 n + n / 2。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva11150(int n) {
    return n + n / 2;
}

int main(void) {
    int ok = (solve_uva11150(8) == 12) && (solve_uva11150(9) == 13);
    printf("%s: UVa 11150 - Cola\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
