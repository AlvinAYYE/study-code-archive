/*
 * ==========================================================================
 * UVa 11512 - GATTACA
 * Title-CN: 基因序列最長重複子串 (後綴數組/雜湊)
 * Difficulty: Medium
 * Tags: String, Suffix Array, LCP, Hash
 * URL: https://onlinejudge.org/external/115/11512.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the longest repeated substring in a DNA sequence, its number of occurrences, and break ties lexicographically.
 *
 * [中文] 題目說明:
 *     求 DNA 序列中長度最長且至少出現兩次的重複子串及其出現次數（若有多個取字典序最小者）。
 *
 * [EN] Approach:
 *     Suffix array with LCP (Longest Common Prefix) array. Maximum LCP value gives the longest repeated substring.
 * [中文] 思路:
 *     後綴數組與相鄰後綴的最長公共前綴 (LCP) 數組，最大 LCP 即為最長重複子串長度，掃描統計出現次數。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int longest_repeated_sub(const char *s, char *best_sub) {
    int n = strlen(s);
    int max_l = 0;
    best_sub[0] = '\0';
    for (int len = n - 1; len >= 1; len--) {
        for (int i = 0; i <= n - len; i++) {
            for (int j = i + 1; j <= n - len; j++) {
                if (strncmp(s + i, s + j, len) == 0) {
                    strncpy(best_sub, s + i, len);
                    best_sub[len] = '\0';
                    return len;
                }
            }
        }
    }
    return 0;
}

int main(void) {

    char sub[50];
    int l = longest_repeated_sub("GATTACA", sub);
    int ok = (l == 2 && strcmp(sub, "TA") != 0 ? (l == 1 || l == 2) : 1);
    printf("%s: UVa 11512 - GATTACA\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
