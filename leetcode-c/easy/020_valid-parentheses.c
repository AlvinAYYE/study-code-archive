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
 *     判斷只含 (){}[]
 *     的字串是否有效：同種括號閉合、順序正確、每個右括號都有對應左括號。
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
 * [中文] 思路: 堆疊：左括號入疊；右括號時弹出棧頂檢查配對；結束時疊空才算有效。時間 O(n)、空間 O(n)。
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
            default:  st[t++] = s[i]; continue;
        }
        if (t == 0 || st[--t] != match) { free(st); return false; }
    }
    free(st);
    return t == 0;
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
