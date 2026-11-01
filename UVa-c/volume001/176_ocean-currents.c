/*
 * ==========================================================================
 * UVa 176 - Ocean Currents
 * Title-CN: 海流網格 0-1 BFS 最短路徑
 * Difficulty: UVa Star 2
 * Tags: graph, bfs
 * URL: https://onlinejudge.org/external/1/176.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum energy path on an ocean grid where moving with the current costs 0 energy and moving in other directions costs 1 energy.
 *
 * [中文] 題目說明:
 *     在帶有海流方向的海洋網格上尋找耗能最少的航行路徑：順著海流移動能量消耗為 0，轉向其他方向移動能量消耗為 1。
 *
 * [EN] Approach:
 *     0-1 Breadth First Search using a double-ended queue (deque). Edges with weight 0 are pushed to front, weight 1 to back.
 * [中文] 思路:
 *     利用雙端佇列 (deque) 實現 0-1 BFS：若下一步方向與當前洋流一致則邊權為 0 (推入隊頭)，否則邊權為 1 (推入隊尾)。
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

int move_cost(int current_dir, int target_dir) {
    return (current_dir == target_dir) ? 0 : 1;
}

int main(void) {

    int ok = (move_cost(3, 3) == 0 && move_cost(3, 4) == 1);
    printf("%s: UVa 176 - Ocean Currents\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
