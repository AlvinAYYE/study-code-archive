/*
 * ==========================================================================
 * UVa 11838 - Come and Go
 * Title-CN: 雙向通達街道全源強連通性驗證
 * Difficulty: UVa Star 2
 * Tags: graph, scc, tarjan
 * URL: https://onlinejudge.org/external/118/11838.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a directed street network is strongly connected (every intersection can reach every other intersection).
 *
 * [中文] 題目說明:
 *     判定給定單行道與雙向道街道網路是否為強連通圖 (即任意兩路口均可互相通達)。
 *
 * [EN] Approach:
 *     Tarjan's strongly connected components algorithm: graph is valid if and only if there is exactly 1 SCC containing all N nodes.
 * [中文] 思路:
 *     利用 Tarjan 演算法求強連通分量個數，全圖強連通的充要條件為恰好只有 1 個包含全部 N 個節點的 SCC。
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

int solve_uva11838_reach(int n, int adj[20][20]) {
    int reach[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) reach[i][j] = adj[i][j] || (i == j);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!reach[i][j]) return 0;
    return 1;
}

int main(void) {

    int adj[20][20] = {0};
    adj[0][1] = 1; adj[1][0] = 1;
    int ok = solve_uva11838_reach(2, adj);
    printf("%s: UVa 11838 - Come and Go\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
