/*
 * ==========================================================================
 * UVa 10080 - Gopher II
 * Title-CN: 地鼠進洞 II
 * Difficulty: Medium
 * Tags: Graph, Bipartite Matching, Max Flow
 * URL: https://onlinejudge.org/external/100/10080.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum number of gophers that can be caught by a hawk before reaching gopher holes within time limit.
 *
 * [中文] 題目說明:
 *     在老鷹捕食前，每隻地鼠在時間限制內只能進入距離允許的洞，求最少會被抓幾隻地鼠（即總地鼠數減去最大二分匹配數）。
 *
 * [EN] Approach:
 *     Model as Maximum Bipartite Matching between gophers and holes where edge exists if dist <= s * v. Answer = n - max_matching.
 * [中文] 思路:
 *     以匈牙利演算法求地鼠與洞穴的最大二分圖匹配，答案即為地鼠總數減去最大匹配數。
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

bool dfs_match(int u, int m, const int adj[10][10], int *match, bool *vis) {
    for (int v = 0; v < m; v++) {
        if (adj[u][v] && !vis[v]) {
            vis[v] = true;
            if (match[v] < 0 || dfs_match(match[v], m, adj, match, vis)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int vulnerable_gophers(int n, int m, const int adj[10][10]) {
    int match[10];
    for (int i = 0; i < m; i++) match[i] = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool vis[10] = {false};
        if (dfs_match(i, m, adj, match, vis)) cnt++;
    }
    return n - cnt;
}

int main(void) {

    int adj[10][10] = {{1, 0}, {1, 1}};
    int ok = (vulnerable_gophers(2, 2, adj) == 0);
    printf("%s: UVa 10080 - Gopher II\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
