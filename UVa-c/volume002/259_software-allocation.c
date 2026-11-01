/*
 * ==========================================================================
 * UVa 259 - Software Allocation
 * Title-CN: 軟體安裝分配 (二分圖最大匹配/最大流)
 * Difficulty: Hard
 * Tags: Network Flow, Max Bipartite Matching
 * URL: https://onlinejudge.org/external/2/259.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Allocate applications requiring specific numbers of users to 10 computer terminals (0-9) according to compatibility.
 *
 * [中文] 題目說明:
 *     將各應用程式分配給 10 台電腦終端機 (0~9) 運行，每台終端機只能運行一個程式，求完全分配方案。
 *
 * [EN] Approach:
 *     Bipartite matching between application instances and computers. Total applications must equal total matches (max flow = sum of requirements).
 * [中文] 思路:
 *     應用程式實例與 10 台電腦之間的二分圖最大匹配（或最大流），檢驗最大流是否等於所有應用程式需求總數。
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

bool dfs_alloc(int u, int n_c, const int adj[30][10], int *match, bool *vis) {
    for (int v = 0; v < n_c; v++) {
        if (adj[u][v] && !vis[v]) {
            vis[v] = true;
            if (match[v] < 0 || dfs_alloc(match[v], n_c, adj, match, vis)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int allocate_software(int total_apps, const int adj[30][10], int *match) {
    for (int i = 0; i < 10; i++) match[i] = -1;
    int cnt = 0;
    for (int i = 0; i < total_apps; i++) {
        bool vis[10] = {false};
        if (dfs_alloc(i, 10, adj, match, vis)) cnt++;
    }
    return cnt;
}

int main(void) {

    int adj[30][10] = {0};
    adj[0][0] = 1; adj[1][1] = 1;
    int m[10];
    int cnt = allocate_software(2, adj, m);
    int ok = (cnt == 2 && m[0] == 0 && m[1] == 1);
    printf("%s: UVa 259 - Software Allocation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
