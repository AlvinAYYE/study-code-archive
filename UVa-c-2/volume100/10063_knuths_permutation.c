/*
 * ==========================================================================
 * UVa 10063 - Knuth's Permutation
 * Title-CN: 高德納全排列產生法
 * Difficulty: Easy
 * Tags: Recursion, Permutations
 * URL: https://onlinejudge.org/external/100/10063.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Generate all permutations of a string by successively inserting each character into all possible positions.
 *
 * [中文] 題目描述:
 *     依照高德納算法，依序將字串中的每個字元插入到目前排列的所有可能位置，輸出全排列。
 *
 * [EN] Approach:
 *     Recursive insertion: start with 1-char prefix, insert 2nd char at index 0 and 1, then 3rd char at 0, 1, 2, etc.
 *
 * [中文] 解題思維:
 *     遞歸插入：從首字元開始，下一字元分別插入前綴的各個位置，直到長度達到原字串長度。
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

static int perm_count_10063;

static void knuth_perm_dfs(const char *orig, int idx, int n, char *cur) {
    if (idx == n) {
        perm_count_10063++;
        return;
    }
    char next_ch = orig[idx];
    char next_buf[15];
    for (int pos = 0; pos <= idx; pos++) {
        for (int j = 0; j < pos; j++) next_buf[j] = cur[j];
        next_buf[pos] = next_ch;
        for (int j = pos; j < idx; j++) next_buf[j + 1] = cur[j];
        next_buf[idx + 1] = '\0';
        knuth_perm_dfs(orig, idx + 1, n, next_buf);
    }
}

int count_knuth_permutations(const char *s) {
    perm_count_10063 = 0;
    int n = (int)strlen(s);
    if (n == 0) return 0;
    char cur[15];
    cur[0] = s[0];
    cur[1] = '\0';
    knuth_perm_dfs(s, 1, n, cur);
    return perm_count_10063;
}

int main(void) {

    int ok = (count_knuth_permutations("abc") == 6) &&
             (count_knuth_permutations("abcd") == 24);
    printf("%s: UVa 10063 - Knuth's Permutation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
