/*
 * ==========================================================================
 * UVa 10252 - Common Permutation
 * Title-CN: 共同排列 (兩字串公共字母排序)
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: string, frequency-counting, two-pointers
 * URL: https://onlinejudge.org/external/102/10252.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     Given two strings of lowercase letters, a and b, print the longest string x
 *     such that x is a permutation of a subsequence of a and also a permutation
 *     of a subsequence of b. The output letters must be in alphabetical order.
 *
 * [中文] 題目說明:
 *     給定兩個皆由小寫英文字母組成的字串 a 與 b。找出最長的字串 x，使得 x
 *     同時是 a 的子序列的某種排列，也是 b 的子序列的某種排列。
 *     若有多個字母符合，必須依照字母升序（a 到 z）依序輸出。
 *
 * Examples:
 *   Input:
 *     pretty
 *     women
 *     walking
 *     down
 *   Output:
 *     e
 *     nw
 *
 * [EN] Approach:
 *     Count character frequencies in both strings (cntA[26], cntB[26]).
 *     For each character 'a' through 'z', take min(cntA[i], cntB[i]) and output.
 * [中文] 思路:
 *     分別統計兩字串中 26 個英文字母的出現次數。
 *     依序檢查 'a' 至 'z'，取兩者次數的最小值並輸出對應數量的字元。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static inline int min_val(int a, int b) {
    return a < b ? a : b;
}

void solve_uva10252(const char *a, const char *b, char *out) {
    int countA[26] = {0};
    int countB[26] = {0};

    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] >= 'a' && a[i] <= 'z') countA[a[i] - 'a']++;
    }
    for (int i = 0; b[i] != '\0'; i++) {
        if (b[i] >= 'a' && b[i] <= 'z') countB[b[i] - 'a']++;
    }

    int idx = 0;
    for (int i = 0; i < 26; i++) {
        int common = min_val(countA[i], countB[i]);
        for (int k = 0; k < common; k++) {
            out[idx++] = (char)('a' + i);
        }
    }
    out[idx] = '\0';
}

int main(void) {
    char out1[128], out2[128];
    solve_uva10252("pretty", "women", out1);
    solve_uva10252("walking", "down", out2);

    int ok = (strcmp(out1, "e") == 0) && (strcmp(out2, "nw") == 0);
    printf("%s: UVa 10252 - Common Permutation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
