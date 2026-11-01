/*
 * ==========================================================================
 * UVa 11045 - My T-shirt suits me
 * Title-CN: 衣服尺碼分配 (二分圖最大匹配)
 * Difficulty: Medium
 * Tags: Bipartite Matching, Max Flow
 * URL: https://onlinejudge.org/external/110/11045.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Distribute N shirts equally among 6 sizes (N/6 each) to M volunteers who each accept 2 specific sizes.
 *
 * [中文] 題目說明:
 *     有 6 種尺寸的 T-shirt 共 N 件（每種尺寸 N/6 件），分配給 M 位志工（每位有 2 種合身尺寸），判定是否能全員滿足。
 *
 * [EN] Approach:
 *     Model as Maximum Bipartite Matching: create N/6 nodes for each size (or network flow), run matching for M volunteers.
 * [中文] 思路:
 *     二分圖匹配：將 6 種尺碼各自複製 N/6 份作為供給節點，對 M 名志工尋求最大二分匹配，判斷匹配數是否為 M。
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

bool dfs_tshirt(int u, int total_shirts, const int adj[30][30], int *match, bool *vis) {
    for (int v = 0; v < total_shirts; v++) {
        if (adj[u][v] && !vis[v]) {
            vis[v] = true;
            if (match[v] < 0 || dfs_tshirt(match[v], total_shirts, adj, match, vis)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
bool can_fit_volunteers(int n, int m, const int adj[30][30]) {
    int match[30];
    for (int i = 0; i < n; i++) match[i] = -1;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        bool vis[30] = {false};
        if (dfs_tshirt(i, n, adj, match, vis)) cnt++;
    }
    return cnt == m;
}

int main(void) {

    int adj[30][30] = {0};
    adj[0][0] = 1; adj[1][1] = 1;
    bool ok = can_fit_volunteers(2, 2, adj);
    printf("%s: UVa 11045 - My T-shirt suits me\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
