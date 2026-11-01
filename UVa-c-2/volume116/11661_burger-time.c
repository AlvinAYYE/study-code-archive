/*
 * ==========================================================================
 * UVa 11661 - Burger Time?
 * Title-CN: 速食漢堡餐廳與藥局最短距離
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/116/11661.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given highway string with 'R' (restaurant), 'D' (drugstore), and 'Z' (both), find minimum distance between any R and D.
 *
 * [中文] 題目說明:
 *     給定包含 'R' (餐廳)、'D' (藥局) 與 'Z' (兩者皆有) 的沿街字串，求任一餐廳與藥局之間的最短距離。
 *
 * [EN] Approach:
 *     If 'Z' exists, distance is 0. Otherwise, track last seen indices of 'R' and 'D' and take minimum abs(last_R - last_D).
 * [中文] 思路:
 *     若存在 'Z' 則距離為 0；否則記錄最後一次遇到 'R' 與 'D' 的索引位置，動態更新其下標差值之最小值。
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

int solve_uva11661(int l, const char *s) {
    int last_r = -1, last_d = -1, min_dist = 1e9;
    for (int i = 0; i < l; i++) {
        if (s[i] == 'Z') return 0;
        if (s[i] == 'R') {
            last_r = i;
            if (last_d != -1 && (last_r - last_d) < min_dist) min_dist = last_r - last_d;
        } else if (s[i] == 'D') {
            last_d = i;
            if (last_r != -1 && (last_d - last_r) < min_dist) min_dist = last_d - last_r;
        }
    }
    return min_dist;
}

int main(void) {

    int d = solve_uva11661(5, "R..D.");
    int ok = (d == 3);
    printf("%s: UVa 11661 - Burger Time?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
