/*
 * ==========================================================================
 * UVa 11687 - Digits
 * Title-CN: 數位長度遞推固定點收斂步數
 * Difficulty: UVa Star 1
 * Tags: math, string
 * URL: https://onlinejudge.org/external/116/11687.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given x_0, define x_i = length(x_{i-1}). Find the smallest index i such that x_i = x_{i-1}.
 *
 * [中文] 題目概述:
 *     給定超大正整數 x_0，令 x_i 為 x_{i-1} 轉為十進位字串後的長度，求首個滿足 x_i = x_{i-1} 的最小下標 i。
 *
 * [EN] Approach:
 *     Compute len = strlen(s). If s == '1' return 1. Otherwise iterate: step = 1, cur = len, next = digits_of(cur), repeat until cur == next.
 * [中文] 解題思路:
 *     若初始字串即為 "1" 則步數為 1；否則以其長度開始迭代，計算每次長度之位數，直至數值不再變化收斂至 1 為止。
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

int solve_uva11687(const char *s) {
    if (strcmp(s, "1") == 0) return 1;
    int cur = strlen(s);
    int step = 1;
    while (1) {
        step++;
        char buf[20];
        sprintf(buf, "%d", cur);
        int next_len = strlen(buf);
        if (next_len == cur) return step;
        cur = next_len;
    }
}

int main(void) {

    int ok = (solve_uva11687("1") == 1 && solve_uva11687("42") == 3);
    printf("%s: UVa 11687 - Digits\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
