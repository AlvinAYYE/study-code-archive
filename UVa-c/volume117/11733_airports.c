/*
 * ==========================================================================
 * UVa 11733 - Airports
 * Title-CN: 機場建設 (Kruskal帶閥值生成森林)
 * Difficulty: Medium
 * Tags: Graph, MST, Kruskal
 * URL: https://onlinejudge.org/external/117/11733.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given costs of building roads between cities and building an airport (cost A), find minimum total cost to make every city accessible to an airport.
 *
 * [中文] 題目說明:
 *     修建公路與建造機場（費用 A），使每座城市都能連通到至少一座機場，求最小成本與機場座數。
 *
 * [EN] Approach:
 *     Run Kruskal's MST. Only add road edges if cost < A. Every remaining connected component must build an airport.
 * [中文] 思路:
 *     以 Kruskal 演算法求生成森林：僅選取建路費用嚴格小於機場費用 A 的邊，其餘獨立連通分量各自建造一座機場。
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

int kruskal_find_ap(int *p, int x) { return p[x] == x ? x : (p[x] = kruskal_find_ap(p, p[x])); }
void solve_airports(int n, int a_cost, int m, int edges[][3], int *total_cost, int *airports) {
    int p[20];
    for (int i = 1; i <= n; i++) p[i] = i;
    // Sort edges by cost
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (edges[i][2] > edges[j][2]) {
                for (int k = 0; k < 3; k++) {
                    int t = edges[i][k]; edges[i][k] = edges[j][k]; edges[j][k] = t;
                }
            }
    int roads_cost = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        if (w >= a_cost) break;
        int ru = kruskal_find_ap(p, u), rv = kruskal_find_ap(p, v);
        if (ru != rv) {
            p[ru] = rv;
            roads_cost += w;
        }
    }
    int comps = 0;
    for (int i = 1; i <= n; i++) if (p[i] == i) comps++;
    *airports = comps;
    *total_cost = roads_cost + comps * a_cost;
}

int main(void) {

    int edges[2][3] = {{1, 2, 10}, {2, 3, 20}};
    int cost, aps;
    solve_airports(3, 15, 2, edges, &cost, &aps); // edge (1,2) taken (10), (2,3) rejected (20>=15) -> 2 airports
    int ok = (aps == 2 && cost == 10 + 2*15);
    printf("%s: UVa 11733 - Airports\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
