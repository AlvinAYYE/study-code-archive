/*
 * ==========================================================================
 * UVa 10450 - World Cup Noise
 * Title-CN: 世界盃吶喊不相鄰二進位序列計數
 * Difficulty: UVa Star 1
 * Tags: math, dp, fibonacci
 * URL: https://onlinejudge.org/external/104/10450.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count binary strings of length n that do not contain two consecutive 1s.
 *
 * [中文] 題目說明:
 *     計算長度為 n 且不包含連續兩個 '1' 的二進位字串個數 (斐波那契數列 F(n+2))。
 *
 * [EN] Approach:
 *     Recurrence matches Fibonacci: ways(n) = ways(n-1) + ways(n-2) with ways(1)=2, ways(2)=3.
 * [中文] 思路:
 *     滿足不連續 1 的二進位字串數對應費氏數列：f(1)=2, f(2)=3, f(n)=f(n-1)+f(n-2)。
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

long long solve_uva10450(int n) {
    long long f[55];
    f[1] = 2; f[2] = 3;
    for (int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int main(void) {

    int ok = (solve_uva10450(1) == 2 && solve_uva10450(2) == 3 && solve_uva10450(3) == 5);
    printf("%s: UVa 10450 - World Cup Noise\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
