/*
 * ==========================================================================
 * UVa 247 - Calling Circles
 * Title-CN: 電話通話社交圈強連通分量
 * Difficulty: UVa Star 2
 * Tags: graph, scc, tarjan
 * URL: https://onlinejudge.org/external/2/247.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given directed phone call logs between individuals, find all calling circles (strongly connected components where everyone can call everyone).
 *
 * [中文] 題目說明:
 *     給定電話通話紀錄形成的有向圖，找出所有可互相輾轉通話的「社交通話圈」(即強連通分量 SCC)。
 *
 * [EN] Approach:
 *     Warshall's transitive closure or Tarjan's SCC algorithm. Two nodes u, v belong to the same circle if reach[u][v] and reach[v][u].
 * [中文] 思路:
 *     利用 Floyd-Warshall 求全源傳遞閉包，若節點 u 與 v 雙向可達 (reach[u][v] && reach[v][u]) 則歸入同一個通話圈。
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

void solve_uva247(int n, int adj[20][20], int circle_id[20]) {
    int reach[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) reach[i][j] = adj[i][j] || (i == j);
        circle_id[i] = -1;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

    int cid = 0;
    for (int i = 0; i < n; i++) {
        if (circle_id[i] == -1) {
            circle_id[i] = cid;
            for (int j = i + 1; j < n; j++) {
                if (reach[i][j] && reach[j][i]) circle_id[j] = cid;
            }
            cid++;
        }
    }
}

int main(void) {

    int adj[20][20] = {0}, cid[20];
    adj[0][1] = 1; adj[1][0] = 1; // 0 and 1 call each other
    adj[2][2] = 1;
    solve_uva247(3, adj, cid);
    int ok = (cid[0] == cid[1] && cid[0] != cid[2]);
    printf("%s: UVa 247 - Calling Circles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
