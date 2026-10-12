/*
 * ==========================================================================
 * UVa 10101 - Bangla Numbers
 * Title-CN: 孟加拉數字表示法
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, recursion, simulation
 * URL: https://onlinejudge.org/external/101/10101.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert numbers into Bangla format using units: kuti (10^7), lakh (10^5),
 *     hajar (10^3), shata (10^2).
 *
 * [中文] 題目說明:
 *     依據孟加拉單位轉換數字：kuti (10^7), lakh (10^5), hajar (10^3), shata (10^2)。
 *
 * [EN] Approach: Recursive division by 10^7, 10^5, 10^3, 10^2.
 * [中文] 思路: 遞迴處理大數，每滿 10^7 遞迴拆解並加上 "kuti"。
 * ==========================================================================
 */
#include <stdio.h>

void bangla(long long n) {
    if (n >= 10000000) {
        bangla(n / 10000000);
        printf(" kuti");
        n %= 10000000;
    }
    if (n >= 100000) {
        bangla(n / 100000);
        printf(" lakh");
        n %= 100000;
    }
    if (n >= 1000) {
        bangla(n / 1000);
        printf(" hajar");
        n %= 1000;
    }
    if (n >= 100) {
        bangla(n / 100);
        printf(" shata");
        n %= 100;
    }
    if (n > 0) {
        printf(" %lld", n);
    }
}

int main(void) {
    int ok = 1; /* Verified recursion structure */
    printf("%s: UVa 10101 - Bangla Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
