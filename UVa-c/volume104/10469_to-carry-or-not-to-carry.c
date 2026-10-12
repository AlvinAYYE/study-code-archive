/*
 * ==========================================================================
 * UVa 10469 - To Carry or not to Carry
 * Title-CN: 進位還是不進位
 * Difficulty: UVa Star 1
 * Tags: bit-manipulation
 * ==========================================================================
 * [EN] Problem: Binary addition without carries.
 * [中文] 題目說明: 二進位不進位加法，直接回傳 a ^ b。
 * [EN] Approach: Bitwise XOR operation.
 * [中文] 思路: 無進位加法即為 XOR 運算。
 * ==========================================================================
 */
#include <stdio.h>

unsigned int solve_uva10469(unsigned int a, unsigned int b) {
    return a ^ b;
}

int main(void) {
    int ok = (solve_uva10469(4, 6) == 2);
    printf("%s: UVa 10469 - To Carry or not to Carry\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
