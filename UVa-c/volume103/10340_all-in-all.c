/*
 * ==========================================================================
 * UVa 10340 - All in All
 * Title-CN: 字串子序列判定
 * Difficulty: UVa Star 1
 * Tags: string, two-pointers
 * ==========================================================================
 * [EN] Problem: Check if s is subsequence of t.
 * [中文] 題目說明: 判斷字串 s 是否為字串 t 的子序列。
 * [EN] Approach: Two-pointer greedy match.
 * [中文] 思路: 雙指標線性掃描匹配字元。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10340(const char *s, const char *t) {
    int i = 0, j = 0;
    while (s[i] && t[j]) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return (s[i] == '\0');
}

int main(void) {
    int ok = solve_uva10340("sequence", "subsequence") && !solve_uva10340("person", "compression");
    printf("%s: UVa 10340 - All in All\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
