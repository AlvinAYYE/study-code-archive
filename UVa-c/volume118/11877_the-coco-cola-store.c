/*
 * ==========================================================================
 * UVa 11877 - The Coco-Cola Store
 * Title-CN: 可口可樂商店空瓶借還
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/118/11877.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Exchange 3 empty bottles for 1 full bottle with bottle borrowing permitted. Find max bottles drank.
 *
 * [中文] 題目說明:
 *     3 個空瓶換 1 瓶新飲料，可向老闆借空瓶但最終須還清，求最多可喝到的可樂瓶數 (等同 n / 2)。
 *
 * [EN] Approach:
 *     Integer division: n / 2.
 * [中文] 思路:
 *     每消耗 2 個空瓶即可淨喝 1 瓶可樂，可喝瓶數恆等於 n / 2。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11877(int n) {
    return n / 2;
}

int main(void) {

    int ok = (solve_uva11877(3) == 1) && (solve_uva11877(10) == 5);
    printf("%s: UVa 11877 - The Coco-Cola Store\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
