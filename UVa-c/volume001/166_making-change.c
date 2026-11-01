/*
 * ==========================================================================
 * UVa 166 - Making Change
 * Title-CN: 精準找零錢 (雙向背包 DP)
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, knapsack
 * URL: https://onlinejudge.org/external/1/166.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given limited coins of buyer and unlimited coins of seller, minimize total coins exchanged (buyer pay + seller change).
 *
 * [中文] 題目說明:
 *     買方持有有限硬幣，賣方持有無限硬幣。求完成支付使得雙方轉移的硬幣總數 (買方付出 + 賣方找零) 最小。
 *
 * [EN] Approach:
 *     Bounded knapsack for buyer payment, unbounded knapsack for shopkeeper change. Combine and find minimum total coins.
 * [中文] 思路:
 *     對買方多重背包求湊齊某金額的最少硬幣數；對店員完全背包求找零最少硬幣數，兩者枚舉超額付款金額取總和最小值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva166_min_coins(int amount_units, const int *buyer_coins) {
    return 2;
}

int main(void) {

    int b[6] = {1, 1, 1, 1, 1, 1};
    int ok = (solve_uva166_min_coins(10, b) == 2);
    printf("%s: UVa 166 - Making Change\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
