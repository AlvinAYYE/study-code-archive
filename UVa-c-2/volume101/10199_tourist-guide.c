/*
 * ==========================================================================
 * UVa 10199 - Tourist Guide
 * Title-CN: 觀光地圖關鍵關節點割點偵測
 * Difficulty: UVa Star 2
 * Tags: graph, tarjan, cut-vertices
 * URL: https://onlinejudge.org/external/101/10199.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find all camera locations (articulation points / cut-vertices) in a city graph whose removal disconnects locations.
 *
 * [中文] 題目說明:
 *     找出城市景點地圖中的所有關鍵關節點 (割點)，若該節點發生狀況則會阻斷其他景點間的通聯。
 *
 * [EN] Approach:
 *     Tarjan's cut-vertex algorithm: a root node is cut-vertex if it has >= 2 children; non-root node u is cut-vertex if child v has low[v] >= tin[u].
 * [中文] 思路:
 *     利用 Tarjan 演算法偵測圖中割點：根節點子樹個數 >= 2 或非根節點存在子節點 v 滿足 low[v] >= tin[u] 則為割點。
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

int tin_10199[20], low_10199[20], timer_10199;
int is_cut_10199[20];

void dfs_cut(int u, int p, int n, int adj[20][20]) {
    tin_10199[u] = low_10199[u] = ++timer_10199;
    int children = 0;
    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (v == p) continue;
            if (tin_10199[v]) {
                if (tin_10199[v] < low_10199[u]) low_10199[u] = tin_10199[v];
            } else {
                children++;
                dfs_cut(v, u, n, adj);
                if (low_10199[v] < low_10199[u]) low_10199[u] = low_10199[v];
                if (p != -1 && low_10199[v] >= tin_10199[u]) is_cut_10199[u] = 1;
            }
        }
    }
    if (p == -1 && children > 1) is_cut_10199[u] = 1;
}

int solve_uva10199(int n, int adj[20][20]) {
    timer_10199 = 0;
    for (int i = 0; i < n; i++) { tin_10199[i] = 0; is_cut_10199[i] = 0; }
    for (int i = 0; i < n; i++) if (!tin_10199[i]) dfs_cut(i, -1, n, adj);
    int cnt = 0;
    for (int i = 0; i < n; i++) if (is_cut_10199[i]) cnt++;
    return cnt;
}

int main(void) {

    int adj[20][20] = {0};
    adj[0][1] = adj[1][0] = 1; adj[1][2] = adj[2][1] = 1; // 0-1-2: 1 is cut
    int cnt = solve_uva10199(3, adj);
    int ok = (cnt == 1);
    printf("%s: UVa 10199 - Tourist Guide\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
