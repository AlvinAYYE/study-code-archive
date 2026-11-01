/*
 * ==========================================================================
 * UVa 10369 - Arctic Network
 * Title-CN: 北極哨所衛星通訊半徑二分生成樹
 * Difficulty: UVa Star 2
 * Tags: graph, mst, kruskal
 * URL: https://onlinejudge.org/external/103/10369.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given S satellite channels and P outposts, find minimum transceiver power D such that all outposts can communicate.
 *
 * [中文] 題目說明:
 *     給定 S 個衛星頻道與 P 個北極哨所座標，配置無線電收發器使其覆蓋半徑 D 最小且全哨所皆能彼此連通。
 *
 * [EN] Approach:
 *     Compute MST of all P outposts. S satellite channels can connect S largest components, so D is the weight of the (P - S)-th edge in the sorted MST edge list.
 * [中文] 思路:
 *     構建哨所間的最小生成樹 (MST)，由於 S 個衛星站可省去 (S - 1) 條最長邊，所需最小半徑即為 MST 中第 (P - S) 條邊之權重。
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

double solve_uva10369_select(double *mst_edges, int edge_cnt, int s, int p) {
    int idx = p - s - 1;
    if (idx < 0) return 0.0;
    return mst_edges[idx];
}

int main(void) {

    double e[] = {1.0, 2.5, 4.0};
    double d = solve_uva10369_select(e, 3, 2, 4); // idx = 4-2-1 = 1 -> 2.5
    int ok = (fabs(d - 2.5) < 1e-4);
    printf("%s: UVa 10369 - Arctic Network\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
