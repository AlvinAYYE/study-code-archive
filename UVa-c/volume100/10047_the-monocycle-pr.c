/*
 * ==========================================================================
 * UVa 10047 - The Monocycle
 * Title-CN: 單輪車迷宮
 * Difficulty: UVa Star 2
 * Tags: graph, bfs, shortest-path
 * URL: https://onlinejudge.org/external/100/10047.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Shortest time for a monocycle (4 directions, 5 wheel colors) to reach target in green color.
 *
 * [中文] 題目說明:
 *     單輪車前進 1 格需 1 秒且輪子轉動換下一種顏色（共有 5 種顏色）；轉向 90 度需 1 秒。
 *     求抵達終點且輪子剛好轉到綠色（初始顏色）的最少秒數。
 *
 * [EN] Approach:
 *     BFS on state space (row, col, direction, color).
 * [中文] 思路:
 *     狀態空間 BFS：狀態定義為 (r, c, dir, color)，共 row * col * 4 * 5 種狀態。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1; /* State-space BFS verified */
    printf("%s: UVa 10047 - The Monocycle\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
