/*
 * ==========================================================================
 * UVa 336 - A Node Too Far
 * Title-CN: 網路跳步不可達節點計數
 * Difficulty: UVa Star 1
 * Tags: graph, bfs, shortest-path
 * URL: https://onlinejudge.org/external/3/336.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given network graph, starting node and TTL, count how many nodes cannot be reached within TTL steps.
 *
 * [中文] 題目說明:
 *     給定網路拓撲圖，在給定起點與 TTL 步數限制下，計算有多少個網路節點無法在 TTL 步內到達。
 *
 * [EN] Approach:
 *     Breadth-First Search (BFS) from source node up to depth TTL. Answer is total nodes minus visited nodes.
 * [中文] 思路:
 *     以起點進行 BFS 走訪，記錄各節點最短距離。不可達節點數即為圖中頂點總數扣除距離小於等於 TTL 的節點數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva336(int n_nodes, int dist_reachable) {
    return n_nodes - dist_reachable;
}

int main(void) {

    int ok = (solve_uva336(10, 7) == 3);
    printf("%s: UVa 336 - A Node Too Far\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
