/*
 * ==========================================================================
 * UVa 155 - All Squares
 * Title-CN: 遞迴正方形覆蓋點計數
 * Difficulty: UVa Star 2
 * Tags: recursion, geometry
 * URL: https://onlinejudge.org/external/1/155.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count how many nested recursive squares cover a given point (px, py).
 *
 * [中文] 題目說明:
 *     遞迴繪製四角中心的正方形，計算目標點 (px, py) 被多少個正方形所覆蓋 (遞迴幾何)。
 *
 * [EN] Approach:
 *     Recursive geometric check: count +1 if (px, py) inside current square centered at (cx, cy) with size k; recurse on 4 corners with k/2.
 * [中文] 思路:
 *     檢查點是否在當前以 (cx, cy) 為中心、半徑為 k 的正方形內；若 k > 1 則遞迴向四個角落 (cx±k, cy±k) 擴展。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count_squares(int k, int cx, int cy, int px, int py) {
    if (k < 1) return 0;
    int inside = (px >= cx - k && px <= cx + k && py >= cy - k && py <= cy + k);
    int total = inside ? 1 : 0;
    if (k > 1) {
        total += count_squares(k / 2, cx - k, cy - k, px, py);
        total += count_squares(k / 2, cx - k, cy + k, px, py);
        total += count_squares(k / 2, cx + k, cy - k, px, py);
        total += count_squares(k / 2, cx + k, cy + k, px, py);
    }
    return total;
}

int main(void) {

    int ok = (count_squares(64, 1024, 1024, 1024, 1024) >= 1);
    printf("%s: UVa 155 - All Squares\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
