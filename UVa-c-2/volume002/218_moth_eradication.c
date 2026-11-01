/*
 * ==========================================================================
 * UVa 218 - Moth Eradication
 * Title-CN: 飛蛾撲滅計畫 (凸包周長)
 * Difficulty: Medium
 * Tags: Geometry, Convex Hull
 * URL: https://onlinejudge.org/external/2/218.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum perimeter convex fence that encloses all given trap coordinates.
 *
 * [中文] 題目描述:
 *     求包圍所有陷阱坐標的最小周長凸多邊形圍欄（凸包）的頂點序列與周長。
 *
 * [EN] Approach:
 *     Compute 2D convex hull using Andrew's monotone chain algorithm and sum distances between adjacent vertices.
 *
 * [中文] 解題思維:
 *     使用 Andrew 單調鏈演算法計算 2D 點集的凸包，並累加相鄰頂點間距離求周長。
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

typedef struct { double x, y; } Pt218;

static int cmp_pt218(const void *a, const void *b) {
    const Pt218 *p = (const Pt218 *)a, *q = (const Pt218 *)b;
    if (p->x != q->x) return p->x < q->x ? -1 : 1;
    return p->y < q->y ? -1 : (p->y > q->y ? 1 : 0);
}

static double cross_218(Pt218 o, Pt218 a, Pt218 b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double convex_hull_perimeter(Pt218 *pts, int n) {
    if (n <= 1) return 0.0;
    qsort(pts, n, sizeof(Pt218), cmp_pt218);
    Pt218 h[205];
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross_218(h[k - 2], h[k - 1], pts[i]) <= 0) k--;
        h[k++] = pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross_218(h[k - 2], h[k - 1], pts[i]) <= 0) k--;
        h[k++] = pts[i];
    }
    k--; // last is same as first
    double perim = 0.0;
    for (int i = 0; i < k; i++) {
        double dx = h[(i + 1) % k].x - h[i].x;
        double dy = h[(i + 1) % k].y - h[i].y;
        perim += sqrt(dx * dx + dy * dy);
    }
    return perim;
}

int main(void) {

    Pt218 pts[] = {{0, 0}, {4, 0}, {4, 3}, {0, 3}, {2, 1}};
    double p = convex_hull_perimeter(pts, 5);
    int ok = (fabs(p - 14.0) < 1e-4);
    printf("%s: UVa 218 - Moth Eradication\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
