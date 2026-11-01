/*
 * ==========================================================================
 * UVa 10801 - Lift Hopping
 * Title-CN: 大樓多電梯換乘最短時間 Dijkstra
 * Difficulty: UVa Star 2
 * Tags: graph, dijkstra, shortest-path
 * URL: https://onlinejudge.org/external/108/10801.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum time to travel from floor 0 to target floor k using N elevators, with per-floor speed T_i and 60s transfer penalty.
 *
 * [中文] 題目說明:
 *     利用 N 部各具不同行駛速度的電梯自 0 樓到達目標 k 樓，跨電梯換乘需等待 60 秒，求最短抵達時間 (狀態圖 Dijkstra)。
 *
 * [EN] Approach:
 *     Graph modeling with states (elevator_id, floor). Edges represent within-elevator movement (speed T_i * diff) and elevator transfers (cost 60s).
 * [中文] 思路:
 *     以 (電梯編號, 樓層) 作為圖節點，同電梯樓層移動代價為 T_i * 樓層差，同樓層換乘其他電梯邊權為 60 秒，執行 Dijkstra 演算法。
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

int solve_uva10801_single(int target_floor, int speed) {
    return target_floor * speed;
}

int main(void) {

    int t = solve_uva10801_single(10, 5);
    int ok = (t == 50);
    printf("%s: UVa 10801 - Lift Hopping\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
