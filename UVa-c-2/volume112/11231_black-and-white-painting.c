/*
 * ==========================================================================
 * UVa 11231 - Black and white painting
 * Title-CN: 黑白棋盤格 8x8 棋盤子矩陣計數
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/112/11231.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count how many 8x8 standard chessboards (bottom-right square white) can be cut out of an n x m grid with top-left square colored c.
 *
 * [中文] 題目說明:
 *     在 n x m 的交錯黑白方格網中，計算有多少個 8x8 標準西洋棋盤 (右下角格子為白色) 可以被完整裁切出來。
 *
 * [EN] Approach:
 *     Total 8x8 subgrids is (n - 7) * (m - 7). Exactly half of them end on white squares, plus c if the total product is odd.
 * [中文] 思路:
 *     總可裁切 8x8 區塊數為 (n - 7) * (m - 7)，其中剛好有一半右下角為白色，若乘積為奇數則加上底色偏移量 c。
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

long long solve_uva11231(long long n, long long m, int c) {
    long long total = (n - 7) * (m - 7);
    return (total + c) / 2;
}

int main(void) {

    int ok = (solve_uva11231(8, 8, 1) == 1 && solve_uva11231(8, 8, 0) == 0);
    printf("%s: UVa 11231 - Black and white painting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
