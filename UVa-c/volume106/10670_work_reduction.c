/*
 * ==========================================================================
 * UVa 10670 - Work Reduction
 * Title-CN: 工作量化簡之最小外包成本
 * Difficulty: Medium
 * Tags: Greedy, Math
 * URL: https://onlinejudge.org/external/106/10670.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum cost to reduce work units from N to M given agency cost rates for unit reduction and halving.
 *
 * [中文] 題目描述:
 *     將工作量由 N 縮減為 M，各外包公司提供兩種收費：每減少 1 單位費用 A，或減半費用 B，求各家公司的最小成本。
 *
 * [EN] Approach:
 *     Greedy choice: repeatedly compare cost of halving (B) with cost of doing the same reduction via unit steps (rem * A).
 *
 * [中文] 解題思維:
 *     貪婪選擇：工作量大於 M 時，每次考慮減半能否節省成本，若減半成本 B 小於單步遞減成本 (N - N/2)*A 則減半，否則全用單步。
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

int min_cost_agency(int N, int M, int A, int B) {
    int total_cost = 0;
    while (N > M) {
        int half = N / 2;
        if (half >= M) {
            int reduce_by = N - half;
            if (B < reduce_by * A) total_cost += B;
            else total_cost += reduce_by * A;
            N = half;
        } else {
            total_cost += (N - M) * A;
            N = M;
        }
    }
    return total_cost;
}

int main(void) {
    // N=100, M=5: A=1, B=10
    // 100->50 cost 10, 50->25 cost 10, 25->12 cost 10, 12->6 cost 6 (A*6), 6->5 cost 1 (A*1) -> total = 37
    int res = min_cost_agency(100, 5, 1, 10);
    int ok = (res == 37);
    printf("%s: UVa 10670 - Work Reduction\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
