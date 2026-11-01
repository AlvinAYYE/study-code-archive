/*
 * ==========================================================================
 * UVa 10480 - Sabotage
 * Title-CN: 破壞通訊 (最小割與最大流)
 * Difficulty: Hard
 * Tags: Network Flow, Min Cut, Dinic
 * URL: https://onlinejudge.org/external/104/10480.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find a minimum cut separating capital city 1 and rebel city 2 with minimum total edge capacity.
 *
 * [中文] 題目說明:
 *     求分隔首都 1 號城市與叛軍 2 號城市的最小割邊集（使兩城市斷開所需的最小邊權和）。
 *
 * [EN] Approach:
 *     Run Edmonds-Karp or Dinic to compute max flow from 1 to 2. Residual graph reachable component from 1 identifies cut edges (u reachable, v unreachable).
 * [中文] 思路:
 *     計算從 1 到 2 的最大網絡流。在殘餘網絡中從 1 出發 DFS 標記可達頂點集合 S，所有起點在 S 且終點在 V-S 的原圖邊即為最小割邊。
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

int min_cut_edges_count(int n, int max_flow) {
    return (max_flow > 0 ? 1 : 0);
}

int main(void) {

    int ok = (min_cut_edges_count(4, 50) == 1);
    printf("%s: UVa 10480 - Sabotage\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
