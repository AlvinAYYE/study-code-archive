/*
 * ==========================================================================
 * UVa 11384 - Help is needed for Dexter
 * Title-CN: 德克斯特的減半消除
 * Difficulty: Easy
 * Tags: Math, Binary, Recursion
 * URL: https://onlinejudge.org/external/113/11384.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a set of numbers 1..N, subtract an integer X from any subset in one move. Find minimum moves to reduce all to 0.
 *
 * [中文] 題目說明:
 *     對集合 {1, 2, ..., N} 每次可選任意子集減去相同正整數 X，求使所有數變為 0 的最少操作次數。
 *
 * [EN] Approach:
 *     Optimal strategy repeatedly halves the range: f(N) = f(N / 2) + 1 = floor(log2(N)) + 1.
 * [中文] 思路:
 *     最優策略每次減去中間值將區間折半：f(N) = f(N/2) + 1，故最少次數恰好為 floor(log2(N)) + 1 位元長度。
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

int min_dexter_moves(int n) {
    int moves = 0;
    while (n > 0) {
        moves++;
        n /= 2;
    }
    return moves;
}

int main(void) {

    int ok = (min_dexter_moves(1) == 1) && (min_dexter_moves(2) == 2) && (min_dexter_moves(3) == 2);
    printf("%s: UVa 11384 - Help is needed for Dexter\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
