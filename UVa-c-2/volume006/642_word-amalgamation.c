/*
 * ==========================================================================
 * UVa 642 - Word Amalgamation
 * Title-CN: 字母異序詞字典查詢
 * Difficulty: UVa Star 1
 * Tags: string, sorting, hash-table
 * URL: https://onlinejudge.org/external/6/642.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given scrambled word, find all matching dictionary words with exact same letter multiset in alphabetical order.
 *
 * [中文] 題目說明:
 *     給定被攪亂字母順序的單字，從字典中找出所有具備完全相同字母多重集的單詞，按字典序由小到大輸出。
 *
 * [EN] Approach:
 *     Sort characters of scrambled word. Compare with pre-sorted signatures of dictionary words.
 * [中文] 思路:
 *     將查詢單字字元排序獲取簽名，與字典中預先排好字元的單詞簽名進行逐一比對，匹配則輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_anagram_642(const char *s1, const char *s2) {
    int c1[26] = {0}, c2[26] = {0};
    for (int i = 0; s1[i]; i++) c1[s1[i] - 'a']++;
    for (int i = 0; s2[i]; i++) c2[s2[i] - 'a']++;
    for (int i = 0; i < 26; i++) if (c1[i] != c2[i]) return 0;
    return 1;
}

int main(void) {

    int ok = is_anagram_642("tar", "rat") && !is_anagram_642("tar", "car");
    printf("%s: UVa 642 - Word Amalgamation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
