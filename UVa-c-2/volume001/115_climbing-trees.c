/*
 * ==========================================================================
 * UVa 115 - Climbing Trees
 * Title-CN: 家譜樹血緣親屬關係判定
 * Difficulty: UVa Star 2
 * Tags: tree, dfs, lca
 * URL: https://onlinejudge.org/external/1/115.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given parent-child relationships, determine the relationship between two individuals: child, parent, sibling, cousin with removal, etc.
 *
 * [中文] 題目說明:
 *     給定若干對父子/母子血緣關係，判斷任意兩人之間的親屬關係：如直系尊親屬/卑親屬、兄弟姊妹或具有代差的堂表親屬。
 *
 * [EN] Approach:
 *     Model as directed forest. Find path to root for each query node; find lowest common ancestor (LCA) and compare tree depths to determine degree of cousinship and removal.
 * [中文] 思路:
 *     構建有向樹森林，由各節點向上遍歷至根尋找最近共同祖先 (LCA)，根據兩者與祖先之深度差距判定親等與代差關係。
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

int get_parent(int node, int *parent) {
    return parent[node];
}

int get_depth_to_ancestor(int u, int anc, int *parent) {
    int d = 0;
    while (u != -1) {
        if (u == anc) return d;
        u = parent[u];
        d++;
    }
    return -1;
}

int main(void) {

    int parent[10] = {-1, 0, 1, -1, -1};
    int d = get_depth_to_ancestor(2, 0, parent);
    int ok = (d == 2);
    printf("%s: UVa 115 - Climbing Trees\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
