/*
 * ==========================================================================
 * UVa 10090 - Marbles
 * Title-CN: 彈珠
 * Difficulty: Medium
 * Tags: Math, Extended GCD, Diophantine Equation
 * URL: https://onlinejudge.org/external/100/10090.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Pack n marbles into two types of boxes (box 1 holds n1 cost c1; box 2 holds n2 cost c2) with minimum total cost.
 *
 * [中文] 題目概述:
 *     將 n 顆彈珠裝入兩種盒子中（盒子 1 容量 n1 費用 c1，盒子 2 容量 n2 費用 c2），求總費用最小的裝盒方案。
 *
 * [EN] Approach:
 *     Solve linear Diophantine equation n1*m1 + n2*m2 = n using Extended Euclidean Algorithm, and optimize cost along parameter t.
 * [中文] 解題思路:
 *     利用擴展歐幾里得演算法求解不定方程 n1*m1 + n2*m2 = n，並沿整數參數 t 尋找最小成本。
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

long long extgcd(long long a, long long b, long long *x, long long *y) {
    if (b == 0) { *x = 1; *y = 0; return a; }
    long long x1, y1;
    long long g = extgcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

bool solve_marbles(long long n, long long c1, long long n1, long long c2, long long n2, long long *m1, long long *m2) {
    long long x, y;
    long long g = extgcd(n1, n2, &x, &y);
    if (n % g != 0) return false;
    x *= (n / g); y *= (n / g);
    long long step1 = n2 / g, step2 = n1 / g;
    long long t_min = (long long)ceil(-(double)x / step1);
    long long t_max = (long long)floor((double)y / step2);
    if (t_min > t_max) return false;
    long long x1 = x + t_min * step1, y1 = y - t_min * step2;
    long long x2 = x + t_max * step1, y2 = y - t_max * step2;
    if (c1 * x1 + c2 * y1 <= c1 * x2 + c2 * y2) { *m1 = x1; *m2 = y1; }
    else { *m1 = x2; *m2 = y2; }
    return true;
}

int main(void) {

    long long m1, m2;
    bool ok = solve_marbles(43, 1, 3, 2, 4, &m1, &m2);
    ok = ok && (m1 * 3 + m2 * 4 == 43);
    printf("%s: UVa 10090 - Marbles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
