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
 *     給定一組字串 strs，找出所有字串共同擁有的最長開頭部分。
 *     若第一個字元就不相同，回傳空字串 ""。
 *
 * [中文] 範例
 *     1. strs = ["flower","flow","flight"]，輸出 "fl"。
 *     2. strs = ["dog","racecar","car"]，輸出 ""，因為三個字串
 *        沒有共同前綴。
 *
 * [中文] 限制
 *     - 1 <= strs.length <= 200
 *     - 0 <= strs[i].length <= 200
 *     - 非空字串只包含小寫英文字母。
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
 * [中文] 直觀解題思路
 *     1. 把第一個字串當成候選答案，從索引 0 開始逐欄比較。
 *     2. 對每個索引 i，確認其餘每個字串的 strs[j][i] 都與第一個字串相同。
 *        若某字串已結束，讀到的 '\0' 也會自然形成不相同。
 *     3. 第一次不相同的位置就是共同前綴終點，把第一個字串該處改成 '\0'
 *        後回傳；若全部相同，第一個字串本身就是答案。
 *     4. 設所有被比較的字元總數為 S，時間 O(S)，額外空間 O(1)。
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
            /* 字元不同或 strs[j] 已結束時，共同前綴就在 i 之前。 */
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
