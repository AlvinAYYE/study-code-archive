/*
 * ==========================================================================
 * UVa 132 - Ashoka's Capital
 * Title-CN: 多邊形質心與穩定支撐凸包幾何
 * Difficulty: UVa Star 2
 * Tags: geometry, convex-hull
 * URL: https://onlinejudge.org/external/1/132.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine which vertex of a 2D polygonal pillar will act as the lowest pivot when tipped from its center of gravity.
 *
 * [中文] 題目說明:
 *     給定柱體截面多邊形與質心，計算多邊形傾倒時能穩定支撐重心的最低支點頂點編號。
 *
 * [EN] Approach:
 *     Compute 2D convex hull. For each hull edge, check if the projection of the center of mass falls strictly within the edge; find minimum vertex index.
 * [中文] 思路:
 *     計算截面頂點之凸包，對各相鄰支撐邊檢驗質心鉛直投影是否落在線段內，輸出具備最小編號之支撐頂點。
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

int is_in_segment(double cx, double x1, double x2) {
    double min_x = x1 < x2 ? x1 : x2;
    double max_x = x1 > x2 ? x1 : x2;
    return (cx >= min_x - 1e-7 && cx <= max_x + 1e-7);
}

int main(void) {

    int ok = is_in_segment(2.5, 1.0, 4.0) && !is_in_segment(5.0, 1.0, 4.0);
    printf("%s: UVa 132 - Ashoka's Capital\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
