/*
 * ==========================================================================
 * UVa 11686 - Pick up sticks
 * Title-CN: 撿木棒 (拓撲排序與環檢測)
 * Difficulty: Medium
 * Tags: Graph, Topological Sort, DAG
 * URL: https://onlinejudge.org/external/116/11686.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find a valid pickup order for n sticks with given on-top-of constraints, or determine if impossible (cycle exists).
 *
 * [中文] 題目說明:
 *     給定木棒之間的壓疊先後關係，求一組可行的撿取順序；若存在環導致無法撿完則判定為不可能。
 *
 * [EN] Approach:
 *     Kahn's topological sort algorithm using in-degree array and queue. If sorted count equals n, valid; else cycle.
 * [中文] 思路:
 *     Kahn 演算法：統計入度為 0 的節點入隊，依序刪除出邊並更新鄰居入度。若拓撲排序長度為 n 則有解，否則有環。
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

bool pick_up_sticks_topo(int n, int m, const int edges[][2], int *order) {
    int in_deg[20] = {0};
    int adj[20][20] = {0};
    for (int i = 0; i < m; i++) {
        int u = edges[i][0] - 1, v = edges[i][1] - 1;
        adj[u][v] = 1;
        in_deg[v]++;
    }
    int q[20], head = 0, tail = 0;
    for (int i = 0; i < n; i++) if (in_deg[i] == 0) q[tail++] = i;
    int cnt = 0;
    while (head < tail) {
        int u = q[head++];
        order[cnt++] = u + 1;
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && --in_deg[v] == 0) q[tail++] = v;
        }
    }
    return (cnt == n);
}

int main(void) {

    int edges[2][2] = {{1, 2}, {2, 3}};
    int ord[3];
    bool ok = pick_up_sticks_topo(3, 2, edges, ord) && (ord[0] == 1 && ord[1] == 2 && ord[2] == 3);
    printf("%s: UVa 11686 - Pick up sticks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
