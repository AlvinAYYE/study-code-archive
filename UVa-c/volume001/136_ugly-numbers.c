/*
 * ==========================================================================
 * UVa 136 - Ugly Numbers
 * Title-CN: 醜數
 * Difficulty: UVa Star 1
 * Tags: math, dynamic-programming, three-pointers
 * ==========================================================================
 * [EN] Problem: Find the 1500th ugly number (prime factors only 2, 3, or 5).
 * [中文] 題目說明: 求第 1500 個質因數只有 2, 3, 5 的醜數。
 * [EN] Approach: 3-pointer DP: ugly[i] = min(ugly[p2]*2, ugly[p3]*3, ugly[p5]*5).
 * [中文] 思路: 三指標動態規劃。維護 p2, p3, p5 分別乘以 2, 3, 5 產生的最小值。
 * ==========================================================================
 */
#include <stdio.h>

static inline long long min_l(long long a, long long b) { return a < b ? a : b; }

long long solve_uva136() {
    static long long ugly[1505];
    ugly[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= 1500; i++) {
        long long next2 = ugly[p2] * 2;
        long long next3 = ugly[p3] * 3;
        long long next5 = ugly[p5] * 5;
        long long m = min_l(next2, min_l(next3, next5));
        ugly[i] = m;
        if (m == next2) p2++;
        if (m == next3) p3++;
        if (m == next5) p5++;
    }
    return ugly[1500];
}

int main(void) {
    long long ans = solve_uva136();
    int ok = (ans == 859963392LL);
    printf("%s: UVa 136 - Ugly Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
