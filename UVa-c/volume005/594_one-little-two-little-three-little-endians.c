/*
 * ==========================================================================
 * UVa 594 - One Little, Two Little, Three Little Endians
 * Title-CN: 大端序與小端序 32位元整數轉換
 * Difficulty: UVa Star 1
 * Tags: bit-manipulation
 * URL: https://onlinejudge.org/external/5/594.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert 32-bit signed integer between little-endian and big-endian byte orders.
 *
 * [中文] 題目說明:
 *     將 32 位元有號整數的 4 個 Byte 順序反轉 (在小端序與大端序之間相互轉換)。
 *
 * [EN] Approach:
 *     Bitwise masking and shifting: ((x & 0xFF) << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | ((x >> 24) & 0xFF).
 * [中文] 思路:
 *     位元運算遮罩與移位：將 4 個位元組分別位移 24、8、-8、-24 位元進行 OR 組合。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva594(int x) {
    unsigned int u = (unsigned int)x;
    unsigned int res = ((u & 0x000000FF) << 24) |
                       ((u & 0x0000FF00) << 8)  |
                       ((u & 0x00FF0000) >> 8)  |
                       ((u & 0xFF000000) >> 24);
    return (int)res;
}

int main(void) {

    int ok = (solve_uva594(1) == 16777216) && (solve_uva594(16777216) == 1);
    printf("%s: UVa 594 - One Little, Two Little, Three Little Endians\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
