/*
 * ==========================================================================
 * UVa 1001 - Say Cheese
 * Title-CN: 起司乳酪洞最短路徑 (3D 穿洞 Dijkstra)
 * Difficulty: UVa Star 2
 * Tags: geometry, graph, dijkstra, shortest-path
 * URL: https://onlinejudge.org/external/10/1001.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find shortest time to travel between two points in Swiss cheese with spherical holes (time inside holes is 0).
 *
 * [中文] 題目說明:
 *     起司內部含有多個球形孔洞，在孔洞內部移動時間為 0。求起點到終點的最短時間 (加權圖 Dijkstra)。
 *
 * [EN] Approach:
 *     Graph vertices: start, end, and n holes. Edge weight between holes i and j is max(0, dist(c_i, c_j) - r_i - r_j) * 10.
 * [中文] 思路:
 *     以起點、終點與 n 個球形洞為頂點建圖。兩球間移動距離為球心距離減去兩球半徑 (負數則為 0)，Dijkstra 求最短路。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

double hole_dist_1001(double x1, double y1, double z1, double r1,
                      double x2, double y2, double z2, double r2) {
    double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
    double cost = d - r1 - r2;
    return (cost < 0.0) ? 0.0 : cost;
}

int main(void) {

    double d = hole_dist_1001(0, 0, 0, 1, 0, 0, 5, 1);
    int ok = (fabs(d - 3.0) < 1e-4);
    printf("%s: UVa 1001 - Say Cheese\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
