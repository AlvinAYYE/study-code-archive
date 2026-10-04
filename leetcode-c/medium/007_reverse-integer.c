/*
 * ==========================================================================
 * LeetCode 007. Reverse Integer
 * Title-CN: 整數反轉
 * Difficulty: Medium
 * Tags: math
 * URL: https://leetcode.com/problems/reverse-integer/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given a signed 32-bit integer x, return x with its digits reversed. If
 *     reversing x causes the value to go outside the signed 32-bit integer
 *     range [-231, 231 - 1], then return 0.
 *     Assume the environment does not allow you to store 64-bit integers
 *     (signed or unsigned).
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定 32 位有符號整數 x，將其數位反轉回傳；反轉後若超出 32 位範圍則回傳
 *     0。
 *
 * Examples:
 *   Example 1:
 *     Input: x = 123
 *     Output: 321
 *   Example 2:
 *     Input: x = -123
 *     Output: -321
 *   Example 3:
 *     Input: x = 120
 *     Output: 21
 *
 * Constraints:
 *   - -231 <= x <= 231 - 1
 *
 * LeetCode official C stub (函式簽名):
 *   int reverse(int x){
 *   }
 *
 * [EN] Approach: Peel digits from the back into a wider accumulator, then one final range check. Time O(log
 * [中文] 思路: x
 * ==========================================================================
 */
#include <stdio.h>
#include <limits.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int reverse(int x) {
    long long acc = 0;
    int sign = x < 0 ? -1 : 1;
    long long v = (long long)x * sign;
    while (v > 0) { acc = acc * 10 + v % 10; v /= 10; }
    acc *= sign;
    return (acc < INT_MIN || acc > INT_MAX) ? 0 : (int)acc;
}
/* ---------- end submission ---------- */

static int check(int x, int expect) {
    int got = reverse(x);
    if (got != expect) { printf("  fail: reverse(%d)=%d want %d\n", x, got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    ok = ok && check(123, 321);
    ok = ok && check(-123, -321);
    ok = ok && check(120, 21);
    ok = ok && check(0, 0);
    ok = ok && check(1534236469, 0);
    ok = ok && check(-2147483647 - 1, 0);
    printf("%s: 007 reverse-integer\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
