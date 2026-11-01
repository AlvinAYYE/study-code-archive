/*
 * ==========================================================================
 * UVa 634 - Polygon
 * Title-CN: 點在多邊形內判定 (射線交叉法)
 * Difficulty: Easy
 * Tags: Geometry, Point in Polygon, Ray Casting
 * URL: https://onlinejudge.org/external/6/634.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a point lies strictly inside an orthogonal/general polygon using ray-casting algorithm.
 *
 * [中文] 題目說明:
 *     使用射線法判斷指定點是否落在任意多邊形內部（輸出 T 或 F）。
 *
 * [EN] Approach:
 *     Cast a ray to the right. Count edge crossings: if total crossings is odd, point is inside; if even, outside.
 * [中文] 思路:
 *     由測試點向右引出水平射線，統計多邊形各邊與射線的交點個數，奇數在多邊形內，偶數在多邊形外。
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

bool is_point_in_poly(int n, const int pts[][2], int qx, int qy) {
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        int xi = pts[i][0], yi = pts[i][1];
        int xj = pts[j][0], yj = pts[j][1];
        if (((yi > qy) != (yj > qy)) && (qx < (xj - xi) * (qy - yi) / (yj - yi) + xi)) {
            inside = !inside;
        }
    }
    return inside;
}

int main(void) {

    int poly[4][2] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int ok = is_point_in_poly(4, poly, 5, 5) && !is_point_in_poly(4, poly, 15, 5);
    printf("%s: UVa 634 - Polygon\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
