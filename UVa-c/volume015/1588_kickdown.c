/*
 * ==========================================================================
 * UVa 1588 - Kickdown
 * Title-CN: 齒條嚙合最短總長度
 * Difficulty: Easy
 * Tags: String, Simulation
 * URL: https://onlinejudge.org/external/15/1588.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Two tooth strips of heights 1 and 2 must fit into a container of height 3 without teeth overlapping (tooth heights at matching positions sum to <= 3). Find min length.
 *
 * [中文] 題目說明:
 *     兩根齒高為 1 與 2 的齒條需放入高度為 3 的槽中，任何重疊位置齒高之和不可超過 3，求最小包絡長度。
 *
 * [EN] Approach:
 *     Slide one strip relative to the other. For each offset shift, check if s1[i] - '0' + s2[i - shift] - '0' <= 3 for all overlapping positions.
 * [中文] 思路:
 *     滑動比較兩齒條的相對偏移量，檢查重疊處兩齒高之和是否均 <= 3，取重疊後總外接長度的最小值。
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

int min_kickdown_length(const char *s1, const char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int min_len = len1 + len2;
    for (int shift = -len2; shift <= len1; shift++) {
        bool ok = true;
        for (int i = 0; i < len2; i++) {
            int p1 = shift + i;
            if (p1 >= 0 && p1 < len1) {
                if ((s1[p1] - '0') + (s2[i] - '0') > 3) { ok = false; break; }
            }
        }
        if (ok) {
            int start = (shift < 0 ? shift : 0);
            int end = (shift + len2 > len1 ? shift + len2 : len1);
            int total = end - start;
            if (total < min_len) min_len = total;
        }
    }
    return min_len;
}

int main(void) {

    int res = min_kickdown_length("2112", "221");
    int ok = (res <= 6);
    printf("%s: UVa 1588 - Kickdown\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
