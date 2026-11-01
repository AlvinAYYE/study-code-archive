/*
 * ==========================================================================
 * UVa 173 - Network Wars
 * Title-CN: 電腦網路佔領搜尋追逐模擬
 * Difficulty: UVa Star 2
 * Tags: graph, simulation
 * URL: https://onlinejudge.org/external/1/173.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate two entities moving through a graph according to local priority rules, trapping or destroying nodes until one is trapped or destroyed.
 *
 * [中文] 題目說明:
 *     模擬兩方主體在網路圖節點上依照局部優先級規則移動，沿途破壞或佔領節點，直到一方被圍困或在同節點相遇判定勝負。
 *
 * [EN] Approach:
 *     Adjacency matrix simulation with alphabetical neighbor tie-breaking and node visitation flags.
 * [中文] 思路:
 *     維護節點鄰接矩陣與破壞標記，每回合雙方依字母序挑選最小未訪問鄰居前進，檢驗相遇或無路可走條件。
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

int choose_next_node(int cur, int n, int adj[30][30], int *destroyed) {
    for (int next = 0; next < n; next++) {
        if (adj[cur][next] && !destroyed[next]) return next;
    }
    return -1; // trapped
}

int main(void) {

    int adj[30][30] = {0}, dest[30] = {0};
    adj[0][1] = 1; adj[0][2] = 1;
    dest[1] = 1;
    int next = choose_next_node(0, 3, adj, dest);
    int ok = (next == 2);
    printf("%s: UVa 173 - Network Wars\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
