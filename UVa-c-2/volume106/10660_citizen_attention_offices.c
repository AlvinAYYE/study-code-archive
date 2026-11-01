/*
 * ==========================================================================
 * UVa 10660 - Citizen attention offices
 * Title-CN: 市民服務處選址最佳化
 * Difficulty: Medium
 * Tags: Brute Force, Geometry, Manhattan Distance
 * URL: https://onlinejudge.org/external/106/10660.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Choose 5 office locations from 25 grid cells to minimize the total weighted Manhattan distance to populated areas.
 *
 * [中文] 題目描述:
 *     在 5x5 的網格中選定 5 個辦事處位置，使所有居民前往最近辦事處的曼哈頓距離加權總和最小。
 *
 * [EN] Approach:
 *     Combinations C(25, 5) = 53130. Brute force all tuples of 5 locations, compute weighted distance, pick minimum.
 *
 * [中文] 解題思維:
 *     枚舉全部 C(25, 5) = 53130 種組合，計算各居民點到 5 個辦事處的最短曼哈頓距離加權和，取最小者。
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

void place_citizen_offices(int num_areas, int *r, int *c, int *pop, int best_offices[5]) {
    int min_total = 2000000000;

    for (int a = 0; a < 25; a++) {
        for (int b = a + 1; b < 25; b++) {
            for (int d = b + 1; d < 25; d++) {
                for (int e = d + 1; e < 25; e++) {
                    for (int f = e + 1; f < 25; f++) {
                        int offs[5] = {a, b, d, e, f};
                        int sum_dist = 0;
                        for (int i = 0; i < num_areas; i++) {
                            int pr = r[i], pc = c[i], p = pop[i];
                            int min_d = 1000;
                            for (int k = 0; k < 5; k++) {
                                int or = offs[k] / 5, oc = offs[k] % 5;
                                int dist = abs(pr - or) + abs(pc - oc);
                                if (dist < min_d) min_d = dist;
                            }
                            sum_dist += min_d * p;
                        }
                        if (sum_dist < min_total) {
                            min_total = sum_dist;
                            best_offices[0] = a; best_offices[1] = b; best_offices[2] = d;
                            best_offices[3] = e; best_offices[4] = f;
                        }
                    }
                }
            }
        }
    }
}

int main(void) {

    int r[] = {2};
    int c[] = {2};
    int pop[] = {100};
    int off[5];
    place_citizen_offices(1, r, c, pop, off);
    // At least one office should be exactly on cell 12 (row 2, col 2) for 0 distance
    int ok = (off[0] == 12 || off[1] == 12 || off[2] == 12 || off[3] == 12 || off[4] == 12);
    printf("%s: UVa 10660 - Citizen attention offices\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
