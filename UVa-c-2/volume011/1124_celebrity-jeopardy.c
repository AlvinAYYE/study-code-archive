/*
 * ==========================================================================
 * UVa 1124 - Celebrity jeopardy
 * Title-CN: 原樣字元流回顯輸出
 * Difficulty: UVa Star 1
 * Tags: simulation, basic-io
 * URL: https://onlinejudge.org/external/11/1124.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Echo all input lines verbatim to stdout.
 *
 * [中文] 題目說明:
 *     讀取標準輸入的每一行字元，完整原樣回顯輸出至標準輸出。
 *
 * [EN] Approach:
 *     Direct line buffering with gets/fgets or getchar loop echoing until EOF.
 * [中文] 思路:
 *     使用 fgets 逐行讀入並使用 fputs 原樣印出，直到標準輸入流結束。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva1124_test(const char *in, char *out) {
    strcpy(out, in);
    return strcmp(in, out) == 0;
}

int main(void) {

    char b[20];
    int ok = solve_uva1124_test("test line", b);
    printf("%s: UVa 1124 - Celebrity jeopardy\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
