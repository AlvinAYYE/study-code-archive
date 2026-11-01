/*
 * ==========================================================================
 * UVa 10278 - Fire Station
 * Title-CN: 消防局選址 (全源最短路徑重排)
 * Difficulty: Medium
 * Tags: Graph, Dijkstra, Floyd-Warshall
 * URL: https://onlinejudge.org/external/102/10278.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given existing fire stations and road network, find a new intersection to place an additional station to minimize maximum distance to nearest station.
 *
 * [中文] 題目說明:
 *     給定現有消防局與城鎮道路網，求新建一座消防局的最佳交叉口位置，使所有交叉口到最近消防局的最遠距離最小。
 *
 * [EN] Approach:
 *     Precompute all-pairs shortest paths. For each candidate node x, evaluate max_v(min(dist_to_existing[v], dist[x][v])).
 * [中文] 思路:
 *     計算全源最短路徑。枚舉新消防局候選點 x，求每點到新局與舊局距離的最小值，取全圖最大值最小的候選點。
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

int best_fire_station(int f_cnt, const int *stations, int n, const int dist[10][10]) {
    int best_node = 0, min_max_dist = 1000000;
    for (int x = 0; x < n; x++) {
        int cur_max = 0;
        for (int v = 0; v < n; v++) {
            int d = dist[x][v];
            for (int i = 0; i < f_cnt; i++) {
                int ds = dist[stations[i]][v];
                if (ds < d) d = ds;
            }
            if (d > cur_max) cur_max = d;
        }
        if (cur_max < min_max_dist) {
            min_max_dist = cur_max;
            best_node = x;
        }
    }
    return best_node + 1;
}

int main(void) {

    int st[] = {0};
    int dist[10][10] = {{0, 10}, {10, 0}};
    int b = best_fire_station(1, st, 2, dist);
    int ok = (b == 1 || b == 2);
    printf("%s: UVa 10278 - Fire Station\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
