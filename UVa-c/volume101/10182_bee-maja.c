/*
 * ==========================================================================
 * UVa 10182 - Bee Maja
 * Title-CN: 蜜蜂瑪雅六角蜂巢螺旋座標映射
 * Difficulty: UVa Star 1
 * Tags: simulation, math
 * URL: https://onlinejudge.org/external/101/10182.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Maja the bee numbers hex honeycomb cells in an expanding spiral. Find the 2D axial coordinates (x, y) of cell N.
 *
 * [中文] 題目概述:
 *     蜜蜂瑪雅以六角蜂巢外擴螺旋為蜂房編號，求編號為 N 的蜂房在二維軸向座標系下的座標 (x, y)。
 *
 * [EN] Approach:
 *     Ring simulation: ring k has 6*k cells. Follow 6 directional steps (down-left, down, right, up-right, up, left) to step N.
 * [中文] 解題思路:
 *     分圈螺旋模擬：第 k 圈包含 6k 個格子，依六角網格的 6 個方向向量逐圈遞推精準定位座標。
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

void solve_uva10182(int n, int *x, int *y) {
    if (n == 1) { *x = 0; *y = 0; return; }
    int ring = 1, total = 1;
    while (total + 6 * ring < n) {
        total += 6 * ring;
        ring++;
    }
    int cur_x = ring, cur_y = 0;
    int cur = total + 1;
    int dx[] = {-1, -1, 0, 1, 1, 0};
    int dy[] = {1, 0, -1, -1, 0, 1};
    for (int d = 0; d < 6; d++) {
        int steps = (d == 0) ? ring - 1 : ring;
        for (int s = 0; s < steps; s++) {
            if (cur == n) { *x = cur_x; *y = cur_y; return; }
            cur_x += dx[d]; cur_y += dy[d];
            cur++;
        }
    }
    *x = cur_x; *y = cur_y;
}

int main(void) {

    int x, y;
    solve_uva10182(1, &x, &y);
    int ok = (x == 0 && y == 0);
    printf("%s: UVa 10182 - Bee Maja\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
