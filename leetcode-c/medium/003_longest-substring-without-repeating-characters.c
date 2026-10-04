/*
 * ==========================================================================
 * LeetCode 003. Longest Substring Without Repeating Characters
 * Title-CN: 無重複字元的最長子字串
 * Difficulty: Medium
 * Tags: hash-table, string, sliding-window
 * URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given a string s, find the length of the longest substring without
 *     duplicate characters.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     找出不含重複字元的最長子字串的長度。
 *
 * Examples:
 *   Example 1:
 *     Input: s = "abcabcbb"
 *     Output: 3
 *     Explanation: The answer is "abc", with the length of 3.
 *   Example 2:
 *     Input: s = "bbbbb"
 *     Output: 1
 *     Explanation: The answer is "b", with the length of 1.
 *   Example 3:
 *     Input: s = "pwwkew"
 *     Output: 3
 *     Explanation: The answer is "wke", with the length of 3.
 *     Notice that the answer must be a substring, "pwke" is a
 *     subsequence and not a substring.
 *
 * Constraints:
 *   - 0 <= s.length <= 5 * 10^4
 *   - s consists of English letters, digits, symbols and spaces.
 *
 * LeetCode official C stub (函式簽名):
 *   int lengthOfLongestSubstring(char* s) {
 *   }
 *
 * [EN] Approach: Sliding window + last-seen table: move left bound past the previous occurrence, remember max width. Time O(n), space O(min(n,Σ)).
 * [中文] 思路: 滑動視窗 + 最近出現位置表：左界跳到重複字元上次位置之後，隨時記錄最大寬度。時間 O(n)、空間 O(min(n,Σ))。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int lengthOfLongestSubstring(char *s) {
    int last[256], i, start = 0, best = 0;
    for (i = 0; i < 256; ++i) last[i] = -1;
    for (i = 0; s[i]; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (last[c] >= start) start = last[c] + 1;
        last[c] = i;
        if (i - start + 1 > best) best = i - start + 1;
    }
    return best;
}
/* ---------- end submission ---------- */

static int check(const char *s, int expect) {
    int got = lengthOfLongestSubstring((char *)s);
    if (got != expect) { printf("  fail: %s -> %d want %d\n", s, got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    ok = ok && check("abcabcbb", 3);
    ok = ok && check("bbbbb", 1);
    ok = ok && check("pwwkew", 3);
    ok = ok && check("", 0);
    ok = ok && check("dvdf", 3);
    ok = ok && check("abba", 2);
    printf("%s: 003 longest-substring-without-repeating-characters\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
