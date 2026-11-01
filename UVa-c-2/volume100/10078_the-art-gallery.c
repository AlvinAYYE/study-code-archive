/*
 * ==========================================================================
 * UVa 10078 - The Art Gallery
 * Title-CN: 美術館警戒盲點 (多邊形凸性判定)
 * Difficulty: Medium
 * Tags: Geometry, Convex Polygon, Cross Product
 * URL: https://onlinejudge.org/external/100/10078.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a polygon representing an art gallery has critical points (not completely convex).
 *
 * [中文] 題目說明:
 *     判定表示美術館平面的多邊形是否不是嚴格凸多邊形（即是否存在視覺盲點的臨界點）。
 *
 * [EN] Approach:
 *     Calculate cross products of consecutive directed edges (p_{i+1} - p_i) x (p_{i+2} - p_{i+1}). If any sign change occurs, it is non-convex.
 * [中文] 思路:
 *     計算相鄰邊的二維向量叉積，若所有叉積同號則為凸多邊形（無盲點）；若出現不同符號則非凸（存在盲點）。
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

long long cross_prod(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}
bool has_critical_point(int n, const long long pts[][2]) {
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        long long cp = cross_prod(pts[i][0], pts[i][1], pts[j][0], pts[j][1], pts[k][0], pts[k][1]);
        if (cp > 0) pos++;
        if (cp < 0) neg++;
    }
    return (pos > 0 && neg > 0); // non-convex has critical points
}

int main(void) {

    long long square[4][2] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int ok = !has_critical_point(4, square); // convex -> no critical points
    printf("%s: UVa 10078 - The Art Gallery\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
