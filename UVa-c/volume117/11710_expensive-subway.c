/*
 * ==========================================================================
 * UVa 11710 - Expensive subway
 * Title-CN: 昂貴的地鐵 (最小生成樹連通性)
 * Difficulty: Medium
 * Tags: Graph, MST, Kruskal
 * URL: https://onlinejudge.org/external/117/11710.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine the minimum cost to build a subway network connecting all stations starting from a given home station, or report 'Impossible'.
 *
 * [中文] 題目說明:
 *     求連接所有地鐵站的最小修建成本，若無法連通所有站點則輸出 Impossible。
 *
 * [EN] Approach:
 *     Run Kruskal's algorithm. Check if total edges in MST equals n - 1. If yes, print total weight; otherwise impossible.
 * [中文] 思路:
 *     使用 Kruskal 演算法求最小生成樹，若選取的邊數恰好為 n - 1 則輸出總權重，否則不可達。
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

int find_subw(int *p, int x) { return p[x] == x ? x : (p[x] = find_subw(p, p[x])); }
int min_subway_cost(int n, int m, int edges[][3]) {
    int p[20];
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (edges[i][2] > edges[j][2]) {
                for (int k = 0; k < 3; k++) {
                    int t = edges[i][k]; edges[i][k] = edges[j][k]; edges[j][k] = t;
                }
            }
    int total = 0, added = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        int ru = find_subw(p, u), rv = find_subw(p, v);
        if (ru != rv) {
            p[ru] = rv;
            total += w;
            added++;
        }
    }
    return (added == n - 1) ? total : -1;
}

int main(void) {

    int e[3][3] = {{0, 1, 10}, {1, 2, 15}, {0, 2, 20}};
    int res = min_subway_cost(3, 3, e);
    int ok = (res == 25);
    printf("%s: UVa 11710 - Expensive subway\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
