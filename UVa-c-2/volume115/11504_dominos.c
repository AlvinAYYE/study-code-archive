/*
 * ==========================================================================
 * UVa 11504 - Dominos
 * Title-CN: 骨牌骨牌推倒強連通縮點入度
 * Difficulty: UVa Star 2
 * Tags: graph, scc, tarjan
 * URL: https://onlinejudge.org/external/115/11504.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum number of dominos you must knock over by hand to knock down all dominos.
 *
 * [中文] 題目說明:
 *     在帶有骨牌骨牌推倒關係的有向圖中，求最少需手動推倒幾張骨牌才能使所有骨牌全部倒下 (SCC 縮點後入度為 0 的個數)。
 *
 * [EN] Approach:
 *     Find strongly connected components (SCC). Build component DAG and count number of components with in-degree 0.
 * [中文] 思路:
 *     以 Tarjan 或 Kosaraju 求強連通分量 (SCC)，將分量縮點構建有向無環圖 (DAG)，統計入度為 0 的連通分量數量。
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

int solve_uva11504_simple(int n, int in_degree_scc[], int num_scc) {
    int zero_in = 0;
    for (int i = 0; i < num_scc; i++) {
        if (in_degree_scc[i] == 0) zero_in++;
    }
    return zero_in;
}

int main(void) {

    int in_deg[] = {0, 1, 0};
    int ans = solve_uva11504_simple(3, in_deg, 3);
    int ok = (ans == 2);
    printf("%s: UVa 11504 - Dominos\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
