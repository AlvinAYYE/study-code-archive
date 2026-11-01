/*
 * ==========================================================================
 * UVa 12798 - Handball
 * Title-CN: 手球每場皆有進球球員計數
 * Difficulty: UVa Star 1
 * Tags: simulation, 2d-grid
 * URL: https://onlinejudge.org/external/127/12798.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count how many players scored at least one goal in every single match of the season.
 *
 * [中文] 題目說明:
 *     統計整季所有場次中，每一場皆至少攻入 1 球的全勤進球球員總人數。
 *
 * [EN] Approach:
 *     For each player row, verify that all match scores are > 0. Increment count.
 * [中文] 思路:
 *     檢查每位球員的比賽得分陣列：若該列所有數值皆大於 0 則符合條件，累加符合全勤進球球員人數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva12798(int n, int m, int scores[][105]) {
    int qualified = 0;
    for (int i = 0; i < n; i++) {
        int all_scored = 1;
        for (int j = 0; j < m; j++) {
            if (scores[i][j] == 0) { all_scored = 0; break; }
        }
        if (all_scored) qualified++;
    }
    return qualified;
}

int main(void) {

    int sc[2][105] = {{1, 2, 3}, {1, 0, 2}};
    int ok = (solve_uva12798(2, 3, sc) == 1);
    printf("%s: UVa 12798 - Handball\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
