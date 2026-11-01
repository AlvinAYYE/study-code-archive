/*
 * ==========================================================================
 * UVa 1339 - Ancient Cipher
 * Title-CN: 古代密碼字母置換與排列判定
 * Difficulty: UVa Star 1
 * Tags: string, sorting
 * URL: https://onlinejudge.org/external/13/1339.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if string A can be transformed into string B by a combination of letter substitution bijection and character permutation.
 *
 * [中文] 題目概述:
 *     判定字串 A 是否能透過字母單射置換與字母順序重排轉換為字串 B (字元各自出現頻率集合相同)。
 *
 * [EN] Approach:
 *     Count character frequencies in A and B (arrays of size 26). Sort both frequency arrays; return 1 if identical, else 0.
 * [中文] 解題思路:
 *     統計字串中 26 個字母出現頻率，將頻率數組排序後，若頻率分佈完全一致則可以轉換。
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

static int cmp1339(const void *a, const void *b) { return (*(int*)a - *(int*)b); }

int solve_uva1339(const char *s1, const char *s2) {
    int c1[26] = {0}, c2[26] = {0};
    for (int i = 0; s1[i]; i++) c1[s1[i] - 'A']++;
    for (int i = 0; s2[i]; i++) c2[s2[i] - 'A']++;
    qsort(c1, 26, sizeof(int), cmp1339);
    qsort(c2, 26, sizeof(int), cmp1339);
    for (int i = 0; i < 26; i++) if (c1[i] != c2[i]) return 0;
    return 1;
}

int main(void) {
    int ok = solve_uva1339("VICTORIOUS", "JWPUDJSTVP") && !solve_uva1339("MAMA", "PIPA");
    printf("%s: UVa 1339 - Ancient Cipher\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
