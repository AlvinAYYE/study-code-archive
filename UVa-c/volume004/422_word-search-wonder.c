/*
 * ==========================================================================
 * UVa 422 - Word-Search Wonder
 * Title-CN: 字詞搜尋奇蹟 (8方向單字搜索)
 * Difficulty: Easy
 * Tags: String, Grid Search
 * URL: https://onlinejudge.org/external/4/422.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find starting and ending coordinates of words in an N x N letter grid in any of the 8 straight directions.
 *
 * [中文] 題目說明:
 *     在 N x N 字母網格中沿 8 個直角或對角線方向搜索單字，求起點與終點坐標。
 *
 * [EN] Approach:
 *     Check all grid starting points (r, c) and 8 directions (dr, dc). Match word characters in order.
 * [中文] 思路:
 *     遍歷每個網格點 (r, c) 作為起點，嘗試 8 個方向逐字匹配，成功則記錄起點與終點坐標。
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

bool find_word(int n, char g[10][10], const char *word, int *r1, int *c1, int *r2, int *c2) {
    int len = strlen(word);
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int k = 0; k < 8; k++) {
                int er = r + dr[k] * (len - 1);
                int ec = c + dc[k] * (len - 1);
                if (er >= 0 && er < n && ec >= 0 && ec < n) {
                    bool match = true;
                    for (int i = 0; i < len; i++) {
                        if (g[r + dr[k]*i][c + dc[k]*i] != word[i]) { match = false; break; }
                    }
                    if (match) {
                        *r1 = r + 1; *c1 = c + 1;
                        *r2 = er + 1; *c2 = ec + 1;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(void) {

    char g[10][10] = {"CAT", "DOG", "FOX"};
    int r1, c1, r2, c2;
    bool ok = find_word(3, g, "DOG", &r1, &c1, &r2, &c2);
    ok = ok && (r1 == 2 && c1 == 1 && r2 == 2 && c2 == 3);
    printf("%s: UVa 422 - Word-Search Wonder\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
