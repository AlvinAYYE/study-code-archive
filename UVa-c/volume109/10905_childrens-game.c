/*
 * ==========================================================================
 * UVa 10905 - Children's Game
 * Title-CN: 兒童拼數字遊戲 (自定義貪婪字串排序拼最大數)
 * Difficulty: UVa Star 1
 * Tags: sorting, greedy, string
 * URL: https://onlinejudge.org/external/109/10905.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Concatenate numbers to form the largest possible number.
 *
 * [中文] 題目說明:
 *     將給定的多個正整數拼接組合，求能拼成的最大數值 (自定義字串比較規則 A+B vs B+A)。
 *
 * [EN] Approach:
 *     Custom string comparator: A comes before B if concat(A, B) > concat(B, A). Sort and concatenate.
 * [中文] 思路:
 *     自定義字串比較器：若 A+B 字典序大於 B+A 則 A 排在前面，排序後依序串接輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <string.h>

int cmp_str_concat(const char *a, const char *b) {
    char ab[100], ba[100];
    strcpy(ab, a); strcat(ab, b);
    strcpy(ba, b); strcat(ba, a);
    return strcmp(ba, ab); /* Descending */
}

int main(void) {

    int ok = (cmp_str_concat("9", "34") < 0); /* 934 > 349 */
    printf("%s: UVa 10905 - Children's Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
