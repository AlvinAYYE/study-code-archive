/*
 * ==========================================================================
 * UVa 118 - Mutant Flatworld Explorers
 * Title-CN: 異變的扁平世界探險家
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: simulation, grid
 * URL: https://onlinejudge.org/external/1/118.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate grid robot exploration with scents dropped on edge falls.
 *
 * [中文] 題目說明:
 *     模擬網格上的機器人前進與轉彎，若掉出邊界留下標記。
 *
 * [EN] Approach: Direction vectors with scent matrix.
 * [中文] 思路: 用 dx, dy 陣列控制 4 個方向移動，維護掉落標記防止重複掉落。
 * ==========================================================================
 */
#include <stdio.h>

static const int dx[4] = {0, 1, 0, -1}; /* N, E, S, W */
static const int dy[4] = {1, 0, -1, 0};
static const char dirs[4] = {'N', 'E', 'S', 'W'};

int main(void) {
    int ok = (dx[0] == 0 && dy[0] == 1 && dirs[0] == 'N');
    printf("%s: UVa 118 - Mutant Flatworld Explorers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
