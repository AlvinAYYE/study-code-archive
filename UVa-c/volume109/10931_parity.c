/*
 * ==========================================================================
 * UVa 10931 - Parity
 * Title-CN: 奇偶校驗
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, bit-manipulation, base-conversion
 * URL: https://onlinejudge.org/external/109/10931.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Output binary string and count of set bits for integer I.
 *
 * [中文] 題目說明:
 *     輸出整數 I 的二進位字串以及其中 1 的個數。
 *
 * [EN] Approach: Base-2 conversion stack/reversal and bit sum.
 * [中文] 思路: 依序取餘數轉換為二進位反轉輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

void solve_uva10931(long long n, char *bin_str, int *parity) {
    char buf[64];
    int len = 0, p = 0;
    while (n > 0) {
        int b = n % 2;
        buf[len++] = (char)('0' + b);
        if (b) p++;
        n /= 2;
    }
    for (int i = 0; i < len; i++) {
        bin_str[i] = buf[len - 1 - i];
    }
    bin_str[len] = '\0';
    *parity = p;
}

int main(void) {
    char bin[64];
    int p;
    solve_uva10931(21, bin, &p);
    int ok = (strcmp(bin, "10101") == 0 && p == 3);
    printf("%s: UVa 10931 - Parity\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
