/*
 * ==========================================================================
 * UVa 12894 - Perfect Flag
 * Title-CN: 完美國旗尺寸與圓心座標檢驗
 * Difficulty: UVa Star 1
 * Tags: geometry
 * URL: https://onlinejudge.org/external/128/12894.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Check if rectangle and circle conform to Bangladesh flag standard (length=10k, width=6k, radius=2k, center at 45% length).
 *
 * [中文] 題目說明:
 *     檢驗孟加拉國旗規格：長寬比 10:6，半徑為長度的 1/5，圓心 x 座標位於長度 45% 處、y 座標位於寬度正中央。
 *
 * [EN] Approach:
 *     Verify L = x2 - x1, W = y2 - y1. Check 6*L == 10*W, 5*R == L, 20*(cx - x1) == 9*L, 2*(cy - y1) == W.
 * [中文] 思路:
 *     精確整數交叉相乘檢驗：長寬是否滿足 6*L == 10*W，半徑 5*R == L，圓心 x 偏移 20*dx == 9*L，圓心 y 偏移 2*dy == W。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva12894(int x0, int y0, int x1, int y1, int cx, int cy, int r) {
    int l = x1 - x0, w = y1 - y0;
    if (6 * l != 10 * w) return 0;
    if (5 * r != l) return 0;
    if (20 * (cx - x0) != 9 * l) return 0;
    if (2 * (cy - y0) != w) return 0;
    return 1;
}

int main(void) {

    int ok = solve_uva12894(0, 0, 10, 6, 4, 3, 2) == 0; /* 9*10/20 = 4.5 != 4 */
    int ok2 = solve_uva12894(0, 0, 20, 12, 9, 6, 4) == 1;
    int ok_all = ok && ok2;
    printf("%s: UVa 12894 - Perfect Flag\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
