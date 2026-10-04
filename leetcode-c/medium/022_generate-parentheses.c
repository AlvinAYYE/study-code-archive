/*
 * ==========================================================================
 * LeetCode 022. Generate Parentheses
 * Title-CN: 括號生成
 * Difficulty: Medium
 * Tags: string, dynamic-programming, backtracking
 * URL: https://leetcode.com/problems/generate-parentheses/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given n pairs of parentheses, write a function to generate all
 *     combinations of well-formed parentheses.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     生成 n 對括號所有合法組合。
 *
 * Examples:
 *   Example 1:
 *     Input: n = 3
 *     Output: ["((()))","(()())","(())()","()(())","()()()"]
 *   Example 2:
 *     Input: n = 1
 *     Output: ["()"]
 *
 * Constraints:
 *   - 1 <= n <= 8
 *
 * LeetCode official C stub (函式簽名):
 *   char** generateParenthesis(int n, int* returnSize) {
 *   }
 *
 * [EN] Approach: Backtrack: place '(' while open<n, place ')' while close<open; emit when length==2n (Catalan count).
 * [中文] 思路: 回溯：仍有左括號就能放 (，右括號數小於左括號才能放 )，長度滿 2n 即產出（卡塔蘭數）。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static void bt(char *buf, int pos, int open, int close, int n,
               char ***out, int *cnt, int *cap) {
    if (pos == 2 * n) {
        if (*cnt == *cap) {
            *cap = *cap ? *cap * 2 : 16;
            *out = (char **)realloc(*out, (size_t)*cap * sizeof(char *));
        }
        buf[pos] = '\0';
        {
            char *cp = (char *)malloc((size_t)(2 * n + 1));
            strcpy(cp, buf);
            (*out)[(*cnt)++] = cp;
        }
        return;
    }
    if (open < n)  { buf[pos] = '('; bt(buf, pos + 1, open + 1, close, n, out, cnt, cap); }
    if (close < open) { buf[pos] = ')'; bt(buf, pos + 1, open, close + 1, n, out, cnt, cap); }
}

char **generateParenthesis(int n, int *returnSize) {
    char **out = NULL; int cnt = 0, cap = 0;
    char *buf;
    buf = (char *)malloc((size_t)(2 * n + 1));
    bt(buf, 0, 0, 0, n, &out, &cnt, &cap);
    *returnSize = cnt;
    free(buf);
    return out;
}
/* ---------- end submission ---------- */

static int cmpstr(const void *a, const void *b) { return strcmp(*(char * const *)a, *(char * const *)b); }

static int run(int n, const char *const *exp, int expCnt) {
    char **out; int rs = 0; int i;
    out = generateParenthesis(n, &rs);
    if (rs != expCnt) { printf("  fail n=%d: got %d want %d\n", n, rs, expCnt); return 0; }
    qsort(out, (size_t)rs, sizeof(char *), cmpstr);
    for (i = 0; i < rs; ++i) {
        if ((int)strlen(out[i]) != 2 * n || strcmp(out[i], exp[i]) != 0) {
            printf("  fail n=%d: %s\n", n, out[i]);
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int ok = 1;
    const char *e1[] = {"()"};
    const char *e2[] = {"(())", "()()"};
    const char *e3[] = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    ok = ok && run(1, e1, 1);
    ok = ok && run(2, e2, 2);
    ok = ok && run(3, e3, 5);
    printf("%s: 022 generate-parentheses\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
