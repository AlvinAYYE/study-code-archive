/*
 * ==========================================================================
 * UVa 11150 - Cola
 * Title-CN: 喝可樂空瓶兌換 (借空瓶技巧)
 * Difficulty: UVa Star 1
 * Tags: math, greedy
 * URL: https://onlinejudge.org/external/111/11150.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Buy n colas. 3 empty bottles exchange for 1 new cola. You may borrow empty bottles as long as you return them. Maximize colas.
 *
 * [中文] 題目說明:
 *     買 n 瓶可樂，每 3 個空瓶換 1 瓶新可樂。允許向朋友借空瓶但最後必須還清，求最多能喝到幾瓶可樂。
 *
 * [EN] Approach:
 *     Formula: total = n + n / 2 = 3 * n / 2.
 * [中文] 思路:
 *     貪婪借空瓶技巧：相當於每 2 個空瓶可淨喝 1 瓶新可樂，數學公式為 n + n / 2。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11150(int n) {
    return n + n / 2;
}

int main(void) {

    int ok = (solve_uva11150(8) == 12) && (solve_uva11150(9) == 13);
    printf("%s: UVa 11150 - Cola\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
