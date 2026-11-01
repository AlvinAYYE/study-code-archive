/*
 * ==========================================================================
 * UVa 301 - Transportation
 * Title-CN: 客運訂單最大收益 (回溯搜索剪枝)
 * Difficulty: Medium
 * Tags: Backtracking, DFS, Pruning
 * URL: https://onlinejudge.org/external/3/301.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A train of capacity B travels stations 0..B. Choose subset of passenger orders to maximize ticket revenue without exceeding capacity.
 *
 * [中文] 題目說明:
 *     容量為 B 的列車沿 0 到 B 站行駛，從眾多客運訂單中選取子集使得各站乘客數均不超載，並最大化總客票收入。
 *
 * [EN] Approach:
 *     DFS backtrack over orders: either accept order (if all stations along [start, end) have remaining capacity >= passengers) or reject it. Branch and bound pruning.
 * [中文] 思路:
 *     對各訂單進行回溯決策（選或不選）：選取時扣減沿途各區間容量，若後續剩餘所有訂單價值全加仍不超過已知最優解則強力剪枝。
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

void dfs_train(int order_idx, int m, int n, int cap, const int orders[][3], int *load, int cur_rev, int *max_rev) {
    if (order_idx == m) {
        if (cur_rev > *max_rev) *max_rev = cur_rev;
        return;
    }
    int u = orders[order_idx][0], v = orders[order_idx][1], p = orders[order_idx][2];
    int fare = (v - u) * p;
    // Try accept
    bool can_take = true;
    for (int i = u; i < v; i++) {
        if (load[i] + p > cap) { can_take = false; break; }
    }
    if (can_take) {
        for (int i = u; i < v; i++) load[i] += p;
        dfs_train(order_idx + 1, m, n, cap, orders, load, cur_rev + fare, max_rev);
        for (int i = u; i < v; i++) load[i] -= p;
    }
    // Try reject
    dfs_train(order_idx + 1, m, n, cap, orders, load, cur_rev, max_rev);
}
int max_train_revenue(int cap, int n, int m, const int orders[][3]) {
    int load[15] = {0};
    int max_r = 0;
    dfs_train(0, m, n, cap, orders, load, 0, &max_r);
    return max_r;
}

int main(void) {

    int ord[2][3] = {{0, 2, 5}, {1, 3, 5}}; // cap 5
    int rev = max_train_revenue(5, 3, 2, ord); // overlapping at [1,2], can only take one
    int ok = (rev == 10);
    printf("%s: UVa 301 - Transportation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
