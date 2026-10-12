/*
 * ==========================================================================
 * UVa 271 - Simply Syntax
 * Title-CN: 簡單語法檢驗
 * Difficulty: UVa Star 1
 * Tags: string, parsing, stack
 * ==========================================================================
 * [EN] Problem: Verify prefix sentence syntax: p..z are sentences, N<sentence> is sentence, C,D,E,I<s1><s2> are sentences.
 * [中文] 題目說明: 前序文法有效性判定：p~z 為句子，N+句子為句子，C,D,E,I+雙句子為句子。
 * [EN] Approach: Right-to-left scan maintaining sentence stack count.
 * [中文] 思路: 由右向左倒序掃描，維護目前完整句子計數。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int is_valid_syntax(const char *s) {
    int len = (int)strlen(s);
    int count = 0;
    for (int i = len - 1; i >= 0; i--) {
        char c = s[i];
        if (c >= 'p' && c <= 'z') {
            count++;
        } else if (c == 'N') {
            if (count < 1) return 0;
        } else if (c == 'C' || c == 'D' || c == 'E' || c == 'I') {
            if (count < 2) return 0;
            count--;
        } else return 0;
    }
    return (count == 1);
}

int main(void) {
    int ok = is_valid_syntax("Cpq") && !is_valid_syntax("Cp") && is_valid_syntax("p");
    printf("%s: UVa 271 - Simply Syntax\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
