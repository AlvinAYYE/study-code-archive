/*
 * ==========================================================================
 * UVa 353 - Pesky Palindromes
 * Title-CN: 討厭的回文 (相異回文子字串計數)
 * Difficulty: UVa Star 1
 * Tags: string, palindrome, brute-force
 * URL: https://onlinejudge.org/external/3/353.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count total number of unique palindromic substrings in a given string.
 *
 * [中文] 題目說明:
 *     計算給定字串中所有不重複的相異回文子字串總數。
 *
 * [EN] Approach:
 *     Enumerate all substrings, check palindrome, insert into a unique set or sorted string array to count distinct matches.
 * [中文] 思路:
 *     枚舉所有可能子字串，判定是否為回文，並加入去重集合或以字串排序去重計算相異回文個數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <string.h>

int is_palindrome_353(const char *s, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) return 0;
    }
    return 1;
}

int solve_uva353(const char *s) {
    int n = (int)strlen(s);
    char subs[1000][85];
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int len = 1; i + len <= n; len++) {
            if (is_palindrome_353(s + i, len)) {
                char temp[85];
                strncpy(temp, s + i, len);
                temp[len] = '\0';
                int exists = 0;
                for (int k = 0; k < count; k++) {
                    if (strcmp(subs[k], temp) == 0) { exists = 1; break; }
                }
                if (!exists) {
                    strcpy(subs[count++], temp);
                }
            }
        }
    }
    return count;
}

int main(void) {

    int ok = (solve_uva353("boy") == 3) && (solve_uva353("radar") == 5);
    printf("%s: UVa 353 - Pesky Palindromes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
