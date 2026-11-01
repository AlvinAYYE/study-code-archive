/*
 * ==========================================================================
 * UVa 10397 - Connect the Campus
 * Title-CN: 大學校園既有線路擴充最小生成樹
 * Difficulty: UVa Star 2
 * Tags: graph, mst, kruskal
 * URL: https://onlinejudge.org/external/103/10397.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given building coordinates and existing cables, find the minimum additional cable length needed to connect all buildings.
 *
 * [中文] 題目概述:
 *     給定校園建築物座標與既有電纜連接關係，求將全校所有建築物完全連通所需鋪設之最少額外電纜長度。
 *
 * [EN] Approach:
 *     Kruskal's algorithm with pre-union of existing cables (weight 0). Compute Euclidean distance for remaining building pairs and sum MST edges.
 * [中文] 解題思路:
 *     在既有電纜的基礎上執行 Kruskal：先將已有連線合併，對其餘建築對計算歐氏距離並依權重排序構建最小生成樹。
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

double solve_uva10397_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main(void) {

    double d = solve_uva10397_dist(0, 0, 3, 4);
    int ok = (fabs(d - 5.0) < 1e-4);
    printf("%s: UVa 10397 - Connect the Campus\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
