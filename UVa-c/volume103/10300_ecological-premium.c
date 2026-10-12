/*
 * ==========================================================================
 * UVa 10300 - Ecological Premium
 * Title-CN: 生態補助金計算
 * Difficulty: UVa Star 1
 * Tags: math, elementary
 * URL: https://onlinejudge.org/external/103/10300.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute government subsidy for each farmer: (size / animals) * eco * animals = size * eco.
 *
 * [中文] 題目說明:
 *     計算每位農民的環保補助款。公式化簡後為 農地面積 * 環保等級。
 *
 * [EN] Approach: Sum product of size * eco for all farmers.
 * [中文] 思路: 牲畜數分子分母剛好約分抵消，直接累加 (面積 * 環保等級)。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva10300(int f, const long long farmers[][3]) {
    long long total = 0;
    for (int i = 0; i < f; i++) {
        long long size = farmers[i][0];
        long long eco = farmers[i][2];
        total += size * eco;
    }
    return total;
}

int main(void) {
    long long f[2][3] = {
        {100, 2, 3},  /* 100 * 3 = 300 */
        {200, 5, 2}   /* 200 * 2 = 400 */
    };
    int ok = (solve_uva10300(2, f) == 700);
    printf("%s: UVa 10300 - Ecological Premium\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
