/*
 * ==========================================================================
 * UVa 10019 - Funny Encryption Method
 * Title-CN: 有趣的加密方法
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, bit-manipulation, base-conversion
 * URL: https://onlinejudge.org/external/100/10019.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count set bits of N in decimal (b1), and count set bits when digits of N
 *     are interpreted as hexadecimal (b2).
 *
 * [中文] 題目說明:
 *     輸入整數 N，計算 N 視為十進位時轉二進位的 1 個數 b1，以及 N 視為十六進位轉二進位的 1 個數 b2。
 *
 * [EN] Approach: Brian Kernighan bit count algorithm.
 * [中文] 思路: b1 計算十進位數值之位元 1 數；b2 拆解每一十進位 digit d，計算 d 的二進位 1 數並累加。
 * ==========================================================================
 */
#include <stdio.h>

static int count_bits(int n) {
    int c = 0;
    while (n > 0) {
        n &= (n - 1);
        c++;
    }
    return c;
}

void solve_uva10019(int n, int *b1, int *b2) {
    *b1 = count_bits(n);
    int sum = 0, temp = n;
    while (temp > 0) {
        sum += count_bits(temp % 10);
        temp /= 10;
    }
    *b2 = sum;
}

int main(void) {
    int b1, b2;
    solve_uva10019(265, &b1, &b2);
    int ok = (b1 == 3 && b2 == 5);
    printf("%s: UVa 10019 - Funny Encryption Method\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
