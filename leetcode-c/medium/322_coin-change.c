/*
 * ==========================================================================
 * LeetCode 322. Coin Change
 * Title-CN: 硬幣找零
 * Difficulty: Medium
 * Tags: array, dynamic-programming, breadthfirst-search
 * URL: https://leetcode.com/problems/coin-change/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     You are given an integer array coins representing coins of different
 *     denominations and an integer amount representing a total amount of
 *     money.
 *     Return the fewest number of coins that you need to make up that amount.
 *     If that amount of money cannot be made up by any combination of the
 *     coins, return -1.
 *     You may assume that you have an infinite number of each kind of coin.
 *
 * [中文] 題目說明
 *     給定不同面額的硬幣陣列 coins 與總金額 amount。每種硬幣都可以使用無限次，
 *     請回傳剛好湊出 amount 所需的最少硬幣數；若任何組合都無法湊出，回傳 -1。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：coins = [1,2,5], amount = 11
 *     輸出：3
 *     說明：11 = 5 + 5 + 1，共使用 3 枚硬幣。
 *   範例 2：
 *     輸入：coins = [2], amount = 3
 *     輸出：-1
 *     說明：只使用面額 2 無法剛好湊出 3。
 *   範例 3：
 *     輸入：coins = [1], amount = 0
 *     輸出：0
 *     說明：金額 0 不需要任何硬幣。
 *
 * [中文] 限制
 *   - 1 <= coins.length <= 12。
 *   - 1 <= coins[i] <= 2^31 - 1。
 *   - 0 <= amount <= 10^4。
 *
 * LeetCode official C stub (函式簽名):
 *   int coinChange(int* coins, int coinsSize, int amount) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 定義 dp[a] 為湊出金額 a 的最少硬幣數，dp[0] = 0。
 *   2. 對每個金額 a，嘗試把每種不大於 a 的硬幣 coin 當作最後一枚。
 *   3. 若 a - coin 可湊出，候選答案就是 dp[a - coin] + 1，取所有候選的最小值。
 *   4. 初值 amount + 1 代表無法湊出；最後仍大於 amount 時回傳 -1。
 *   時間複雜度 O(amount * coinsSize)，空間複雜度 O(amount)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int coinChange(int *coins, int coinsSize, int amount) {
    int *dp = (int *)malloc((size_t)(amount + 1) * sizeof(int));
    int a, i;
    dp[0] = 0;
    for (a = 1; a <= amount; ++a) {
        /* 最多使用 amount 枚面額 1；amount + 1 可安全代表無解。 */
        int best = amount + 1;
        for (i = 0; i < coinsSize; ++i)
            if (coins[i] <= a && dp[a - coins[i]] + 1 < best)
                best = dp[a - coins[i]] + 1;
        dp[a] = best;
    }
    {
        int ans = (amount == 0) ? 0 : (dp[amount] > amount ? -1 : dp[amount]);
        free(dp);
        return ans;
    }
}
/* ---------- end submission ---------- */

static int check(int *c, int n, int amount, int expect) {
    int got = coinChange(c, n, amount);
    if (got != expect) { printf("  fail: amount %d -> %d want %d\n", amount, got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    int c1[] = {1, 2, 5};
    ok = ok && check(c1, 3, 11, 3);
    int c2[] = {2};
    ok = ok && check(c2, 1, 3, -1);
    int c3[] = {1};
    ok = ok && check(c3, 1, 0, 0);
    int c4[] = {186, 419, 83, 408};
    ok = ok && check(c4, 4, 6249, 20);
    printf("%s: 322 coin-change\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
