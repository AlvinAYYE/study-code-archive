/*
 * ==========================================================================
 * UVa 11463 - Commandos
 * Title-CN: 突擊隊
 * Difficulty: Medium
 * Tags: Graph, Floyd-Warshall, Shortest Path
 * URL: https://onlinejudge.org/external/114/11463.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum time for commandos starting at s to visit all buildings and gather at destination d.
 *
 * [中文] 題目概述:
 *     突擊隊員從起點 s 出發炸毀所有建築物後在終點 d 集合，求所有人完成任務並會合的最短時間。
 *
 * [EN] Approach:
 *     All-pairs shortest path with Floyd-Warshall. Maximize (dist[s][i] + dist[i][d]) over all nodes i.
 * [中文] 解題思路:
 *     使用 Floyd-Warshall 求全源最短路徑，遍歷所有中間節點 i，求 max(dist[s][i] + dist[i][d])。
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

int min_commando_time(int n, int dist[10][10], int s, int d) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    int max_time = 0;
    for (int i = 0; i < n; i++) {
        if (dist[s][i] + dist[i][d] > max_time)
            max_time = dist[s][i] + dist[i][d];
    }
    return max_time;
}

int main(void) {

    int dist[10][10];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) dist[i][j] = (i == j ? 0 : 100);
    dist[0][1] = dist[1][0] = 1;
    dist[1][2] = dist[2][1] = 1;
    dist[2][3] = dist[3][2] = 1;
    int ok = (min_commando_time(4, dist, 0, 3) == 3);
    printf("%s: UVa 11463 - Commandos\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
