/*
 * ==========================================================================
 * UVa 11015 - 05-2 Rendezvous
 * Title-CN: 聚會地點選址 (全源最短路徑中心點)
 * Difficulty: Easy
 * Tags: Graph, Floyd-Warshall
 * URL: https://onlinejudge.org/external/110/11015.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the person's location to hold a rendezvous party such that the sum of travel distances of all friends is minimized.
 *
 * [中文] 題目說明:
 *     求使所有朋友前往集合地點的總路程之和最小的聚會成員所在位置。
 *
 * [EN] Approach:
 *     Floyd-Warshall all-pairs shortest path. Compute sum of distances from all friends to each candidate location, pick minimum.
 * [中文] 思路:
 *     以 Floyd-Warshall 演算法求全源最短路徑，計算各候選點到所有其他點的最短距離總和，取總和最小者。
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

int rendezvous_node(int n, int dist[25][25]) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    int best_node = 0, min_total = 10000000;
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < n; j++) total += dist[i][j];
        if (total < min_total) { min_total = total; best_node = i; }
    }
    return best_node;
}

int main(void) {

    int d[25][25];
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) d[i][j] = (i == j ? 0 : 10);
    d[0][1] = d[1][0] = 1;
    d[1][2] = d[2][1] = 1;
    // node 1: d=1+1=2, node 0: 1+2=3, node 2: 1+2=3 -> node 1 is best
    int b = rendezvous_node(3, d);
    int ok = (b == 1);
    printf("%s: UVa 11015 - 05-2 Rendezvous\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
