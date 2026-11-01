/*
 * ==========================================================================
 * UVa 10382 - Watering Grass
 * Title-CN: 草地澆水 (區間覆蓋貪心法)
 * Difficulty: Medium
 * Tags: Greedy, Interval Covering
 * URL: https://onlinejudge.org/external/103/10382.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum number of circular sprinklers along the center of a rectangular lawn of width w and length l needed to completely water it.
 *
 * [中文] 題目說明:
 *     求在長 l 寬 w 的長方形草地中心線上，最少需開啟幾個圓形噴水器才能完全覆蓋整片草地。
 *
 * [EN] Approach:
 *     Convert each circle into a 1D covered interval [x - dx, x + dx] along the strip using Pythagorean theorem dx = sqrt(r^2 - (w/2)^2). Run interval covering greedy algorithm.
 * [中文] 思路:
 *     利用畢氏定理 dx = sqrt(r^2 - (w/2)^2) 將圓轉化為中心線上的 1 維覆蓋區間，貪心選取能覆蓋當前左端點且向右延伸最遠的噴水器。
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

int min_sprinklers(int n, double l, double w, const double *pos, const double *rad) {
    double ivs[100][2];
    int cnt = 0;
    double h = w / 2.0;
    for (int i = 0; i < n; i++) {
        if (rad[i] > h) {
            double dx = sqrt(rad[i] * rad[i] - h * h);
            ivs[cnt][0] = pos[i] - dx;
            ivs[cnt][1] = pos[i] + dx;
            cnt++;
        }
    }
    // Greedy interval cover [0, l]
    double cur_r = 0.0;
    int used = 0;
    while (cur_r < l) {
        double max_ext = cur_r;
        for (int i = 0; i < cnt; i++) {
            if (ivs[i][0] <= cur_r && ivs[i][1] > max_ext) {
                max_ext = ivs[i][1];
            }
        }
        if (max_ext == cur_r) return -1; // cannot cover
        cur_r = max_ext;
        used++;
    }
    return used;
}

int main(void) {

    double pos[] = {1, 4, 7, 10}, rad[] = {2, 2, 2, 2};
    int ans = min_sprinklers(4, 10.0, 2.0, pos, rad);
    int ok = (ans > 0);
    printf("%s: UVa 10382 - Watering Grass\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
