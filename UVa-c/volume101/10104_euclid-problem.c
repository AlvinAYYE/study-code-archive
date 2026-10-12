/*
 * ==========================================================================
 * UVa 10104 - Euclid Problem
 * Title-CN: 歐幾里得問題
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, extended-gcd
 * URL: https://onlinejudge.org/external/101/10104.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given integers A and B, find integers X, Y and D such that A*X + B*Y = D = gcd(A, B).
 *
 * [中文] 題目說明:
 *     給定整數 A 與 B，求貝祖等式整數解 X, Y 使得 A*X + B*Y = gcd(A, B)。
 *
 * [EN] Approach: Extended Euclidean Algorithm (extgcd).
 * [中文] 思路: 擴展歐幾里得演算法 (Extended Euclidean Algorithm) 遞迴求解。
 * ==========================================================================
 */
#include <stdio.h>

long long extgcd(long long a, long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extgcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return d;
}

int main(void) {
    long long x, y;
    long long d = extgcd(4, 6, &x, &y);
    int ok = (d == 2 && 4 * x + 6 * y == 2);
    printf("%s: UVa 10104 - Euclid Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
