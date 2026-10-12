/*
 * ==========================================================================
 * UVa 10000 - Longest Paths
 * Title-CN: 最長路徑 (DAG 最長路)
 * Difficulty: UVa Star 2
 * Tags: graph, dag, dynamic-programming, longest-path
 * URL: https://onlinejudge.org/external/100/10000.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a directed acyclic graph (DAG) and a starting node S, find the longest path length
 *     and the ending node with the smallest index if tied.
 *
 * [中文] 題目說明:
 *     給定一個有向無環圖（DAG）與起點 S，求從 S 出發的最長路徑長度，以及到達的終點編號
 *     （若有多個終點長度相同，取編號最小者）。
 *
 * [EN] Approach:
 *     Bellman-Ford / DP on DAG (memoized DFS). State dp[u]: longest path from u.
 * [中文] 思路:
 *     記憶化搜尋 / 動態規劃求解 DAG 最長路徑。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int adj[105][105], deg[105];
int memo_len[105], memo_dest[105];

void dfs(int u) {
    if (memo_len[u] != -1) return;
    int max_l = 0, best_d = u;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        dfs(v);
        if (memo_len[v] + 1 > max_l) {
            max_l = memo_len[v] + 1;
            best_d = memo_dest[v];
        } else if (memo_len[v] + 1 == max_l && memo_dest[v] < best_d) {
            best_d = memo_dest[v];
        }
    }
    memo_len[u] = max_l;
    memo_dest[u] = best_d;
}

void solve_uva10000(int start, int *len, int *dest) {
    memset(memo_len, -1, sizeof(memo_len));
    dfs(start);
    *len = memo_len[start];
    *dest = memo_dest[start];
}

int main(void) {
    deg[1] = 2; adj[1][0] = 2; adj[1][1] = 3;
    deg[2] = 1; adj[2][0] = 4;
    deg[3] = 1; adj[3][0] = 4;
    deg[4] = 0;
    int l, d;
    solve_uva10000(1, &l, &d);
    int ok = (l == 2 && d == 4);
    printf("%s: UVa 10000 - Longest Paths\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
