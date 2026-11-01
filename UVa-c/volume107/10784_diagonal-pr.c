/*
 * ==========================================================================
 * UVa 10784 - Diagonal
 * Title-CN: 凸多邊形對角線反求最少頂點數
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/107/10784.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum number of vertices of convex polygon that has at least N diagonals: n*(n-3)/2 >= N.
 *
 * [中文] 題目說明:
 *     凸多邊形對角線數量公式為 n*(n-3)/2。給定對角線數量下限 N，求最少頂點數 n。
 *
 * [EN] Approach:
 *     Solve quadratic equation n^2 - 3n - 2N >= 0: n = ceil((3 + sqrt(9 + 8N)) / 2).
 * [中文] 思路:
 *     一元二次不等式求根公式：n = ceil((3 + sqrt(9 + 8N)) / 2.0)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

long long solve_uva10784(long long N) {
    double root = (3.0 + sqrt(9.0 + 8.0 * N)) / 2.0;
    return (long long)ceil(root);
}

int main(void) {

    int ok = (solve_uva10784(10) == 7); /* 7*(4)/2 = 14 >= 10 */
    printf("%s: UVa 10784 - Diagonal\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
