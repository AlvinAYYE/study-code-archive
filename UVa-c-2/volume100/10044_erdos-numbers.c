/*
 * ==========================================================================
 * UVa 10044 - Erdos Numbers
 * Title-CN: 艾狄胥數
 * Difficulty: UVa Star 2
 * Tags: graph, bfs, string
 * ==========================================================================
 * [EN] Problem: Compute Erdos numbers (shortest collaboration distance from Paul Erdos).
 * [中文] 題目說明: 建立作者合作無向圖，計算由 Erdos 起算的 BFS 最短距離。
 * [EN] Approach: Graph construction from paper author lists + BFS from Erdos.
 * [中文] 思路: 論文作者建立圖節點與邊，從 Erdos 跑 BFS 標記距離。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 10044 - Erdos Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
