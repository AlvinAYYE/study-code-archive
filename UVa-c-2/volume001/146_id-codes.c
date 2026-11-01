/*
 * ==========================================================================
 * UVa 146 - ID Codes
 * Title-CN: 識別碼字典序下一個排列
 * Difficulty: UVa Star 1
 * Tags: string, permutation
 * ==========================================================================
 * [EN] Problem: Generate next lexicographical permutation of a string. Output "No Successor" if last.
 * [中文] 題目說明: 產生給定字串的字典序下一個排列；若已是最後一個排列則輸出 "No Successor"。
 * [EN] Approach: Classic next_permutation algorithm in C.
 * [中文] 思路: 由右向左尋找第一對降序位置，交換並反轉後綴。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static void swap(char *a, char *b) { char t = *a; *a = *b; *b = t; }

int next_perm(char *s) {
    int n = (int)strlen(s);
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1]) i--;
    if (i < 0) return 0;
    int j = n - 1;
    while (s[j] <= s[i]) j--;
    swap(&s[i], &s[j]);
    int l = i + 1, r = n - 1;
    while (l < r) { swap(&s[l], &s[r]); l++; r--; }
    return 1;
}

int main(void) {
    char s[10] = "abaac";
    int has = next_perm(s);
    int ok = has && (strcmp(s, "abaca") == 0);
    printf("%s: UVa 146 - ID Codes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
