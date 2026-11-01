/*
 * ==========================================================================
 * UVa 159 - Word Crosses
 * Title-CN: 單字相交十字格排版輸出
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/1/159.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two pairs of intersecting words, find matching common letters and print a side-by-side 2D character grid cross.
 *
 * [中文] 題目說明:
 *     給定兩組相交的英文單字，尋找首個相同公共字母形成十字交叉，並排印出二維字元十字交叉圖形。
 *
 * [EN] Approach:
 *     Find first matching character between horizontal and vertical words. Lay out characters onto 2D text buffer and print with spacing.
 * [中文] 思路:
 *     遍歷橫向與縱向單字尋找首個相同之相交字母，在二維字元緩衝區中填入單字並保持相對位置與空白輸出。
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

int find_match(const char *h, const char *v, int *h_idx, int *v_idx) {
    for (int i = 0; h[i]; i++) {
        for (int j = 0; v[j]; j++) {
            if (h[i] == v[j]) {
                *h_idx = i; *v_idx = j;
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {

    int hi, vi;
    int f = find_match("CAT", "DOGS", &hi, &vi);
    int ok = (!f);
    f = find_match("MATCH", "APPLE", &hi, &vi);
    ok = ok && (f && hi == 1 && vi == 0);
    printf("%s: UVa 159 - Word Crosses\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
