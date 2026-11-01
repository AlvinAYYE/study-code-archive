/*
 * ==========================================================================
 * UVa 10002 - Center of Masses
 * Title-CN: 凸多邊形質心計算
 * Difficulty: Medium
 * Tags: Geometry, Centroid, Polygon Area
 * URL: https://onlinejudge.org/external/100/10002.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the center of mass (centroid) of a uniform planar convex polygon.
 *
 * [中文] 題目描述:
 *     求均勻凸多邊形平面薄片的質心（重心）坐標。
 *
 * [EN] Approach:
 *     Sort vertices counter-clockwise (Convex Hull), then compute polygon area and weighted centroid coordinates using standard polygon formulas.
 *
 * [中文] 解題思維:
 *     先求凸包以取得逆時針頂點順序，再利用多邊形有向面積與質心積分公式求解 Cx 與 Cy。
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

typedef struct { double x, y; } Pt10002;

static int cmp_pt10002(const void *a, const void *b) {
    const Pt10002 *p = (const Pt10002 *)a, *q = (const Pt10002 *)b;
    if (p->x != q->x) return p->x < q->x ? -1 : 1;
    return p->y < q->y ? -1 : (p->y > q->y ? 1 : 0);
}

static double cross_10002(Pt10002 o, Pt10002 a, Pt10002 b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

void polygon_centroid(Pt10002 *pts, int n, double *cx, double *cy) {
    qsort(pts, n, sizeof(Pt10002), cmp_pt10002);
    Pt10002 h[205];
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross_10002(h[k - 2], h[k - 1], pts[i]) <= 0) k--;
        h[k++] = pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross_10002(h[k - 2], h[k - 1], pts[i]) <= 0) k--;
        h[k++] = pts[i];
    }
    k--; // k is number of unique vertices in counter-clockwise order

    double area = 0.0, sum_x = 0.0, sum_y = 0.0;
    for (int i = 0; i < k; i++) {
        Pt10002 p1 = h[i], p2 = h[(i + 1) % k];
        double cross = p1.x * p2.y - p2.x * p1.y;
        area += cross;
        sum_x += (p1.x + p2.x) * cross;
        sum_y += (p1.y + p2.y) * cross;
    }
    area *= 0.5;
    *cx = sum_x / (6.0 * area);
    *cy = sum_y / (6.0 * area);
}

int main(void) {

    Pt10002 square[] = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    double cx, cy;
    polygon_centroid(square, 4, &cx, &cy);
    int ok = (fabs(cx - 1.0) < 1e-4 && fabs(cy - 1.0) < 1e-4);
    printf("%s: UVa 10002 - Center of Masses\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
