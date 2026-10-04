/*
 * ==========================================================================
 * LeetCode 014. Longest Common Prefix
 * Title-CN: 最長共同前綴
 * Difficulty: Easy
 * Tags: array, string, trie
 * URL: https://leetcode.com/problems/longest-common-prefix/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Write a function to find the longest common prefix string amongst an
 *     array of strings.
 *     If there is no common prefix, return an empty string "".
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     找出字串陣列中最長的共同前綴；若沒有共同前綴回傳空字串。
 *
 * Examples:
 *   Example 1:
 *     Input: strs = ["flower","flow","flight"]
 *     Output: "fl"
 *   Example 2:
 *     Input: strs = ["dog","racecar","car"]
 *     Output: ""
 *     Explanation: There is no common prefix among the input strings.
 *
 * Constraints:
 *   - 1 <= strs.length <= 200
 *   - 0 <= strs[i].length <= 200
 *   - strs[i] consists of only lowercase English letters if it is
 *   non-empty.
 *
 * LeetCode official C stub (函式簽名):
 *   char* longestCommonPrefix(char** strs, int strsSize) {
 *   }
 *
 * [EN] Approach: Vertical scan: compare column by column with strs[0]; truncate strs[0] at the first mismatch. Time O(S), space O(1).
 * [中文] 思路: 直向掃描：逐欄比較所有字串與 strs[0] 的第 i 字元，第一次不同就截斷回傳。時間 O(S)、空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
char *longestCommonPrefix(char **strs, int strsSize) {
    int i, j;
    if (strsSize == 0) return "";
    for (i = 0; strs[0][i] != '\0'; ++i) {
        for (j = 1; j < strsSize; ++j) {
            if (strs[j][i] != strs[0][i]) { strs[0][i] = '\0'; return strs[0]; }
        }
    }
    return strs[0];
}
/* ---------- end submission ---------- */

static char *dup(const char *s) {
    char *p = (char *)malloc(strlen(s) + 1);
    strcpy(p, s);
    return p;
}

static int check(char *raw[], int n, const char *expect) {
    char *got = longestCommonPrefix(raw, n);
    if (got != raw[0] || strcmp(got, expect) != 0) {
        printf("  fail: got \"%s\", want \"%s\"\n", got, expect);
        return 0;
    }
    return 1;
}

int main(void) {
    int ok = 1;
    char *a[3] = { dup("flower"), dup("flow"), dup("flight") };
    ok = ok && check(a, 3, "fl");
    char *b[3] = { dup("dog"), dup("racecar"), dup("car") };
    ok = ok && check(b, 3, "");
    char *c[4] = { dup("abc"), dup("abc"), dup("abcd"), dup("ab") };
    ok = ok && check(c, 4, "ab");
    printf("%s: 014 longest-common-prefix\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
