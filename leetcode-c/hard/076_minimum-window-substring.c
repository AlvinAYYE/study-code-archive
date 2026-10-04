/*
 * ==========================================================================
 * LeetCode 076. Minimum Window Substring
 * Title-CN: 最小覆蓋子串
 * Difficulty: Hard
 * Tags: hash-table, string, sliding-window
 * URL: https://leetcode.com/problems/minimum-window-substring/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given two strings s and t of lengths m and n respectively, return the
 *     minimum window substring of s such that every character in t (including
 *     duplicates) is included in the window. If there is no such substring,
 *     return the empty string "".
 *     The testcases will be generated such that the answer is unique.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     找 s 中包含 t 全部字元（含重覆數）的最小子串。
 *
 * Examples:
 *   Example 1:
 *     Input: s = "ADOBECODEBANC", t = "ABC"
 *     Output: "BANC"
 *     Explanation: The minimum window substring "BANC" includes 'A',
 *     'B', and 'C' from string t.
 *   Example 2:
 *     Input: s = "a", t = "a"
 *     Output: "a"
 *     Explanation: The entire string s is the minimum window.
 *   Example 3:
 *     Input: s = "a", t = "aa"
 *     Output: ""
 *     Explanation: Both 'a's from t must be included in the window.
 *     Since the largest window of s only has one 'a', return empty
 *     string.
 *
 * Constraints:
 *   - m == s.length
 *   - n == t.length
 *   - 1 <= m, n <= 10^5
 *   - s and t consist of uppercase and lowercase English letters.
 *
 * LeetCode official C stub (函式簽名):
 *   char* minWindow(char* s, char* t) {
 *   }
 *
 * [EN] Approach: Sliding window over a need-count table: grow right until covered, then shrink left while still covered. Time O(
 * [中文] 思路: s
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---------- LeetCode submission / 提交區 ---------- */
char *minWindow(char *s, char *t) {
    int need[128], have[128], i, l = 0;
    int required = 0, formed = 0, best = INT_MAX, bestL = 0;
    char *res;
    for (i = 0; i < 128; ++i) { need[i] = 0; have[i] = 0; }
    for (i = 0; t[i]; ++i) { unsigned char c = (unsigned char)t[i]; if (need[c]++ == 0) required++; }
    for (i = 0; s[i]; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (need[c] && ++have[c] == need[c]) formed++;
        while (formed == required) {
            unsigned char lc;
            if (i - l + 1 < best) { best = i - l + 1; bestL = l; }
            lc = (unsigned char)s[l];
            if (need[lc] && --have[lc] < need[lc]) formed--;
            l++;
        }
    }
    if (best == INT_MAX) best = 0;
    res = (char *)malloc((size_t)best + 1);
    memcpy(res, s + bestL, (size_t)best);
    res[best] = '\0';
    return res;
}
/* ---------- end submission ---------- */

static int check(const char *s, const char *t, const char *expect) {
    char *got = minWindow((char *)s, (char *)t);
    int hit = (strcmp(got, expect) == 0);
    if (!hit) printf("  fail: (%s,%s) -> \"%s\" want \"%s\"\n", s, t, got, expect);
    free(got);
    return hit;
}

int main(void) {
    int ok = 1;
    ok = ok && check("ADOBECODEBANC", "ABC", "BANC");
    ok = ok && check("a", "a", "a");
    ok = ok && check("a", "aa", "");
    ok = ok && check("aa", "a", "a");
    ok = ok && check("ABC", "ABC", "ABC");
    printf("%s: 076 minimum-window-substring\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
