/*
 * ==========================================================================
 * UVa 615 - Is It A Tree?
 * Title-CN: 這是一棵樹嗎？
 * Difficulty: Medium
 * Tags: Graph, Tree Verification
 * URL: https://onlinejudge.org/external/6/615.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a given directed graph is a rooted tree (exactly one root with in-degree 0, every other node in-degree 1, connected).
 *
 * [中文] 題目概述:
 *     判斷給定的有向圖是否為一棵有根樹（恰好一個入度為 0 的根節點，其餘節點入度均為 1，且連通無環）。
 *
 * [EN] Approach:
 *     Check: 0 or 1 edge empty tree is valid. Max in-degree <= 1. Exactly one node with in-degree 0. Total edges == total nodes - 1.
 * [中文] 解題思路:
 *     空圖為樹；檢查每個節點入度不可超過 1；恰好有一個入度為 0 的根節點；邊數必等於節點數減 1 且全圖連通。
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

bool is_tree(int num_nodes, int num_edges, const int in_degree[100]) {
    if (num_nodes == 0 && num_edges == 0) return true;
    if (num_edges != num_nodes - 1) return false;
    int root_count = 0;
    for (int i = 1; i <= num_nodes; i++) {
        if (in_degree[i] == 0) root_count++;
        if (in_degree[i] > 1) return false;
    }
    return root_count == 1;
}

int main(void) {

    int in_deg[10] = {0, 0, 1, 1}; // node 1 is root, 2 and 3 in-degree 1
    int ok = is_tree(3, 2, in_deg);
    printf("%s: UVa 615 - Is It A Tree?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
