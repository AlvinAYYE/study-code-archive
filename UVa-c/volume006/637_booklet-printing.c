/*
 * ==========================================================================
 * UVa 637 - Booklet Printing
 * Title-CN: 小冊子雙面列印頁碼排列模擬
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/6/637.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate folding sheets of paper into a booklet: determine page numbers printed on front and back of each sheet for an N-page document.
 *
 * [中文] 題目概述:
 *     模擬將紙張對折裝訂成小冊子：計算包含 N 頁的文件在每張紙正面與背面左右兩側應列印的頁碼 (不足處補 Blank)。
 *
 * [EN] Approach:
 *     Total booklet slots = 4 * ceil(N / 4). Pages 1..N arranged on front/back: Sheet k Front has (Total - 2k + 2, 2k - 1), Back has (2k, Total - 2k + 1).
 * [中文] 解題思路:
 *     總格數為 4 的最小倍數 4*ceil(N/4)，第 k 張紙正面為 (總頁-2k+2, 2k-1)，背面為 (2k, 總頁-2k+1)，頁碼大於 N 標示為 Blank。
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

int booklet_total_pages(int n) {
    return ((n + 3) / 4) * 4;
}

int main(void) {

    int ok = (booklet_total_pages(1) == 4 && booklet_total_pages(14) == 16);
    printf("%s: UVa 637 - Booklet Printing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
