/*
 * ==========================================================================
 * LeetCode 010. Regular Expression Matching
 * Title-CN: 正則表達式匹配
 * Difficulty: Hard
 * Tags: string, dynamic-programming, recursion
 * URL: https://leetcode.com/problems/regular-expression-matching/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an input string s and a pattern p, implement regular expression
 *     matching with support for '.' and '*' where:
 *     The matching should cover the entire input string (not partial).
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     支援 '.' (任一字元) 與 '*' (前字符零次或多次)
 *     的匹配，整個字串必須完整符合。
 *
 * Examples:
 *   Example 1:
 *     Input: s = "aa", p = "a"
 *     Output: false
 *     Explanation: "a" does not match the entire string "aa".
 *   Example 2:
 *     Input: s = "aa", p = "a*"
 *     Output: true
 *     Explanation: '*' means zero or more of the preceding element, 'a'.
 *     Therefore, by repeating 'a' once, it becomes "aa".
 *   Example 3:
 *     Input: s = "ab", p = ".*"
 *     Output: true
 *     Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 * Constraints:
 *   - 1 <= s.length <= 20
 *   - 1 <= p.length <= 20
 *   - s contains only lowercase English letters.
 *   - p contains only lowercase English letters, '.', and '*'.
 *   - It is guaranteed for each appearance of the character '*', there
 *   will be a previous valid character to match.
 *
 * LeetCode official C stub (函式簽名):
 *   bool isMatch(char* s, char* p) {
 *   }
 *
 * [EN] Approach: 2D DP dp[i][j] = s prefix i matches p prefix j; '*' branches: zero-repetition dp[i][j-2], or char match + dp[i-1][j]. Time O(mn).
 * [中文] 思路: 二維 DP：dp[i][j] 代表 s 前 i 字元可否被 p 前 j 字元匹配；遇到 * 分「重複 0 次」與「至少 1 次」兩支。時間 O(mn)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* ---------- LeetCode submission / 提交區 ---------- */
bool isMatch(char *s, char *p) {
    int m = (int)strlen(s), n = (int)strlen(p), i, j, w = n + 1;
    char *dp = (char *)calloc((size_t)(m + 1) * (size_t)w, 1);
    bool ans;
    dp[0] = 1;                                   /* "" matches "" */
    for (j = 2; j <= n; ++j)                     /* "" vs "x*" etc. */
        if (p[j - 1] == '*') dp[j] = dp[j - 2];
    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                char one = dp[i * w + (j - 2)];                       /* zero reps */
                char ch = (p[j - 2] == s[i - 1] || p[j - 2] == '.');
                dp[i * w + j] = one || (ch && dp[(i - 1) * w + j]);   /* one or more */
            } else {
                dp[i * w + j] = (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                                && dp[(i - 1) * w + (j - 1)];
            }
        }
    }
    ans = dp[m * w + n] != 0;
    free(dp);
    return ans;
}
/* ---------- end submission ---------- */

static int check(const char *s, const char *p, int expect) {
    if (isMatch((char *)s, (char *)p) != (expect != 0)) {
        printf("  fail: (%s, %s) want %d\n", s, p, expect);
        return 0;
    }
    return 1;
}

int main(void) {
    int ok = 1;
    ok = ok && check("aa", "a", 0);
    ok = ok && check("aa", "a*", 1);
    ok = ok && check("ab", ".", 0);
    ok = ok && check("ab", ".*", 1);
    ok = ok && check("aab", "c*a*b", 1);
    ok = ok && check("mississippi", "mis*is*p*.", 0);
    ok = ok && check("", "a*", 1);
    ok = ok && check("a", "ab*", 1);
    printf("%s: 010 regular-expression-matching\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
