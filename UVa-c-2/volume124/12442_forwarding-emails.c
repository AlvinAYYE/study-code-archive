/*
 * ==========================================================================
 * UVa 12442 - Forwarding Emails
 * Title-CN: 轉寄電子郵件
 * Difficulty: Medium
 * Tags: Graph, DFS, Strongly Connected Components
 * URL: https://onlinejudge.org/external/124/12442.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Each person forwards email to exactly one other person. Find the person who can reach the maximum number of recipients.
 *
 * [中文] 題目概述:
 *     每個人都只會將郵件轉寄給特定一人，求誰發起郵件能傳遞給最多的人。
 *
 * [EN] Approach:
 *     Since each node has out-degree 1, the graph is a collection of functional graphs (trees rooted on cycles). Use DFS with memoization.
 * [中文] 解題思路:
 *     每個節點出度皆為 1，全圖由基環樹森林構成。使用帶記憶化的 DFS 計算每個點可抵達的節點數。
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

int dfs_reach(int u, const int *next, int *vis, int *memo) {
    vis[u] = 1;
    int v = next[u];
    int count = 0;
    if (v != -1 && !vis[v]) count = 1 + dfs_reach(v, next, vis, memo);
    vis[u] = 0;
    return memo[u] = count;
}
int best_email_starter(int n, const int *next) {
    int max_r = -1, best = 0;
    int vis[100] = {0}, memo[100];
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; i++) {
        int r = dfs_reach(i, next, vis, memo);
        if (r > max_r) { max_r = r; best = i; }
    }
    return best;
}

int main(void) {

    int nxt[] = {1, 2, 0}; // 0->1->2->0
    int best = best_email_starter(3, nxt);
    int ok = (best == 0 || best == 1 || best == 2);
    printf("%s: UVa 12442 - Forwarding Emails\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
