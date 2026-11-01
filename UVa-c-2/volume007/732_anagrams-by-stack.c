/*
 * ==========================================================================
 * UVa 732 - Anagrams by Stack
 * Title-CN: 堆疊重組字謎
 * Difficulty: Medium
 * Tags: Backtracking, Stack
 * URL: https://onlinejudge.org/external/7/732.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all sequences of push ('i') and pop ('o') operations that transform source word into target word via stack.
 *
 * [中文] 題目說明:
 *     求所有透過堆疊 push ('i') 與 pop ('o') 操作將來源單字轉換為目標單字的操作序列（按字典序輸出）。
 *
 * [EN] Approach:
 *     DFS backtrack tracking input pointer, stack content, matched output length, and operation history. Prioritize 'i' over 'o' for lexicographical order.
 * [中文] 思路:
 *     深度優先回溯搜尋：維護輸入字元指標、當前堆疊與已匹配字元數，優先嘗試 'i' 再嘗試 'o' 生成字典序序列。
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

int dfs_stack_anagram(const char *src, const char *tgt, int s_idx, int t_idx, char *st, int top) {
    if (tgt[t_idx] == '\0') return (top == 0);
    int valid = 0;
    // Try push 'i'
    if (src[s_idx] != '\0') {
        st[top] = src[s_idx];
        valid += dfs_stack_anagram(src, tgt, s_idx + 1, t_idx, st, top + 1);
    }
    // Try pop 'o'
    if (top > 0 && st[top - 1] == tgt[t_idx]) {
        valid += dfs_stack_anagram(src, tgt, s_idx, t_idx + 1, st, top - 1);
    }
    return valid;
}

int main(void) {

    char st[10];
    int count = dfs_stack_anagram("madam", "adamm", 0, 0, st, 0);
    int ok = (count == 2);
    printf("%s: UVa 732 - Anagrams by Stack\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
