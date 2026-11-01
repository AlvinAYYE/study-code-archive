/*
 * ==========================================================================
 * UVa 11000 - Bee
 * Title-CN: 蜜蜂王國繁衍 (費氏數列 DP 規律)
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, math, fibonacci
 * URL: https://onlinejudge.org/external/110/11000.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute number of male bees and total bees in year N given reproduction biology rules.
 *
 * [中文] 題目說明:
 *     公蜂生下一公一母，母蜂只生一公，母蜂不死。求第 N 年時公蜂數量與全部蜜蜂總數 (公蜂為 F(N+2) - 1)。
 *
 * [EN] Approach:
 *     Dynamic programming: male[i] = male[i-1] + female[i-1], female[i] = male[i-1] + 1. Males sequence is Fibonacci variant.
 * [中文] 思路:
 *     動態規劃推導：第 i 年公蜂數等於前一年總蜂數，母蜂數等於前一年公蜂數 + 1。公蜂數 = F(i+2) - 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva11000(int n, long long *out_male, long long *out_total) {
    long long male = 0, female = 1;
    for (int i = 0; i < n; i++) {
        long long next_m = male + female;
        long long next_f = male + 1;
        male = next_m;
        female = next_f;
    }
    *out_male = male;
    *out_total = male + female;
}

int main(void) {

    long long m, t;
    solve_uva11000(1, &m, &t);
    int ok = (m == 1 && t == 2);
    printf("%s: UVa 11000 - Bee\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
