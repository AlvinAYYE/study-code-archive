/*
 * ==========================================================================
 * LeetCode 009. Palindrome Number
 * Title-CN: 迴文數
 * Difficulty: Easy
 * Tags: math
 * URL: https://leetcode.com/problems/palindrome-number/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an integer x, return true if x is a palindrome, and false
 *     otherwise.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定整數 x，若它正著讀與倒著讀相同（迴文）回傳 true；負數不可能是迴文。
 *
 * Examples:
 *   Example 1:
 *     Input: x = 121
 *     Output: true
 *     Explanation: 121 reads as 121 from left to right and from right to
 *     left.
 *   Example 2:
 *     Input: x = -121
 *     Output: false
 *     Explanation: From left to right, it reads -121. From right to
 *     left, it becomes 121-. Therefore it is not a palindrome.
 *   Example 3:
 *     Input: x = 10
 *     Output: false
 *     Explanation: Reads 01 from right to left. Therefore it is not a
 *     palindrome.
 *
 * Constraints:
 *   - -231 <= x <= 231 - 1
 *
 * LeetCode official C stub (函式簽名):
 *   bool isPalindrome(int x) {
 *   }
 *
 * [EN] Approach: Reverse only the second half of the digits and compare with the first half (drop middle digit for odd length). No overflow possible. Time O(log n), space O(1).
 * [中文] 思路: 只反轉後半段數字與前半段比較（奇數長度用 half/10 丟掉中間位），完全不會溢位。時間 O(log n)、空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdbool.h>

/* ---------- LeetCode submission / 提交區 ---------- */
bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int half = 0;
    while (x > half) { half = half * 10 + x % 10; x /= 10; }
    return x == half || x == half / 10;
}
/* ---------- end submission ---------- */

static int check(int x, int expect) {
    if (isPalindrome(x) != (expect != 0)) {
        printf("  fail: isPalindrome(%d)=%d want %d\n", x, (int)isPalindrome(x), expect);
        return 0;
    }
    return 1;
}

int main(void) {
    int ok = 1;
    ok = ok && check(121, 1);
    ok = ok && check(-121, 0);
    ok = ok && check(10, 0);
    ok = ok && check(0, 1);
    ok = ok && check(12321, 1);
    ok = ok && check(1000021, 0);
    printf("%s: 009 palindrome-number\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
