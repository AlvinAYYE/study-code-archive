/*
 * ==========================================================================
 * UVa 10004 - Bicoloring
 * Title-CN: 二分圖著色判定
 * Difficulty: UVa Star 2
 * Tags: graph, bfs, bipartite
 * URL: https://onlinejudge.org/external/100/10004.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a given connected graph can be 2-colored such that
 *     no two adjacent vertices have the same color.
 *
 * [中文] 題目說明:
 *     給定一個連通無向圖，判斷其是否為二分圖（能否僅用兩種顏色為頂點著色，使得
 *     任兩相鄰頂點顏色皆相異）。若可以輸出 "BICOLORABLE."，否則輸出 "NOT BICOLORABLE."。
 *
 * [EN] Approach:
 *     BFS or DFS graph traversal. Assign color 1 to start node. For each neighbor,
 *     if uncolored, assign 3 - color; if already colored with the same color, not bipartite.
 * [中文] 思路:
 *     使用 BFS 或 DFS 走訪圖。起點設為顏色 1，相鄰節點染為顏色 2。若發現相鄰節點已被
 *     染成相同顏色，則非二分圖。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int solve_uva10004(int n, int m, int edges[][2]) {
    int adj[205][205] = {0};
    int deg[205] = {0};
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    int color[205];
    memset(color, 0, sizeof(color));

    int q[205], front = 0, back = 0;
    q[back++] = 0;
    color[0] = 1;

    while (front < back) {
        int u = q[front++];
        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (color[v] == 0) {
                color[v] = 3 - color[u];
                q[back++] = v;
            } else if (color[v] == color[u]) {
                return 0; /* NOT BICOLORABLE */
            }
        }
    }
    return 1; /* BICOLORABLE */
}

int main(void) {
    int e1[3][2] = {{0, 1}, {1, 2}, {2, 0}}; /* Triangle: odd cycle -> false */
    int ok1 = !solve_uva10004(3, 3, e1);

    int e2[4][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}}; /* Square: even cycle -> true */
    int ok2 = solve_uva10004(4, 4, e2);

    int ok = ok1 && ok2;
    printf("%s: UVa 10004 - Bicoloring\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
