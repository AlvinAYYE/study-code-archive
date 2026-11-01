/*
 * ==========================================================================
 * UVa 10056 - What is the Probability?
 * Title-CN: 誰會先擲出成功？(幾何分佈無窮等比級數)
 * Difficulty: UVa Star 1
 * Tags: math, probability
 * URL: https://onlinejudge.org/external/100/10056.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N players take turns rolling a die with success probability p. Find probability that player I is the first to succeed.
 *
 * [中文] 題目說明:
 *     N 位玩家依序輪流擲骰子，每人成功機率為 p。求第 I 位玩家是全場第一個擲出成功的機率。
 *
 * [EN] Approach:
 *     Geometric series: P = (1-p)^{I-1} * p / (1 - (1-p)^N). Handle p = 0 edge case.
 * [中文] 思路:
 *     無窮等比級數求和公式：P = p * q^(I-1) / (1 - q^N)，其中 q = 1 - p。若 p 接近 0 則機率為 0.0000。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

double solve_uva10056(int n, double p, int i) {
    if (fabs(p) < 1e-9) return 0.0;
    double q = 1.0 - p;
    return (pow(q, i - 1) * p) / (1.0 - pow(q, n));
}

int main(void) {

    double res = solve_uva10056(2, 0.1666, 1);
    int ok = (res > 0.5 && res < 0.6);
    printf("%s: UVa 10056 - What is the Probability?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
