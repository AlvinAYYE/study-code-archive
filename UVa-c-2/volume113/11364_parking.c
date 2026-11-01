/*
 * ==========================================================================
 * UVa 11364 - Parking
 * Title-CN: 最佳停車地點走動距離最小化
 * Difficulty: UVa Star 1
 * Tags: math, greedy
 * URL: https://onlinejudge.org/external/113/11364.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum total walking distance to visit all shops along a street and return to car.
 *
 * [中文] 題目說明:
 *     在街道一維座標軸上停車，走遍所有商店後回到停車處，求最少總步行距離 (2 * (max - min))。
 *
 * [EN] Approach:
 *     Regardless of parking location inside the span, optimal round trip distance is always 2 * (max_pos - min_pos).
 * [中文] 思路:
 *     閉區間遍歷性質：無論車停在兩端之間何處，來回拜訪所有點並回到原處的最短總距離恆等於 2 * (最大座標 - 最小座標)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11364(int n, const int *x) {
    int min_x = x[0], max_x = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] < min_x) min_x = x[i];
        if (x[i] > max_x) max_x = x[i];
    }
    return 2 * (max_x - min_x);
}

int main(void) {

    int p[4] = {24, 13, 89, 37};
    int ok = (solve_uva11364(4, p) == 152); /* 2 * (89 - 13) = 152 */
    printf("%s: UVa 11364 - Parking\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
