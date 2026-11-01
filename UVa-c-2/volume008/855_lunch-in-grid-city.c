/*
 * ==========================================================================
 * UVa 855 - Lunch in Grid City
 * Title-CN: 格點城市聚餐地點 (二維曼哈頓中位數)
 * Difficulty: UVa Star 1
 * Tags: math, sorting, geometry
 * URL: https://onlinejudge.org/external/8/855.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find grid intersection (street, avenue) that minimizes total Manhattan distance to F friends.
 *
 * [中文] 題目說明:
 *     在二維棋盤城市中尋找最佳集合十字路口，使所有朋友到該點的曼哈頓距離總和最小 (中位數定理)。
 *
 * [EN] Approach:
 *     Independent coordinates: median of sorted street coordinates and median of sorted avenue coordinates.
 * [中文] 思路:
 *     曼哈頓距離 x 與 y 軸互相獨立。將所有朋友的街道與大道座標分別排序，各取中位數 (F - 1) / 2 即為最佳地點。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva855(int f, int *streets, int *avenues, int *best_s, int *best_a) {
    for (int i = 0; i < f - 1; i++) {
        for (int j = i + 1; j < f; j++) {
            if (streets[i] > streets[j]) { int t = streets[i]; streets[i] = streets[j]; streets[j] = t; }
            if (avenues[i] > avenues[j]) { int t = avenues[i]; avenues[i] = avenues[j]; avenues[j] = t; }
        }
    }
    int mid = (f - 1) / 2;
    *best_s = streets[mid];
    *best_a = avenues[mid];
}

int main(void) {

    int s[3] = {2, 1, 5};
    int a[3] = {4, 3, 2};
    int bs, ba;
    solve_uva855(3, s, a, &bs, &ba);
    int ok = (bs == 2 && ba == 3);
    printf("%s: UVa 855 - Lunch in Grid City\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
