/*
 * ==========================================================================
 * UVa 10193 - All You Need Is Love
 * Title-CN: 你所需要的只是愛
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, gcd, base-conversion
 * URL: https://onlinejudge.org/external/101/10193.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two binary strings, check if their integer GCD > 1.
 *
 * [中文] 題目說明:
 *     將兩二進位字串轉為整數，判斷其最大公因數（GCD）是否大於 1。
 *
 * [EN] Approach: Binary string to integer conversion + Euclidean GCD algorithm.
 * [中文] 思路: 二進位轉十進位，再使用輾轉相除法計算 GCD。
 * ==========================================================================
 */
#include <stdio.h>

static long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

static long long bin2dec(const char *s) {
    long long res = 0;
    for (int i = 0; s[i]; i++) {
        res = (res << 1) | (s[i] - '0');
    }
    return res;
}

int solve_uva10193(const char *s1, const char *s2) {
    long long n1 = bin2dec(s1);
    long long n2 = bin2dec(s2);
    return gcd(n1, n2) > 1;
}

int main(void) {
    int ok = solve_uva10193("11011", "11000") && !solve_uva10193("11011", "11010");
    printf("%s: UVa 10193 - All You Need Is Love\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
