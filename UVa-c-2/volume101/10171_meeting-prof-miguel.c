/*
 * ==========================================================================
 * UVa 10171 - Meeting Prof. Miguel...
 * Title-CN: 會見米格爾教授 (分年齡最短路徑與會面點)
 * Difficulty: Medium
 * Tags: Graph, Floyd-Warshall, Shortest Path
 * URL: https://onlinejudge.org/external/101/10171.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Young man and old Miguel want to meet at a place where the sum of their travel costs is minimized. Young people and mature people can only use respective street networks.
 *
 * [中文] 題目說明:
 *     年輕人與年長教授各有一套可通行的街道系統，求使兩人前往會合地點的總路費最小的會面節點。
 *
 * [EN] Approach:
 *     Run Floyd-Warshall independently on Young graph and Mature graph. Find node k minimizing dist_young[src1][k] + dist_mature[src2][k].
 * [中文] 思路:
 *     分別對年輕人與老年人的街道圖跑 Floyd-Warshall 全源最短路徑，枚舉所有節點 k 求兩者距離和最小值。
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

int find_meeting_point(int n, int dy[26][26], int dm[26][26], int y_start, int m_start, int *best_node) {
    int min_cost = 10000000;
    *best_node = -1;
    for (int i = 0; i < n; i++) {
        if (dy[y_start][i] < 1000000 && dm[m_start][i] < 1000000) {
            int cost = dy[y_start][i] + dm[m_start][i];
            if (cost < min_cost) {
                min_cost = cost;
                *best_node = i;
            }
        }
    }
    return min_cost;
}

int main(void) {

    int dy[26][26], dm[26][26];
    for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) dy[i][j] = dm[i][j] = (i == j ? 0 : 1000000);
    dy[0][1] = 10; dm[2][1] = 20; // meet at node 1
    int node;
    int cost = find_meeting_point(3, dy, dm, 0, 2, &node);
    int ok = (cost == 30 && node == 1);
    printf("%s: UVa 10171 - Meeting Prof. Miguel...\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
