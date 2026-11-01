/*
 * ==========================================================================
 * UVa 10340 - All in All
 * Title-CN: 子序列雙指標判定
 * Difficulty: UVa Star 1
 * Tags: two-pointers, string, greedy
 * URL: https://onlinejudge.org/external/103/10340.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if string s is a subsequence of string t.
 *
 * [中文] 題目說明:
 *     判定字串 s 是否為字串 t 的子序列 (可透過從 t 中刪除某些字元得到 s)。
 *
 * [EN] Approach:
 *     Two pointers: iterate through t, advancing pointer in s on matching character.
 * [中文] 思路:
 *     貪婪雙指標：遍歷字串 t，每當遇到與 s[i] 相等的字元即將 i 前移，若 i 抵達 s 尾端則判定為子序列。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10340(const char *s, const char *t) {
    int ps = 0, pt = 0;
    while (s[ps] && t[pt]) {
        if (s[ps] == t[pt]) ps++;
        pt++;
    }
    return s[ps] == '\0';
}

int main(void) {

    int ok = solve_uva10340("sequence", "subsequence") && !solve_uva10340("person", "compression");
    printf("%s: UVa 10340 - All in All\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
