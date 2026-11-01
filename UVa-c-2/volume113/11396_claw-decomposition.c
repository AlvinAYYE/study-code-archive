/*
 * ==========================================================================
 * UVa 11396 - Claw Decomposition
 * Title-CN: 爪圖分解 (二分圖判定)
 * Difficulty: Medium
 * Tags: Graph, Bipartite Check, 2-Coloring
 * URL: https://onlinejudge.org/external/113/11396.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a 3-regular graph can be decomposed into claw graphs (K_{1,3}).
 *
 * [中文] 題目說明:
 *     判斷一個 3-正則圖是否能分解為爪圖 (K_{1,3})。由定理知當且僅當圖為二分圖時可分解。
 *
 * [EN] Approach:
 *     A 3-regular graph is claw-decomposable if and only if it is bipartite. Use BFS/DFS 2-coloring to check.
 * [中文] 思路:
 *     根據圖論定理，3-正則圖能分解為爪圖的充要條件是該圖為二分圖。使用 BFS 進行二染色判定即可。
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

bool is_bipartite_graph(int n, const int adj[20][20]) {
    int color[20];
    for (int i = 0; i < n; i++) color[i] = -1;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            int q[20], head = 0, tail = 0;
            q[tail++] = i;
            while (head < tail) {
                int u = q[head++];
                for (int v = 0; v < n; v++) {
                    if (adj[u][v]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q[tail++] = v;
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main(void) {

    int adj[20][20] = {0}; adj[0][1] = adj[1][0] = 1; adj[0][2] = adj[2][0] = 1; adj[0][3] = adj[3][0] = 1;
    int ok = is_bipartite_graph(4, adj);
    printf("%s: UVa 11396 - Claw Decomposition\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
