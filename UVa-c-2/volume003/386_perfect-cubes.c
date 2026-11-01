/*
 * ==========================================================================
 * UVa 386 - Perfect Cubes
 * Title-CN: 完全立方等式 (a^3 = b^3 + c^3 + d^3)
 * Difficulty: UVa Star 1
 * Tags: math, brute-force
 * URL: https://onlinejudge.org/external/3/386.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all integer quadruples 2 <= b <= c <= d <= a <= 200 such that a^3 = b^3 + c^3 + d^3.
 *
 * [中文] 題目說明:
 *     求出所有滿足 a^3 = b^3 + c^3 + d^3 且 2 <= b <= c <= d <= a <= 200 的整數四元組。
 *
 * [EN] Approach:
 *     Precompute cubes 1..200. Four nested loops with pruning b^3 + c^3 + d^3 <= a^3.
 * [中文] 思路:
 *     預先計算 1..200 的立方值。四重迴圈枚舉 a, b, c, d，利用單調性進行提早跳出剪枝。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva386_count(int max_a) {
    int cnt = 0;
    for (int a = 6; a <= max_a; a++) {
        long long a3 = (long long)a * a * a;
        for (int b = 2; b < a; b++) {
            long long b3 = (long long)b * b * b;
            for (int c = b; c < a; c++) {
                long long c3 = (long long)c * c * c;
                if (b3 + c3 >= a3) break;
                for (int d = c; d < a; d++) {
                    long long sum = b3 + c3 + (long long)d * d * d;
                    if (sum == a3) cnt++;
                    else if (sum > a3) break;
                }
            }
        }
    }
    return cnt;
}

int main(void) {

    int ok = (solve_uva386_count(10) >= 1);
    printf("%s: UVa 386 - Perfect Cubes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
