/*
 * ==========================================================================
 * UVa 356 - Square Pegs And Round Holes
 * Title-CN: 方釘圓孔 (圓與網格完全包含及穿過計數)
 * Difficulty: Easy
 * Tags: Geometry, Math
 * URL: https://onlinejudge.org/external/3/356.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given radius R = (2n - 1) / 2, count the number of 1x1 cells completely inside the circle and cells intersected by circle boundary.
 *
 * [中文] 題目說明:
 *     半徑為 R = (2n - 1) / 2 的圓覆蓋網格，求完全落在圓內的 1x1 網格數以及被圓周切割的網格數。
 *
 * [EN] Approach:
 *     Symmetry across 4 quadrants. A 1x1 cell [x, x+1] x [y, y+1] is completely inside if outer corner (x+1)^2 + (y+1)^2 <= R^2. Intersects if inner corner <= R^2 and outer corner > R^2.
 * [中文] 思路:
 *     利用四象限對稱性：若外頂點 (x+1)^2 + (y+1)^2 <= R^2 則完全在圓內；若內外頂點跨越圓半徑則為相交邊界格。
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

void count_grid_circle(int n, int *completely_in, int *intersected) {
    double r = (2.0 * n - 1.0) / 2.0;
    double r2 = r * r;
    int in_cnt = 0, seg_cnt = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            double inner = (double)x * x + (double)y * y;
            double outer = (double)(x + 1) * (x + 1) + (double)(y + 1) * (y + 1);
            if (outer <= r2) in_cnt++;
            else if (inner < r2 && outer > r2) seg_cnt++;
        }
    }
    *completely_in = in_cnt * 4;
    *intersected = seg_cnt * 4;
}

int main(void) {

    int in_c, int_c;
    count_grid_circle(3, &in_c, &int_c);
    int ok = (int_c == 20);
    printf("%s: UVa 356 - Square Pegs And Round Holes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
