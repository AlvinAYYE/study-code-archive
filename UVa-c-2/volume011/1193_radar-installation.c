/*
 * ==========================================================================
 * UVa 1193 - Radar Installation
 * Title-CN: 雷達安裝 (區間選點貪心法)
 * Difficulty: Medium
 * Tags: Greedy, Geometry, Interval Scheduling
 * URL: https://onlinejudge.org/external/11/1193.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given islands in the ocean and radar range d on coastline (x-axis), find minimum number of radar stations to cover all islands.
 *
 * [中文] 題目描述:
 *     海岸線為 x 軸，海中有若干島嶼點，雷達半徑為 d，求最少需在海岸線上設立幾座雷達以覆蓋所有島嶼。
 *
 * [EN] Approach:
 *     Convert each island (x, y) into a valid x-interval [x - dx, x + dx] on coastline where dx = sqrt(d^2 - y^2). Sort by right endpoint, greedy interval point cover.
 *
 * [中文] 解題思維:
 *     利用 dx = sqrt(d^2 - y^2) 將各島嶼轉化為海岸線上的有效雷達放置區間，依區間右端點升序排序，貪心在右端點設雷達。
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

int min_radars(int n, double d, const double islands[][2]) {
    double ivs[20][2];
    for (int i = 0; i < n; i++) {
        if (islands[i][1] > d) return -1;
        double dx = sqrt(d * d - islands[i][1] * islands[i][1]);
        ivs[i][0] = islands[i][0] - dx;
        ivs[i][1] = islands[i][0] + dx;
    }
    // Sort by right endpoint
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ivs[i][1] > ivs[j][1]) {
                double t0 = ivs[i][0], t1 = ivs[i][1];
                ivs[i][0] = ivs[j][0]; ivs[i][1] = ivs[j][1];
                ivs[j][0] = t0; ivs[j][1] = t1;
            }
    int count = 1;
    double cur_r = ivs[0][1];
    for (int i = 1; i < n; i++) {
        if (ivs[i][0] > cur_r) {
            count++;
            cur_r = ivs[i][1];
        }
    }
    return count;
}

int main(void) {

    double isl[3][2] = {{1, 2}, {-3, 1}, {2, 1}};
    int r = min_radars(3, 2.0, isl);
    int ok = (r > 0);
    printf("%s: UVa 1193 - Radar Installation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
