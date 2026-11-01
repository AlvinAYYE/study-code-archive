/*
 * ==========================================================================
 * UVa 11264 - Coin Collector
 * Title-CN: 硬幣收藏家
 * Difficulty: Medium
 * Tags: Greedy
 * URL: https://onlinejudge.org/external/112/11264.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum number of different coins that can be withdrawn from a bank given coins of strictly increasing denominations.
 *
 * [中文] 題目概述:
 *     給定嚴格遞增面額的硬幣，求最多可以同時取出多少種不同面額的硬幣。
 *
 * [EN] Approach:
 *     Greedily take coin i if the current sum plus coin i is strictly less than coin i+1. Always take the last coin.
 * [中文] 解題思路:
 *     貪心法：若當前硬幣總和加上第 i 枚硬幣的面額嚴格小於第 i+1 枚硬幣面額，則選取第 i 枚；最後一枚必定選取。
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

int max_distinct_coins(int n, const int *coins) {
    if (n <= 2) return n;
    int count = 1; // first coin
    long long sum = coins[0];
    for (int i = 1; i < n - 1; i++) {
        if (sum + coins[i] < coins[i + 1]) {
            sum += coins[i];
            count++;
        }
    }
    return count + 1; // last coin
}

int main(void) {

    int c[] = {1, 2, 4, 8, 16};
    int ok = (max_distinct_coins(5, c) == 5);
    printf("%s: UVa 11264 - Coin Collector\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
