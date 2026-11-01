/*
 * ==========================================================================
 * UVa 10959 - The Party, Part I
 * Title-CN: 舞會派對 I (吉奧瓦尼號數 / 廣度優先搜尋)
 * Difficulty: Easy
 * Tags: Graph, BFS, Shortest Path
 * URL: https://onlinejudge.org/external/109/10959.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the Giovanni number (shortest distance from host 0) for every guest at a ballroom dance party.
 *
 * [中文] 題目說明:
 *     求舞會派對中每位客人與主持人 0 號的最短舞伴距離（吉奧瓦尼號數）。
 *
 * [EN] Approach:
 *     Standard BFS starting from host 0 on an unweighted undirected graph.
 * [中文] 思路:
 *     以 0 號主持人為起點進行無權圖 BFS，求每個節點的最短距離。
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

void giovanni_numbers(int p, int d, const int pairs[][2], int *dist) {
    int adj[20][20] = {0};
    for (int i = 0; i < d; i++) {
        adj[pairs[i][0]][pairs[i][1]] = adj[pairs[i][1]][pairs[i][0]] = 1;
    }
    for (int i = 0; i < p; i++) dist[i] = -1;
    dist[0] = 0;
    int q[20], head = 0, tail = 0;
    q[tail++] = 0;
    while (head < tail) {
        int u = q[head++];
        for (int v = 0; v < p; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q[tail++] = v;
            }
        }
    }
}

int main(void) {

    int pairs[3][2] = {{0, 1}, {1, 2}, {2, 3}};
    int dist[4];
    giovanni_numbers(4, 3, pairs, dist);
    int ok = (dist[1] == 1 && dist[2] == 2 && dist[3] == 3);
    printf("%s: UVa 10959 - The Party, Part I\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
