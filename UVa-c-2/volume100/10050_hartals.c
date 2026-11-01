/*
 * ==========================================================================
 * UVa 10050 - Hartals
 * Title-CN: 罷工日計算
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: simulation, array
 * URL: https://onlinejudge.org/external/100/10050.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N days and P political parties, each party strikes every h_i days.
 *     No strikes occur on Friday (day 6, 13, ...) or Saturday (day 7, 14, ...).
 *     Find the number of working days lost due to strikes.
 *
 * [中文] 題目說明:
 *     在總共 N 天內，有 P 個政黨各自以週期 h_i 發動罷工。
 *     若某天為週五（第 6, 13, 20... 天）或週六（第 7, 14, 21... 天），則不罷工。
 *     計算 N 天內總共損失了多少個工作天（有至少一個政黨罷工的非週末天數）。
 *
 * [EN] Approach:
 *     Use a boolean array `strike[N + 1]`. For each party, mark multiples of h_i.
 *     Count days d where strike[d] is true and (d % 7 != 6) and (d % 7 != 0).
 * [中文] 思路:
 *     陣列標記每個罷工日，最後排除星期五 (d % 7 == 6) 與星期六 (d % 7 == 0) 後統計總數。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10050(int n, int p, const int *hartals) {
    int strike[3700] = {0};
    for (int i = 0; i < p; i++) {
        int h = hartals[i];
        for (int day = h; day <= n; day += h) {
            strike[day] = 1;
        }
    }
    int lost = 0;
    for (int d = 1; d <= n; d++) {
        if (strike[d] && (d % 7 != 6) && (d % 7 != 0)) {
            lost++;
        }
    }
    return lost;
}

int main(void) {
    int h1[] = {3, 4, 8};
    int r1 = solve_uva10050(14, 3, h1);
    int ok = (r1 == 5);
    printf("%s: UVa 10050 - Hartals\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
