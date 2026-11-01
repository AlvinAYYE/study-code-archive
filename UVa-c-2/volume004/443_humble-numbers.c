/*
 * ==========================================================================
 * UVa 443 - Humble Numbers
 * Title-CN: 卑微數 (只含 2, 3, 5, 7 質因數之數)
 * Difficulty: UVa Star 1
 * Tags: math, dynamic-programming, priority-queue
 * URL: https://onlinejudge.org/external/4/443.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find n-th humble number (numbers whose only prime factors are 2, 3, 5, 7) for n <= 5842.
 *
 * [中文] 題目說明:
 *     求第 n 個卑微數 (質因數僅含 2, 3, 5, 7 的整數，第 1 個為 1，n <= 5842)。
 *
 * [EN] Approach:
 *     Four-pointer dynamic programming: next humble number is min(2*h[p2], 3*h[p3], 5*h[p5], 7*h[p7]). Advance matching pointers.
 * [中文] 思路:
 *     四指標動態規劃：維護 p2, p3, p5, p7 指標，下一個卑微數取四者乘積最小值，並將達成最小值的指標前移去重。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int humble[5845];
static int humble_ready = 0;

void init_humble(void) {
    if (humble_ready) return;
    humble[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1, p7 = 1;
    for (int i = 2; i <= 5842; i++) {
        int v2 = humble[p2] * 2, v3 = humble[p3] * 3, v5 = humble[p5] * 5, v7 = humble[p7] * 7;
        int min_v = v2;
        if (v3 < min_v) min_v = v3;
        if (v5 < min_v) min_v = v5;
        if (v7 < min_v) min_v = v7;
        humble[i] = min_v;
        if (min_v == v2) p2++;
        if (min_v == v3) p3++;
        if (min_v == v5) p5++;
        if (min_v == v7) p7++;
    }
    humble_ready = 1;
}

int solve_uva443(int n) {
    init_humble();
    return humble[n];
}

int main(void) {

    int ok = (solve_uva443(1) == 1) && (solve_uva443(11) == 12) && (solve_uva443(100) == 450);
    printf("%s: UVa 443 - Humble Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
