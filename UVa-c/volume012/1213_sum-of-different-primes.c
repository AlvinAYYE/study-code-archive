/*
 * ==========================================================================
 * UVa 1213 - Sum of Different Primes
 * Title-CN: 不同質數之和 (0/1背包計數DP)
 * Difficulty: Medium
 * Tags: DP, Knapsack, Prime
 * URL: https://onlinejudge.org/external/12/1213.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of ways to express integer n as the sum of k distinct prime numbers.
 *
 * [中文] 題目說明:
 *     求將正整數 n 表示為 k 個互不相同的質數之和的組合方案數。
 *
 * [EN] Approach:
 *     0/1 Knapsack DP where items are primes: dp[j][s] = number of ways to choose j primes summing to s. dp[j][s] += dp[j-1][s - prime].
 * [中文] 思路:
 *     以質數為物品的二維 0/1 背包計數 DP：dp[j][s] 表示選取 j 個質數和為 s 的方案數，倒序更新。
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

int count_prime_sums(int n, int k) {
    int primes[200], p_cnt = 0;
    bool is_p[1200];
    memset(is_p, true, sizeof(is_p));
    for (int p = 2; p <= n; p++) {
        if (is_p[p]) {
            primes[p_cnt++] = p;
            for (int i = p * 2; i <= n; i += p) is_p[i] = false;
        }
    }
    int dp[15][1200] = {0};
    dp[0][0] = 1;
    for (int i = 0; i < p_cnt; i++) {
        int p = primes[i];
        for (int j = k; j >= 1; j--) {
            for (int s = n; s >= p; s--) {
                dp[j][s] += dp[j - 1][s - p];
            }
        }
    }
    return dp[k][n];
}

int main(void) {

    int ok = (count_prime_sums(24, 3) == 2); // (2,3,19), (2,5,17) -> sum 24
    printf("%s: UVa 1213 - Sum of Different Primes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
