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
 *     給定輸入字串 s 與模式 p，請實作支援以下兩種特殊符號的正則匹配：
 *       '.' 可匹配任意單一字元；
 *       '*' 可讓它前面的元素出現零次或多次。
 *     匹配必須涵蓋整個輸入字串，不能只匹配其中一部分。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入：s = "aa", p = "a"
 *     輸出：false
 *     說明：模式 "a" 無法匹配完整字串 "aa"。
 *   範例 2：
 *     輸入：s = "aa", p = "a*"
 *     輸出：true
 *     說明：'*' 讓前面的 'a' 可重複多次，因此能匹配兩個 'a'。
 *   範例 3：
 *     輸入：s = "ab", p = ".*"
 *     輸出：true
 *     說明：'.' 可代表任意字元，'*' 再讓它出現零次或多次。
 *
 * [中文] 限制：
 *   - 1 <= s.length, p.length <= 20
 *   - s 僅包含小寫英文字母。
 *   - p 僅包含小寫英文字母、'.' 與 '*'。
 *   - 每個 '*' 前面都保證有一個可供它修飾的有效元素。
 *
 * LeetCode official C stub (函式簽名):
 *   bool isMatch(char* s, char* p) {
 *   }
 *
 * [EN] Approach: 2D DP dp[i][j] = s prefix i matches p prefix j; '*' branches: zero-repetition dp[i][j-2], or char match + dp[i-1][j]. Time O(mn).
 * [中文] 直觀解題思路：
 *   1. 定義 dp[i][j]：s 的前 i 個字元是否能被 p 的前 j 個字元完整匹配。
 *      空字串對空模式成立，所以 dp[0][0] = true。
 *   2. 一般字元或 '.' 必須先匹配目前的 s[i-1]，再承接 dp[i-1][j-1]。
 *   3. 若目前模式字元是 '*'，有兩種選擇：
 *      - 讓「前一元素 + *」出現零次，狀態來自 dp[i][j-2]；
 *      - 若前一元素可匹配 s[i-1]，讓它再吃掉一個字元，狀態來自
 *        dp[i-1][j]，模式仍停在 '*' 以便繼續重複。
 *   4. 空字串也可能被 "a*b*" 這類模式匹配，因此先初始化 dp[0][j]。
 *   5. 最終答案為 dp[m][n]。
 *
 * 複雜度：時間 O(mn)，空間 O(mn)。
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
    dp[0] = 1;                                   /* 空字串匹配空模式 */
    for (j = 2; j <= n; ++j)                     /* "x*" 可視為出現零次 */
        if (p[j - 1] == '*') dp[j] = dp[j - 2];
    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                char one = dp[i * w + (j - 2)];                       /* 重複零次 */
                char ch = (p[j - 2] == s[i - 1] || p[j - 2] == '.');
                /* 第二支保留 j，表示 '*' 還能繼續吃下一個相同字元。 */
                dp[i * w + j] = one || (ch && dp[(i - 1) * w + j]);
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
