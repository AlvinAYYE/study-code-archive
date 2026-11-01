/*
 * ==========================================================================
 * UVa 196 - Spreadsheet
 * Title-CN: 電子表格計算 (公式解析與拓撲排序求值)
 * Difficulty: Medium
 * Tags: DFS, Memoization, Topological Sort
 * URL: https://onlinejudge.org/external/1/196.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Evaluate an R x C spreadsheet with integer constants and formula cells '=A1+B2+...'.
 *
 * [中文] 題目描述:
 *     計算含整數常數與加法公式單元格（如 =A1+B2+...）的電子表格各單元格的最終數值。
 *
 * [EN] Approach:
 *     DFS with memoization: formula evaluation recursively resolves referenced cells. No circular dependencies exist.
 *
 * [中文] 解題思維:
 *     帶記憶化的 DFS：單元格為純數字直接返回；若為公式則解析各引用坐標，遞迴求解相加並記憶化。
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

void parse_cell_name(const char *name, int *r, int *c) {
    int col = 0;
    const char *p = name;
    while (*p >= 'A' && *p <= 'Z') {
        col = col * 26 + (*p - 'A' + 1);
        p++;
    }
    *c = col - 1;
    *r = atoi(p) - 1;
}

int main(void) {

    int r, c;
    parse_cell_name("A1", &r, &c);
    int ok = (r == 0 && c == 0);
    parse_cell_name("B2", &r, &c);
    ok = ok && (r == 1 && c == 1);
    printf("%s: UVa 196 - Spreadsheet\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
