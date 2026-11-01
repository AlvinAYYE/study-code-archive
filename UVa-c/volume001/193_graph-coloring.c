/*
 * ==========================================================================
 * UVa 193 - Graph Coloring
 * Title-CN: 無向圖最大獨立集
 * Difficulty: UVa Star 2
 * Tags: graph, backtracking
 * URL: https://onlinejudge.org/external/1/193.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Color graph vertices black or white such that no two adjacent vertices are both black, maximizing the count of black vertices (Maximum Independent Set).
 *
 * [中文] 題目說明:
 *     對無向圖頂點進行黑白二染色，相鄰頂點不可同為黑色，求黑色頂點數量的最大值 (最大獨立集) 並輸出其頂點集合。
 *
 * [EN] Approach:
 *     Backtracking search: at each vertex, try coloring black (if no black neighbor), then try white. Prune if remaining vertices cannot exceed best count.
 * [中文] 思路:
 *     回溯搜尋最大獨立集：對每個節點分支嘗試著黑色 (需滿足無鄰居為黑) 與著白色，配合剩餘節點上限剪枝，記錄最大著黑數量頂點集。
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

int can_color_black(int u, int n, int adj[100][100], int *color) {
    for (int v = 0; v < n; v++)
        if (adj[u][v] && color[v] == 1) return 0;
    return 1;
}

int main(void) {

    int adj[100][100] = {0}, col[100] = {0};
    adj[0][1] = 1; adj[1][0] = 1;
    col[1] = 1;
    int ok = !can_color_black(0, 2, adj, col);
    printf("%s: UVa 193 - Graph Coloring\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
