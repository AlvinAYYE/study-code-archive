/*
 * ==========================================================================
 * UVa 10926 - How Many Dependencies?
 * Title-CN: 多少依賴項？ (有向圖可達節點計數)
 * Difficulty: Easy
 * Tags: Graph, DFS, Transitive Closure
 * URL: https://onlinejudge.org/external/109/10926.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the task in a dependency graph that has the maximum total number of dependencies (reachable nodes).
 *
 * [中文] 題目說明:
 *     求有向依賴圖中能夠抵達最多其他節點（依賴任務總數最多）的任務編號。
 *
 * [EN] Approach:
 *     Run DFS from each node 1 to n to count distinct reachable descendants. Pick the node with maximum reachable count.
 * [中文] 思路:
 *     從每個節點出發進行 DFS 遍歷，統計該節點可抵達的相異子節點總數，取計數最大且編號最小的節點。
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

int dfs_dep_count(int u, int n, const int adj[20][20], bool *vis) {
    vis[u] = true;
    int cnt = 0;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !vis[v]) {
            cnt += 1 + dfs_dep_count(v, n, adj, vis);
        }
    }
    return cnt;
}
int most_dependent_task(int n, const int adj[20][20]) {
    int max_c = -1, best = 0;
    for (int i = 0; i < n; i++) {
        bool vis[20] = {false};
        int c = dfs_dep_count(i, n, adj, vis);
        if (c > max_c) { max_c = c; best = i; }
    }
    return best + 1;
}

int main(void) {

    int adj[20][20] = {0};
    adj[0][1] = 1; adj[1][2] = 1; // 0 depends on 1 and 2
    int res = most_dependent_task(3, adj);
    int ok = (res == 1);
    printf("%s: UVa 10926 - How Many Dependencies?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
