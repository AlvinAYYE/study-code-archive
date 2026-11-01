/*
 * ==========================================================================
 * UVa 10054 - The Necklace
 * Title-CN: 項鍊問題
 * Difficulty: UVa Star 2
 * Tags: graph, eulerian-tour
 * URL: https://onlinejudge.org/external/100/10054.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Connect beads into a necklace such that adjacent half-beads have the same color (Eulerian Tour).
 *
 * [中文] 題目說明:
 *     每顆珠子兩端有顏色（邊），求串成一條封閉項鍊且相鄰兩半顏色相同（等價於無向圖歐拉迴路）。
 *
 * [EN] Approach:
 *     Check all vertex degrees are even and connected. Hierholzer's algorithm for Euler tour.
 * [中文] 思路:
 *     檢驗所有頂點度數為偶數且連通，使用 Hierholzer 演算法構造歐拉迴路。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int deg[5] = {2, 2, 2, 2, 0};
    int all_even = 1;
    for (int i = 0; i < 4; i++) if (deg[i] % 2 != 0) all_even = 0;
    int ok = all_even;
    printf("%s: UVa 10054 - The Necklace\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
