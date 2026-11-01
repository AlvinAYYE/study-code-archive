/*
 * ==========================================================================
 * UVa 10931 - Parity
 * Title-CN: 二進位奇偶校驗與位元計數
 * Difficulty: UVa Star 1
 * Tags: bit-manipulation, math
 * URL: https://onlinejudge.org/external/109/10931.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Print binary representation of I and its parity (count of set bits 1).
 *
 * [中文] 題目說明:
 *     印出十進位整數 I 的二進位表示法及其奇偶校驗位 (即二進位中 1 的個數)。
 *
 * [EN] Approach:
 *     Convert integer to binary string by repeatedly dividing by 2. Count bits with value 1.
 * [中文] 思路:
 *     除以 2 取餘數構建二進位字串，統計其中字元 '1' 的總個數並格式化輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10931(int n, char *bin) {
    char temp[35];
    int len = 0, ones = 0;
    while (n) {
        int bit = n % 2;
        if (bit) ones++;
        temp[len++] = bit + '0';
        n /= 2;
    }
    for (int i = 0; i < len; i++) bin[i] = temp[len - 1 - i];
    bin[len] = '\0';
    return ones;
}

int main(void) {

    char b[35];
    int ones = solve_uva10931(21, b);
    int ok = (strcmp(b, "10101") == 0 && ones == 3);
    printf("%s: UVa 10931 - Parity\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
