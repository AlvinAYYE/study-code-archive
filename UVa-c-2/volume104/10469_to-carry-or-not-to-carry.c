/*
 * ==========================================================================
 * UVa 10469 - To Carry or not to Carry
 * Title-CN: 無進位加法器 (位元互斥或 XOR)
 * Difficulty: UVa Star 1
 * Tags: bit-manipulation, math
 * URL: https://onlinejudge.org/external/104/10469.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Add two 32-bit unsigned integers without carrying to the next bit (bitwise XOR).
 *
 * [中文] 題目說明:
 *     計算二進位無進位加法運算結果 (即位元運算 XOR: a ^ b)。
 *
 * [EN] Approach:
 *     Addition without carry in binary arithmetic is mathematically equivalent to bitwise XOR: a ^ b.
 * [中文] 思路:
 *     二進位無進位加法完全等價於位元互斥或 (XOR) 運算：直接回傳 a ^ b。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned int solve_uva10469(unsigned int a, unsigned int b) {
    return a ^ b;
}

int main(void) {

    int ok = (solve_uva10469(4, 6) == 2) && (solve_uva10469(6, 9) == 15);
    printf("%s: UVa 10469 - To Carry or not to Carry\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
