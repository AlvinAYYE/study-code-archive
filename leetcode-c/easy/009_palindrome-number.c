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
 *     給定整數 x。若 x 從左往右與從右往左讀都相同，回傳 true；
 *     否則回傳 false。
 *
 * [中文] 範例
 *     1. x = 121，輸出 true，因為正讀與反讀都是 121。
 *     2. x = -121，輸出 false；反讀會成為 121-，並不相同。
 *     3. x = 10，輸出 false；反讀是 01。
 *
 * [中文] 限制
 *     - -2^31 <= x <= 2^31 - 1
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
 * [中文] 直觀解題思路
 *     1. 負數含有負號，不可能是迴文；非零且末位為 0 的數，首位不可能
 *        也是 0，因此也可直接排除。
 *     2. 每次把 x 的末位移到 half，直到 half 大於或等於剩下的 x；此時
 *        half 正好是反轉後的後半段，不必反轉整個整數，因此不會溢位。
 *     3. 偶數位數比較 x == half；奇數位數忽略中間位，比較 x == half / 10。
 *        時間 O(log x)，額外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdbool.h>

/* ---------- LeetCode submission / 提交區 ---------- */
bool isPalindrome(int x) {
    /* 0 是迴文；其餘末位為 0 的數，反轉後會有無法保留的前導 0。 */
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int half = 0;
    /* 只反轉一半，避免完整反轉可能造成的整數溢位。 */
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
