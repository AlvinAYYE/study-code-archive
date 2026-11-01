/*
 * ==========================================================================
 * UVa 459 - Graph Connectivity
 * Title-CN: 無向圖連通分量計數
 * Difficulty: UVa Star 2
 * Tags: graph, dsu, dfs
 * URL: https://onlinejudge.org/external/4/459.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given maximal node label up to 'Z' and list of undirected edges, find the number of connected components in the graph.
 *
 * [中文] 題目說明:
 *     給定圖中最大節點標籤 (至多為 'Z') 與無向邊列表，計算圖中連通分量的個數。
 *
 * [EN] Approach:
 *     Disjoint-Set Union (DSU): initialize N disjoint sets, union endpoints for each edge, count distinct root representatives.
 * [中文] 思路:
 *     使用並查集 (DSU) 維護連通關係：將每條邊兩端點合併，最後統計相異集合代表元之總數。
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

int dsu_find(int *parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = dsu_find(parent, parent[i]);
}

void dsu_union(int *parent, int i, int j) {
    int r1 = dsu_find(parent, i);
    int r2 = dsu_find(parent, j);
    if (r1 != r2) parent[r1] = r2;
}

int solve_uva459(char max_node, int num_edges, char edges[][3]) {
    int n = max_node - 'A' + 1;
    int parent[26];
    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < num_edges; i++) {
        dsu_union(parent, edges[i][0] - 'A', edges[i][1] - 'A');
    }
    int comps = 0;
    for (int i = 0; i < n; i++) {
        if (dsu_find(parent, i) == i) comps++;
    }
    return comps;
}

int main(void) {

    char edges[2][3] = {"AB", "CD"};
    int ans = solve_uva459('E', 2, edges);
    int ok = (ans == 3); // {A,B}, {C,D}, {E}
    printf("%s: UVa 459 - Graph Connectivity\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
