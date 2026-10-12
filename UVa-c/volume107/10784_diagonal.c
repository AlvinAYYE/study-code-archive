/*
 * ==========================================================================
 * UVa 10784 - Diagonal
 * Title-CN: 凸多邊形對角線數求頂點數
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Find minimal n such that n*(n - 3)/2 >= N.
 * [中文] 題目說明: 已知對角線數 >= N，求凸多邊形最小頂點數。
 * [EN] Approach: Quadratic formula solve n^2 - 3n - 2N >= 0.
 * [中文] 思路: 解一元二次不等式：ceil((3 + sqrt(9 + 8N)) / 2)。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

long long solve_uva10784(long long n) {
    double root = ceil((3.0 + sqrt(9.0 + 8.0 * n)) / 2.0);
    return (long long)root;
}

int main(void) {
    int ok = (solve_uva10784(10) == 7) && (solve_uva10784(100) == 16);
    printf("%s: UVa 10784 - Diagonal\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
