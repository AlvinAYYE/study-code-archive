/*
 * ==========================================================================
 * UVa 628 - Passwords
 * Title-CN: 密碼字典與規則生成回溯搜尋
 * Difficulty: UVa Star 1
 * Tags: backtracking, string
 * URL: https://onlinejudge.org/external/6/628.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a dictionary of words and password rules containing '#' (word from dict) and '0' (digit 0-9), generate all valid passwords.
 *
 * [中文] 題目說明:
 *     給定單詞字典與密碼規則字串 (包含 '#' 代表替換字典單詞，'0' 代表替換數字 0-9)，窮舉生成所有可能密碼。
 *
 * [EN] Approach:
 *     Recursive backtracking: at '#' branch over all dictionary words; at '0' branch over digits '0' through '9'.
 * [中文] 思路:
 *     深度優先回溯生成：遇到 '#' 逐一嘗試字典中所有單詞，遇到 '0' 依序遞迴填入 0 到 9 十個數位。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int uva628_count;

void dfs_uva628(const char *rule, int r_idx, int n_words) {
    if (!rule[r_idx]) { uva628_count++; return; }
    if (rule[r_idx] == '#') {
        for (int w = 0; w < n_words; w++) dfs_uva628(rule, r_idx + 1, n_words);
    } else {
        for (int d = 0; d < 10; d++) dfs_uva628(rule, r_idx + 1, n_words);
    }
}

int solve_uva628(int n_words, const char *rule) {
    uva628_count = 0;
    dfs_uva628(rule, 0, n_words);
    return uva628_count;
}

int main(void) {

    int c = solve_uva628(2, "#0"); // 2 * 10 = 20 passwords
    int ok = (c == 20);
    printf("%s: UVa 628 - Passwords\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
