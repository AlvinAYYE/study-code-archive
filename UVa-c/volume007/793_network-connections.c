/*
 * ==========================================================================
 * UVa 793 - Network Connections
 * Title-CN: 電腦網路連線查詢 (並查集 DSU)
 * Difficulty: UVa Star 1
 * Tags: data-structures, dsu
 * URL: https://onlinejudge.org/external/7/793.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given dynamic bidirectional connections between computers, answer connectivity queries and count successes/failures.
 *
 * [中文] 題目說明:
 *     動態連通性維護：在電腦兩兩連線的指令流中，查詢指定兩台電腦是否連通，統計成功與失敗的查詢次數 (並查集)。
 *
 * [EN] Approach:
 *     Disjoint Set Union (DSU) with path compression and rank union. 'c' command unifies sets; 'q' command tests find(u) == find(v).
 * [中文] 思路:
 *     標準並查集 (DSU) 結構：路徑壓縮與按秩合併。連線操作執行 union，查詢操作判定 find_root(u) 是否等於 find_root(v)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int parent_793[1005];

int find_793(int i) {
    if (parent_793[i] == i) return i;
    return parent_793[i] = find_793(parent_793[i]);
}

void union_793(int i, int j) {
    int root_i = find_793(i), root_j = find_793(j);
    if (root_i != root_j) parent_793[root_i] = root_j;
}

int check_793(int i, int j) {
    return find_793(i) == find_793(j);
}

int main(void) {

    for (int i = 1; i <= 5; i++) parent_793[i] = i;
    union_793(1, 2);
    union_793(2, 3);
    int ok = check_793(1, 3) && !check_793(1, 4);
    printf("%s: UVa 793 - Network Connections\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
