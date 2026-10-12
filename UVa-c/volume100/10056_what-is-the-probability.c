/*
 * ==========================================================================
 * UVa 10056 - What is the Probability?
 * Title-CN: 獲勝機率是多少
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, probability
 * URL: https://onlinejudge.org/external/100/10056.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N players roll a die in turns with success probability p. Find the probability
 *     that player I is the first to succeed.
 *
 * [中文] 題目說明:
 *     N 個人依序擲骰子，每人成功的機率為 p。求第 I 個人成為第一個成功獲勝者的機率。
 *
 * [EN] Approach:
 *     Geometric series sum: P = p * (1-p)^(I-1) / (1 - (1-p)^N). If p == 0, output 0.0000.
 * [中文] 思路:
 *     利用無窮等比級數求和公式：P = p * q^(I-1) / (1 - q^N)，其中 q = 1 - p。若 p == 0 則為 0。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

double solve_uva10056(int n, double p, int i) {
    if (p < 1e-9) return 0.0;
    double q = 1.0 - p;
    return p * pow(q, (double)(i - 1)) / (1.0 - pow(q, (double)n));
}

int main(void) {
    double ans = solve_uva10056(2, 0.1666, 1);
    int ok = (fabs(ans - 0.5455) < 0.01);
    printf("%s: UVa 10056 - What is the Probability?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
