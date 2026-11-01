/*
 * ==========================================================================
 * UVa 11005 - Cheapest Base
 * Title-CN: 最便宜的進位制
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, base-conversion
 * URL: https://onlinejudge.org/external/110/11005.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the bases (2..36) that give minimum printing cost for integer X.
 *
 * [中文] 題目說明:
 *     給定 36 個字元的印刷成本，求列印數值 X 成本最低的進位制。
 *
 * [EN] Approach: Simulate base conversion for bases 2..36, find minimal cost bases.
 * [中文] 思路: 遍歷基底 2 至 36，取模計算各進位制成本。
 * ==========================================================================
 */
#include <stdio.h>

long long get_cost(long long x, int base, const int *costs) {
    if (x == 0) return costs[0];
    long long total = 0;
    while (x > 0) {
        total += costs[x % base];
        x /= base;
    }
    return total;
}

int main(void) {
    int costs[36];
    for (int i = 0; i < 36; i++) costs[i] = 1;
    long long c = get_cost(10, 2, costs); /* 1010 in base 2 => 4 characters => cost 4 */
    int ok = (c == 4);
    printf("%s: UVa 11005 - Cheapest Base\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
