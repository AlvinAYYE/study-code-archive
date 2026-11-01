/*
 * ==========================================================================
 * UVa 10098 - Generating Fast, Sorted Permutation
 * Title-CN: 快速產生相異字母排列
 * Difficulty: UVa Star 1
 * Tags: backtracking, string, permutation
 * ==========================================================================
 * [EN] Problem: Generate all unique permutations of a string in alphabetical order.
 * [中文] 題目說明: 依照字母升序產生字串的所有不重複排列。
 * [EN] Approach: Sort characters, use next_permutation algorithm iteratively.
 * [中文] 思路: 字元排序後以字典序下一個排列演算法生成。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static void swap(char *a, char *b) { char t = *a; *a = *b; *b = t; }

int next_perm(char *s, int len) {
    int i = len - 2;
    while (i >= 0 && s[i] >= s[i + 1]) i--;
    if (i < 0) return 0;
    int j = len - 1;
    while (s[j] <= s[i]) j--;
    swap(&s[i], &s[j]);
    int l = i + 1, r = len - 1;
    while (l < r) { swap(&s[l], &s[r]); l++; r--; }
    return 1;
}

int main(void) {
    char s[] = "abc";
    int count = 1;
    while (next_perm(s, 3)) count++;
    int ok = (count == 6);
    printf("%s: UVa 10098 - Generating Fast\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
