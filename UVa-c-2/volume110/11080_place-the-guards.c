/*
 * ==========================================================================
 * UVa 11080 - Place the Guards
 * Title-CN: 街道守衛二分圖二著色最小守衛數
 * Difficulty: UVa Star 2
 * Tags: graph, bipartite
 * URL: https://onlinejudge.org/external/110/11080.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Place minimum guards on intersections such that every street has at least one guard and no two guards share a street (Bipartite graph vertex cover).
 *
 * [中文] 題目概述:
 *     在街道交會點佈置最少數量的警衛，使得每條街均受到巡查且相鄰兩點不可同時設哨 (二分圖二著色最小頂點覆蓋)。
 *
 * [EN] Approach:
 *     Bipartite coloring using BFS/DFS. For each component, count color 0 and color 1. If not bipartite, return -1. Take sum(max(1, min(c0, c1))).
 * [中文] 解題思路:
 *     以 BFS 對每個連通分量進行黑白二著色：若出現同色衝突則無解回傳 -1；否則取 min(黑, 白) (獨立單點至少需 1 衛) 加總。
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

int solve_uva11080(int n, int adj[20][20]) {
    int color[20];
    for (int i = 0; i < n; i++) color[i] = -1;
    int total_guards = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            int q[20], head = 0, tail = 0;
            q[tail++] = i; color[i] = 0;
            int c0 = 1, c1 = 0;
            while (head < tail) {
                int u = q[head++];
                for (int v = 0; v < n; v++) {
                    if (adj[u][v]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            if (color[v] == 0) c0++; else c1++;
                            q[tail++] = v;
                        } else if (color[v] == color[u]) {
                            return -1; // not bipartite
                        }
                    }
                }
            }
            total_guards += (c1 == 0) ? 1 : (c0 < c1 ? c0 : c1);
        }
    }
    return total_guards;
}

int main(void) {

    int adj[20][20] = {0};
    adj[0][1] = adj[1][0] = 1;
    int g = solve_uva11080(2, adj);
    int ok = (g == 1);
    printf("%s: UVa 11080 - Place the Guards\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
