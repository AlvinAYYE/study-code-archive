/*
 * ==========================================================================
 * UVa 11597 - Spanning Subtree
 * Title-CN: 生成子樹 (完全圖的邊不相交生成樹數量)
 * Difficulty: Easy
 * Tags: Math, Graph Theory
 * URL: https://onlinejudge.org/external/115/11597.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum number of edge-disjoint spanning trees in a complete graph K_n.
 *
 * [中文] 題目說明:
 *     求在 n 個頂點的完全圖 K_n 中，最多可以包含多少個邊不相交的生成樹。
 *
 * [EN] Approach:
 *     A complete graph K_n has n*(n-1)/2 edges. Each spanning tree has n-1 edges. Max edge-disjoint spanning trees = (n*(n-1)/2) / (n-1) = n / 2.
 * [中文] 思路:
 *     完全圖共有 n*(n-1)/2 條邊，每棵生成樹需 n-1 條邊，故最多有 floor(n / 2) 棵邊不相交生成樹。
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

int max_edge_disjoint_trees(int n) {
    return n / 2;
}

int main(void) {

    int ok = (max_edge_disjoint_trees(4) == 2) && (max_edge_disjoint_trees(5) == 2);
    printf("%s: UVa 11597 - Spanning Subtree\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
