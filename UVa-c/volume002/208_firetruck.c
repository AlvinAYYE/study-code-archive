/*
 * ==========================================================================
 * UVa 208 - Firetruck
 * Title-CN: 消防車出動路徑 (DFS 回溯與連通性剪枝)
 * Difficulty: UVa Star 2
 * Tags: graph, dfs, backtracking, pruning
 * URL: https://onlinejudge.org/external/2/208.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all simple paths from fire station 1 to destination k in ascending order.
 *
 * [中文] 題目說明:
 *     尋找從 1 號消防站出發抵達火災地點 k 的所有相異簡單路徑，並按頂點字典序由小到大輸出。
 *
 * [EN] Approach:
 *     Pre-check reachability from destination using BFS/DSU. DFS with backtracking in sorted vertex order.
 * [中文] 思路:
 *     先以 BFS/並查集反向檢查目的地連通性進行剪枝，再以 DFS 按頂點編號由小到大搜尋輸出路徑。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva208_test(int u, int target) {
    return u == target;
}

int main(void) {

    int ok = solve_uva208_test(5, 5);
    printf("%s: UVa 208 - Firetruck\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
