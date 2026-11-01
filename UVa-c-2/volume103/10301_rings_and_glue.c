/*
 * ==========================================================================
 * UVa 10301 - Rings and Glue
 * Title-CN: 環與膠水 (圓相交最大連通塊)
 * Difficulty: Medium
 * Tags: Geometry, Disjoint Set, Connected Components
 * URL: https://onlinejudge.org/external/103/10301.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given n circular rings with coordinates and radii, find the size of the largest connected set of glued rings.
 *
 * [中文] 題目描述:
 *     給定 n 個圓環的位置與半徑，判斷相交（邊界重疊）的環，求最大連通塊中包含的環數量。
 *
 * [EN] Approach:
 *     Two circles intersect if |r1 - r2| <= dist <= r1 + r2. Build union-find set and return maximum component size.
 *
 * [中文] 解題思維:
 *     兩圓相交的充要條件為圓心距離 d 滿足 |r1 - r2| <= d <= r1 + r2。使用並查集維護連通塊大小。
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

static int find_10301(int *p, int x) {
    if (p[x] < 0) return x;
    return p[x] = find_10301(p, p[x]);
}

static void union_10301(int *p, int a, int b) {
    int ra = find_10301(p, a), rb = find_10301(p, b);
    if (ra != rb) {
        p[ra] += p[rb]; // p stores negative size
        p[rb] = ra;
    }
}

int max_glued_rings(int n, double *x, double *y, double *r) {
    if (n == 0) return 0;
    int p[105];
    for (int i = 0; i < n; i++) p[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            double d = sqrt(dx * dx + dy * dy);
            if (d <= r[i] + r[j] && d >= fabs(r[i] - r[j])) {
                union_10301(p, i, j);
            }
        }
    }
    int max_sz = 1;
    for (int i = 0; i < n; i++) {
        if (p[i] < 0 && -p[i] > max_sz) max_sz = -p[i];
    }
    return max_sz;
}

int main(void) {

    double x[] = {0.0, 1.5, 5.0};
    double y[] = {0.0, 0.0, 0.0};
    double r[] = {1.0, 1.0, 1.0};
    // Ring 0 and Ring 1 overlap (dist 1.5 <= 2.0), Ring 2 is far away
    int ok = (max_glued_rings(3, x, y, r) == 2);
    printf("%s: UVa 10301 - Rings and Glue\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
