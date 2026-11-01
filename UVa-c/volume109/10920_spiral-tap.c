/*
 * ==========================================================================
 * UVa 10920 - Spiral Tap
 * Title-CN: 螺旋座標定位
 * Difficulty: Medium
 * Tags: Math, Simulation
 * URL: https://onlinejudge.org/external/109/10920.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a grid size S and a cell number P in an outwards counter-clockwise spiral starting at center 1, find row and column.
 *
 * [中文] 題目概述:
 *     在邊長為 S 的網格中，從中心點 1 逆時針向外呈螺旋編號，求編號 P 所在的行與列座標。
 *
 * [EN] Approach:
 *     Find the odd square ring k such that (k-2)^2 < P <= k^2. Center is at ((S+1)/2, (S+1)/2). Trace position along the four segments of ring k.
 * [中文] 解題思路:
 *     找出 P 所在的奇數外環 k：(k-2)^2 < P <= k^2，中心為 ((S+1)/2, (S+1)/2)，再根據 P 在外環四條邊上的相對位置推算座標。
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

void spiral_coords(long long s, long long p, long long *row, long long *col) {
    long long center = (s + 1) / 2;
    if (p == 1) { *row = center; *col = center; return; }
    long long k = 1;
    while (k * k < p) k += 2;
    long long r = center + (k / 2);
    long long c = center + (k / 2);
    long long cur = k * k;
    long long side = k - 1;
    // top edge going left
    if (cur - side < p) { *row = r; *col = c - (cur - p); return; }
    cur -= side; c -= side;
    // left edge going down
    if (cur - side < p) { *row = r - (cur - p); *col = c; return; }
    cur -= side; r -= side;
    // bottom edge going right
    if (cur - side < p) { *row = r; *col = c + (cur - p); return; }
    cur -= side; c += side;
    // right edge going up
    *row = r + (cur - p); *col = c;
}

int main(void) {

    long long r, c;
    spiral_coords(3, 1, &r, &c);
    int ok = (r == 2 && c == 2);
    spiral_coords(3, 3, &r, &c);
    ok = ok && (r == 1 && c == 3);
    printf("%s: UVa 10920 - Spiral Tap\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
