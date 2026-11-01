/*
 * ==========================================================================
 * UVa 13130 - Cacho
 * Title-CN: Cacho 骰子連續順子判定 (Escala)
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/131/13130.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if 5 dice values form a consecutive straight (Escala) i.e. 1-2-3-4-5 or 2-3-4-5-6.
 *
 * [中文] 題目說明:
 *     判定 5 顆骰子的點數是否形成嚴格公差為 1 的連續順子 (即 a[i] == a[i-1] + 1)。
 *
 * [EN] Approach:
 *     Check if d[i] == d[i-1] + 1 for all i in 1..4.
 * [中文] 思路:
 *     直接檢驗相鄰元素差值：若每一對相鄰骰子皆滿足 d[i] == d[i-1] + 1 則輸出 'Y'，否則輸出 'N'。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva13130(const int *d) {
    for (int i = 1; i < 5; i++) {
        if (d[i] != d[i - 1] + 1) return 0;
    }
    return 1;
}

int main(void) {

    int d1[5] = {1, 2, 3, 4, 5};
    int d2[5] = {1, 2, 4, 5, 6};
    int ok = solve_uva13130(d1) && !solve_uva13130(d2);
    printf("%s: UVa 13130 - Cacho\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
