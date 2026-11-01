/*
 * ==========================================================================
 * UVa 10229 - Modular Fibonacci
 * Title-CN: 模 2 的 M 次方大數費氏數列矩陣快速冪
 * Difficulty: UVa Star 2
 * Tags: math, matrix-exponentiation
 * URL: https://onlinejudge.org/external/102/10229.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute the n-th Fibonacci number modulo 2^m for n up to 2^31.
 *
 * [中文] 題目說明:
 *     計算第 n 個斐波那契數對 2^m 取模的餘數 (n 高達 2^31，以 2x2 矩陣快速冪求值)。
 *
 * [EN] Approach:
 *     2x2 Matrix Exponentiation: [[1,1],[1,0]]^n modulo 2^m.
 * [中文] 思路:
 *     以 2x2 矩陣快速冪加速費氏數列運算，乘法過程隨時對 2^m 取模，時間複雜度 O(log n)。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

void mat_mul2(long long A[2][2], long long B[2][2], long long C[2][2], long long mod) {
    long long T[2][2];
    T[0][0] = (A[0][0]*B[0][0] + A[0][1]*B[1][0]) % mod;
    T[0][1] = (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % mod;
    T[1][0] = (A[1][0]*B[0][0] + A[1][1]*B[1][0]) % mod;
    T[1][1] = (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % mod;
    memcpy(C, T, sizeof(T));
}

long long solve_uva10229(long long n, int m) {
    if (m == 0 || n == 0) return 0;
    long long mod = 1LL << m;
    long long res[2][2] = {{1, 0}, {0, 1}};
    long long base[2][2] = {{1, 1}, {1, 0}};
    while (n > 0) {
        if (n & 1) mat_mul2(res, base, res, mod);
        mat_mul2(base, base, base, mod);
        n >>= 1;
    }
    return res[0][1];
}

int main(void) {

    int ok = (solve_uva10229(11, 7) == 89 % 128 && solve_uva10229(0, 5) == 0);
    printf("%s: UVa 10229 - Modular Fibonacci\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
