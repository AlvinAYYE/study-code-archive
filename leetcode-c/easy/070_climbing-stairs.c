/*
 * ==========================================================================
 * LeetCode 070. Climbing Stairs
 * Title-CN: 爬樓梯
 * Difficulty: Easy
 * Tags: math, dynamic-programming, memoization
 * URL: https://leetcode.com/problems/climbing-stairs/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     You are climbing a staircase. It takes n steps to reach the top.
 *     Each time you can either climb 1 or 2 steps. In how many distinct ways
 *     can you climb to the top?
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     一段樓梯共有 n 階，每次可以爬 1 階或 2 階。請計算恰好爬到樓梯頂端
 *     共有多少種不同走法。
 *
 * [中文] 範例
 *     1. n = 2，輸出 2；走法是 1+1 或 2。
 *     2. n = 3，輸出 3；走法是 1+1+1、1+2、2+1。
 *
 * [中文] 限制
 *     - 1 <= n <= 45
 *
 * Examples:
 *   Example 1:
 *     Input: n = 2
 *     Output: 2
 *     Explanation: There are two ways to climb to the top.
 *     1. 1 step + 1 step
 *     2. 2 steps
 *   Example 2:
 *     Input: n = 3
 *     Output: 3
 *     Explanation: There are three ways to climb to the top.
 *     1. 1 step + 1 step + 1 step
 *     2. 1 step + 2 steps
 *     3. 2 steps + 1 step
 *
 * Constraints:
 *   - 1 <= n <= 45
 *
 * LeetCode official C stub (函式簽名):
 *   int climbStairs(int n) {
 *   }
 *
 * [EN] Approach: Fibonacci: ways(n)=ways(n-1)+ways(n-2) because the last step is 1 or 2 stairs. Iterate upward. Time O(n), space O(1).
 * [中文] 直觀解題思路
 *     1. 到第 n 階的最後一步只可能從第 n-1 階走 1 階，或從第 n-2 階
 *        走 2 階，因此 ways(n) = ways(n-1) + ways(n-2)。
 *     2. 基底是 ways(1)=1、ways(2)=2，之後由小到大計算。
 *     3. 只保留前兩個結果，不必建立整張表。時間 O(n)，額外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int climbStairs(int n) {
    int a = 1, b = 1, i, c;
    /* 迴圈開始前，a=ways(0)、b=ways(1)。 */
    for (i = 2; i <= n; ++i) { c = a + b; a = b; b = c; }
    return b;
}
/* ---------- end submission ---------- */

static int check(int n, int expect) {
    int got = climbStairs(n);
    if (got != expect) { printf("  fail: climbStairs(%d)=%d want %d\n", n, got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    ok = ok && check(1, 1);
    ok = ok && check(2, 2);
    ok = ok && check(3, 3);
    ok = ok && check(10, 89);
    ok = ok && check(45, 1836311903);
    printf("%s: 070 climbing-stairs\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
