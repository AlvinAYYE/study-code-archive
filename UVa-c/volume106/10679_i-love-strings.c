/*
 * ==========================================================================
 * UVa 10679 - I Love Strings!!
 * Title-CN: 字串多模式匹配 (KMP / 子字串查詢)
 * Difficulty: UVa Star 2
 * Tags: string, kmp, aho-corasick
 * URL: https://onlinejudge.org/external/106/10679.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a large text and multiple queries, determine if each query string appears as a substring.
 *
 * [中文] 題目說明:
 *     給定主字串 S 與多筆查詢字串 Q，判定各查詢字串是否在主字串中作為子字串出現。
 *
 * [EN] Approach:
 *     KMP search for each query string in text S or Aho-Corasick multi-pattern search.
 * [中文] 思路:
 *     以 KMP 演算法在主字串中高效搜尋目標字串，匹配成功回傳 'y'，否則回傳 'n'。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <string.h>

int solve_uva10679(const char *text, const char *sub) {
    return strstr(text, sub) != NULL;
}

int main(void) {

    int ok = solve_uva10679("abcdefgh", "cde") && !solve_uva10679("abcdefgh", "xyz");
    printf("%s: UVa 10679 - I Love Strings!!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
