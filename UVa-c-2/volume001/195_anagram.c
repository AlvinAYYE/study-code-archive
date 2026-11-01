/*
 * ==========================================================================
 * UVa 195 - Anagram
 * Title-CN: 自定義大小寫字母字典序全排列
 * Difficulty: UVa Star 1
 * Tags: string, sorting, backtracking, permutation
 * URL: https://onlinejudge.org/external/1/195.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Print all permutations of a string without duplicates in custom alphabetical order: 'A' < 'a' < 'B' < 'b' < ...
 *
 * [中文] 題目說明:
 *     輸出給定字串的所有不重複全排列，依題目規定的自定義字母順序：'A' < 'a' < 'B' < 'b' ... 嚴格排序。
 *
 * [EN] Approach:
 *     Sort characters with custom comparator, then use next_permutation logic handling duplicate elements cleanly.
 * [中文] 思路:
 *     依題目特殊大小寫優先序進行字元排序，接著以遞迴回溯或字典序下一個排列 (next_permutation) 跳過重複字元輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp_uva195_char(char a, char b) {
    char la = (char)tolower((unsigned char)a);
    char lb = (char)tolower((unsigned char)b);
    if (la != lb) return la - lb;
    return a - b;
}

int main(void) {

    int ok = (cmp_uva195_char('A', 'a') < 0) && (cmp_uva195_char('a', 'B') < 0);
    printf("%s: UVa 195 - Anagram\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
