/*
 * ==========================================================================
 * UVa 920 - Sunny Mountains
 * Title-CN: 陽光山脈 (幾何線段投影)
 * Difficulty: Medium
 * Tags: Geometry, Sorting
 * URL: https://onlinejudge.org/external/9/920.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate total length of mountain slopes facing sun from top-right receiving direct sunlight.
 *
 * [中文] 題目說明:
 *     計算由右側射入的陽光所能照亮的山脈迎光坡面總長度。
 *
 * [EN] Approach:
 *     Sort peak points by x descending. Keep track of highest y seen so far. If current peak is higher, calculate illuminated segment length using similar triangles.
 * [中文] 思路:
 *     將山峰點按 x 坐標降序排序，由右至左維護已見最高高度 max_y；遇更高山峰則利用相似三角形計算受光照坡面長度。
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

int cmp_pt(const void *a, const void *b) {
    double xa = ((double*)a)[0], xb = ((double*)b)[0];
    return (xb > xa) - (xb < xa);
}
double sunny_slopes(int n, double pts[][2]) {
    qsort(pts, n, sizeof(pts[0]), cmp_pt);
    double max_y = 0.0;
    double ans = 0.0;
    for (int i = 1; i < n; i++) {
        if (pts[i][1] > max_y) {
            double dx = pts[i][0] - pts[i-1][0];
            double dy = pts[i][1] - pts[i-1][1];
            double seg = sqrt(dx * dx + dy * dy);
            ans += seg * (pts[i][1] - max_y) / dy;
            max_y = pts[i][1];
        }
    }
    return ans;
}

int main(void) {

    double pts[3][2] = {{0, 0}, {50, 100}, {100, 0}};
    double len = sunny_slopes(3, pts);
    int ok = (len > 0);
    printf("%s: UVa 920 - Sunny Mountains\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
