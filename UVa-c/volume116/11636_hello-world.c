/*
 * ==========================================================================
 * UVa 11636 - Hello World!
 * Title-CN: 複製貼上最少次數 (倍增對數)
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/116/11636.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum copy-paste operations to obtain at least N lines of 'Hello World!' starting from 1 line.
 *
 * [中文] 題目說明:
 *     從 1 行文字開始，每次可複製既有所有文字並貼上 (行數翻倍)，求產生至少 N 行所需的最少貼上次數。
 *
 * [EN] Approach:
 *     Doubling: ceil(log2(N)). If N <= 1 return 0; else count times doubling until >= N.
 * [中文] 思路:
 *     每次操作行數翻倍 (1->2->4->8...)，即求 ceil(log2(N))。以迴圈每次乘 2 統計步數直至達到或超過 N。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11636(int n) {
    if (n <= 1) return 0;
    int steps = 0, cur = 1;
    while (cur < n) {
        cur *= 2;
        steps++;
    }
    return steps;
}

int main(void) {

    int ok = (solve_uva11636(1) == 0) && (solve_uva11636(2) == 1) && (solve_uva11636(5) == 3);
    printf("%s: UVa 11636 - Hello World!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
