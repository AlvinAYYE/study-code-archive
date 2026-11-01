/*
 * ==========================================================================
 * UVa 587 - There's treasure everywhere!
 * Title-CN: 到處都是寶藏！(二維羅盤方位向量累加)
 * Difficulty: UVa Star 1
 * Tags: geometry, math, parsing
 * URL: https://onlinejudge.org/external/5/587.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Follow navigation directions (N, NE, E, SE, S, SW, W, NW) with steps to find final (x, y) coordinates and Euclidean distance.
 *
 * [中文] 題目說明:
 *     依羅盤 8 方位步數 (正向為 step，斜向各分量為 step / sqrt(2)) 累計二維位移向量，求寶藏最終座標與直線距離。
 *
 * [EN] Approach:
 *     Vector accumulation: diagonal steps contribute step / sqrt(2) to both x and y axes.
 * [中文] 思路:
 *     解析步數與方位字串，正向直接增減座標，斜向各軸增減 step * sqrt(0.5)，最後以歐幾里得幾何距離公式求解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

void solve_uva587_step(double *x, double *y, int step, const char *dir) {
    double diag = step / sqrt(2.0);
    if (strcmp(dir, "N") == 0) *y += step;
    else if (strcmp(dir, "S") == 0) *y -= step;
    else if (strcmp(dir, "E") == 0) *x += step;
    else if (strcmp(dir, "W") == 0) *x -= step;
    else if (strcmp(dir, "NE") == 0) { *x += diag; *y += diag; }
    else if (strcmp(dir, "NW") == 0) { *x -= diag; *y += diag; }
    else if (strcmp(dir, "SE") == 0) { *x += diag; *y -= diag; }
    else if (strcmp(dir, "SW") == 0) { *x -= diag; *y -= diag; }
}

int main(void) {

    double x = 0, y = 0;
    solve_uva587_step(&x, &y, 10, "N");
    solve_uva587_step(&x, &y, 5, "E");
    int ok = (fabs(x - 5.0) < 1e-4 && fabs(y - 10.0) < 1e-4);
    printf("%s: UVa 587 - There's treasure everywhere!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
