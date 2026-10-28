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
 * [中文] 題目說明
 *     給定一個 32 位元有符號整數 x，將十進位數字的順序反轉後回傳。
 *     若反轉結果超出 [-2^31, 2^31 - 1]，回傳 0。題目假設環境不能使用
 *     64 位元整數來暫存結果。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：x = 123
 *     輸出：321
 *   範例 2：
 *     輸入：x = -123
 *     輸出：-321
 *   範例 3：
 *     輸入：x = 120
 *     輸出：21
 *     說明：反轉後的前導零不會保留。
 *
 * [中文] 限制
 *   - -2^31 <= x <= 2^31 - 1。
 *
 * LeetCode official C stub (函式簽名):
 *   int reverse(int x){
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 用 x % 10 取出最後一位 digit，再用 x /= 10 移除該位。
 *   2. 新結果會是 result * 10 + digit；計算前先判斷乘 10 後是否會超出 int 範圍。
 *   3. 若會溢位立即回傳 0，否則加入 digit，直到所有位數都處理完。
 *   時間複雜度 O(log |x|)，空間複雜度 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <limits.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int reverse(int x) {
    int result = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        /* 不使用 64 位元整數，先比較邊界再做 result * 10。 */
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && digit > 7)) return 0;
        if (result < INT_MIN / 10 ||
            (result == INT_MIN / 10 && digit < -8)) return 0;
        result = result * 10 + digit;
    }
    return result;
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
