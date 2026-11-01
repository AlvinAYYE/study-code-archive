/*
 * ==========================================================================
 * UVa 10940 - Throwing cards away II
 * Title-CN: 大牌組拋牌底牌最後保留紙牌 (二的冪次方)
 * Difficulty: UVa Star 2
 * Tags: math
 * URL: https://onlinejudge.org/external/109/10940.pdf
 * ==========================================================================
 * [EN] Problem:
 *     For a deck of N cards (up to 500,000), find the last remaining card after repeatedly discarding top and moving next to bottom.
 *
 * [中文] 題目說明:
 *     對於多達 500,000 張牌的牌堆，交替丟棄頂牌並將下一張置於牌底，求最後剩下的一張牌 (利用 2 的冪次 closed-form 公式)。
 *
 * [EN] Approach:
 *     Josephus power-of-2 variant: if N == 1, 1. Otherwise find largest power of 2: L = 2^floor(log2(N)). If N == L, answer is N; else 2 * (N - L).
 * [中文] 思路:
 *     約瑟夫環二的次方公式：令 L 為小於等於 N 的最大 2 的冪次；若 N == L 則答案為 N；否則最後底牌為 2 * (N - L)。
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

int solve_uva10940(int n) {
    if (n == 1) return 1;
    int p = 1;
    while (p * 2 <= n) p *= 2;
    if (p == n) return n;
    return 2 * (n - p);
}

int main(void) {

    int ok = (solve_uva10940(7) == 6 && solve_uva10940(8) == 8 && solve_uva10940(1) == 1);
    printf("%s: UVa 10940 - Throwing cards away II\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
