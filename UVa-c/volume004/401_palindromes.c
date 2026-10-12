/*
 * ==========================================================================
 * UVa 401 - Palindromes
 * Title-CN: 回文與鏡像字串判定
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * ==========================================================================
 * [EN] Problem: Determine if string is a regular palindrome, a mirrored string, a mirrored palindrome, or not.
 * [中文] 題目說明: 判定字串是否為普通回文、鏡像字串、鏡像回文或都不是。
 * [EN] Approach: Check s[i] == s[len-1-i] and s[i] == rev_char(s[len-1-i]).
 * [中文] 思路: 建立字元鏡像對應表，分別比對回文與鏡像條件。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static const char rev_table[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

static char get_rev(char c) {
    if (c >= 'A' && c <= 'Z') return rev_table[c - 'A'];
    if (c >= '1' && c <= '9') return rev_table[c - '1' + 26];
    return ' ';
}

int solve_uva401(const char *s, int *is_pal, int *is_mir) {
    int len = (int)strlen(s);
    *is_pal = 1;
    *is_mir = 1;
    for (int i = 0; i <= len / 2; i++) {
        if (s[i] != s[len - 1 - i]) *is_pal = 0;
        if (s[i] != get_rev(s[len - 1 - i])) *is_mir = 0;
    }
    return 1;
}

int main(void) {
    int p, m;
    solve_uva401("ATOYOTA", &p, &m);
    int ok = p && m;
    printf("%s: UVa 401 - Palindromes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
