/*
 * ==========================================================================
 * UVa 10190 - Divide, But Not Quite Conquer!
 * Title-CN: 除，但無法完全征服！
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/101/10190.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Print sequence n, n/m, n/m^2...1 if perfectly divisible at every step.
 *     Otherwise print Boring!
 *
 * [中文] 題目說明:
 *     每次將 n 除以 m 直到 1，若每步皆能整除則輸出數列，否則印出 Boring!。
 *
 * [EN] Approach: Simulation with boundary checks (m <= 1, n <= 1).
 * [中文] 思路: 判斷 n % m == 0，依序除以 m 直到 n == 1。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10190(long long n, long long m, long long *seq, int *len) {
    if (m <= 1 || n < m || n <= 1) return 0;
    int idx = 0;
    while (n > 1) {
        if (n % m != 0) return 0;
        seq[idx++] = n;
        n /= m;
    }
    seq[idx++] = 1;
    *len = idx;
    return 1;
}

int main(void) {
    long long seq[64];
    int len;
    int ok1 = solve_uva10190(125, 5, seq, &len) && (len == 4 && seq[0] == 125 && seq[3] == 1);
    int ok2 = !solve_uva10190(30, 3, seq, &len);
    int ok = ok1 && ok2;
    printf("%s: UVa 10190 - Divide, But Not Quite Conquer!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
