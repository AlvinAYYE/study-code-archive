/*
 * ==========================================================================
 * UVa 11340 - Newspaper
 * Title-CN: 報紙字元計費總額計算
 * Difficulty: UVa Star 1
 * Tags: string, hash
 * URL: https://onlinejudge.org/external/113/11340.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given price per character for K paid characters, calculate total cost of an article in dollars and cents.
 *
 * [中文] 題目說明:
 *     給定 K 個指定字元的計費單價 (以美分為單位)，計算整篇新聞報導所有字元的總報酬金額。
 *
 * [EN] Approach:
 *     Maintain a direct-mapped lookup table table[256]. Scan each character of the text, accumulate cents, and format as dollars.
 * [中文] 思路:
 *     建立 256 大小的直接映射查找表，掃描文章字元流累加美分總值，最後轉換為美元與美分。
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

long long solve_uva11340(const char *text, int *table) {
    long long total_cents = 0;
    for (int i = 0; text[i]; i++) {
        unsigned char uc = (unsigned char)text[i];
        total_cents += table[uc];
    }
    return total_cents;
}

int main(void) {

    int tbl[256] = {0};
    tbl['a'] = 3; tbl['b'] = 5;
    long long res = solve_uva11340("ababa", tbl);
    int ok = (res == 19); // 3*3 + 5*2 = 19
    printf("%s: UVa 11340 - Newspaper\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
