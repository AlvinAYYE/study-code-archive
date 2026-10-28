/*
 * ==========================================================================
 * LeetCode 020. Valid Parentheses
 * Title-CN: 有效的括號
 * Difficulty: Easy
 * Tags: string, stack
 * URL: https://leetcode.com/problems/valid-parentheses/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given a string s containing just the characters '(', ')', '{', '}', '['
 *     and ']', determine if the input string is valid.
 *     An input string is valid if:
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定只包含小括號 ()、中括號 []、大括號 {} 的字串 s，判斷括號是否
 *     有效。有效字串必須同種類配對、依正確順序閉合，而且每個右括號都要
 *     對應到先前尚未閉合的左括號。
 *
 * [中文] 範例
 *     1. s = "()"，輸出 true。
 *     2. s = "()[]{}"，輸出 true。
 *     3. s = "(]"，輸出 false，因為括號種類不相符。
 *     4. s = "([])"，輸出 true。
 *     5. s = "([)]"，輸出 false，因為閉合順序錯誤。
 *
 * [中文] 限制
 *     - 1 <= s.length <= 10^4
 *     - s 只包含 ()[]{}。
 *
 * Examples:
 *   Example 1:
 *     Input: s = "()"
 *     Output: true
 *   Example 2:
 *     Input: s = "()[]{}"
 *     Output: true
 *   Example 3:
 *     Input: s = "(]"
 *     Output: false
 *   Example 4:
 *     Input: s = "([])"
 *     Output: true
 *   Example 5:
 *     Input: s = "([)]"
 *     Output: false
 *
 * Constraints:
 *   - 1 <= s.length <= 10^4
 *   - s consists of parentheses only '()[]{}'.
 *
 * LeetCode official C stub (函式簽名):
 *   bool isValid(char* s) {
 *   }
 *
 * [EN] Approach: Stack: push openings; on a closing bracket pop and require the matching pair; valid iff stack empty at end. Time O(n), space O(n).
 * [中文] 直觀解題思路
 *     1. 由左往右掃描；遇到左括號就壓入堆疊，表示它尚未閉合。
 *     2. 遇到右括號時，它只能與堆疊頂端（最近出現）的左括號配對。
 *        若堆疊為空或種類不符，立即回傳 false。
 *     3. 全部掃描後，堆疊必須為空；若仍有左括號便表示尚未閉合。
 *        時間 O(n)，額外空間 O(n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* ---------- LeetCode submission / 提交區 ---------- */
bool isValid(char *s) {
    size_t n = strlen(s), t = 0, i;
    char *st = (char *)malloc(n + 1);
    for (i = 0; i < n; ++i) {
        char match = 0;
        switch (s[i]) {
            case ')': match = '('; break;
            case ']': match = '['; break;
            case '}': match = '{'; break;
            default:  st[t++] = s[i]; continue;  /* 左括號入疊 */
        }
        /* 右括號必須與最近一個尚未閉合的左括號相符。 */
        if (t == 0 || st[--t] != match) { free(st); return false; }
    }
    free(st);
    return t == 0;  /* 堆疊非空代表仍有左括號未閉合。 */
}
/* ---------- end submission ---------- */

static int check(const char *s, int expect) {
    if (isValid((char *)s) != (expect != 0)) {
        printf("  fail: isValid(%s)=%d want %d\n", s, (int)isValid((char *)s), expect);
        return 0;
    }
    return 1;
}

int main(void) {
    int ok = 1;
    ok = ok && check("()", 1);
    ok = ok && check("()[]{}", 1);
    ok = ok && check("(]", 0);
    ok = ok && check("[)", 0);
    ok = ok && check("{[]}", 1);
    ok = ok && check("(", 0);
    printf("%s: 020 valid-parentheses\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
