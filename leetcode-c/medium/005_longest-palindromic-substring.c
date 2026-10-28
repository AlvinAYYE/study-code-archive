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
 * [中文] 題目說明
 *     給定字串 s，回傳其中最長的迴文子字串。迴文是由左向右與由右向左讀
 *     都相同的字串；子字串必須由原字串中的連續字元組成。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：s = "babad"
 *     輸出："bab"
 *     說明："aba" 也是正確答案。
 *   範例 2：
 *     輸入：s = "cbbd"
 *     輸出："bb"
 *
 * [中文] 限制
 *   - 1 <= s.length <= 1000。
 *   - s 只包含數字與英文字母。
 *
 * LeetCode official C stub (函式簽名):
 *   char* longestPalindrome(char* s) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 每個迴文都有中心；奇數長度以一個字元為中心，偶數長度以兩字元間隙為中心。
 *   2. 對每個位置各做一次奇數與偶數擴展，只要左右字元相同就繼續往外走。
 *   3. 擴展停止後比較區間長度，記下最長區間，最後複製成新字串回傳。
 *   共檢查 2n - 1 個中心，最壞時間複雜度 O(n^2)，除回傳字串外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static void expand(const char *s, int n, int l, int r, int *bestL, int *bestLen) {
    /* l == r 處理奇數長度；r == l + 1 處理偶數長度。 */
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
