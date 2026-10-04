/*
 * ==========================================================================
 * LeetCode 005. Longest Palindromic Substring
 * Title-CN: 最長迴文子字串
 * Difficulty: Medium
 * Tags: two-pointers, string, dynamic-programming
 * URL: https://leetcode.com/problems/longest-palindromic-substring/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given a string s, return the longest palindromic substring in s.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定字串 s，回傳其中最長的迴文子字串。
 *
 * Examples:
 *   Example 1:
 *     Input: s = "babad"
 *     Output: "bab"
 *     Explanation: "aba" is also a valid answer.
 *   Example 2:
 *     Input: s = "cbbd"
 *     Output: "bb"
 *
 * Constraints:
 *   - 1 <= s.length <= 1000
 *   - s consist of only digits and English letters.
 *
 * LeetCode official C stub (函式簽名):
 *   char* longestPalindrome(char* s) {
 *   }
 *
 * [EN] Approach: Expand around 2n-1 centers (single char / pair); keep the longest span, copy it out. Time O(n^2), space O(1).
 * [中文] 思路: 由 2n-1 個中心（單字或雙字）向兩側擴展，保留最長區間後複製回傳。時間 O(n^2)、空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static void expand(const char *s, int n, int l, int r, int *bestL, int *bestLen) {
    while (l >= 0 && r < n && s[l] == s[r]) { --l; ++r; }
    ++l;
    if (r - l > *bestLen) { *bestL = l; *bestLen = r - l; }
}

char *longestPalindrome(char *s) {
    int n = (int)strlen(s), bestL = 0, bestLen = 1, i;
    char *res;
    if (n == 0) {
        res = (char *)malloc(1);
        res[0] = '\0';
        return res;
    }
    for (i = 0; i < n; ++i) {
        expand(s, n, i, i, &bestL, &bestLen);       /* odd length */
        expand(s, n, i, i + 1, &bestL, &bestLen);   /* even length */
    }
    res = (char *)malloc((size_t)bestLen + 1);
    memcpy(res, s + bestL, (size_t)bestLen);
    res[bestLen] = '\0';
    return res;
}
/* ---------- end submission ---------- */

static int check(const char *s, const char *expect) {
    char *got = longestPalindrome((char *)s);
    int hit = (strcmp(got, expect) == 0);
    if (!hit) printf("  fail: %s -> %s (want %s)\n", s, got, expect);
    free(got);
    return hit;
}

int main(void) {
    int ok = 1;
    ok = ok && check("babad", "bab");      /* "aba" is also valid on LeetCode */
    ok = ok && check("cbbd", "bb");
    ok = ok && check("a", "a");
    ok = ok && check("bb", "bb");
    ok = ok && check("ccc", "ccc");
    printf("%s: 005 longest-palindromic-substring\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
