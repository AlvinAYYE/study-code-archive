/*
 * ==========================================================================
 * UVa 10013 - Super long sums
 * Title-CN: 超長整數大數相加
 * Difficulty: UVa Star 1
 * Tags: math, big-integer, simulation
 * URL: https://onlinejudge.org/external/100/10013.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Add two numbers up to 1,000,000 digits given digit by digit from most significant to least.
 *
 * [中文] 題目說明:
 *     給定長達 100 萬位的兩個大整數，由最高位到最低位給出，求兩數相加的精確結果。
 *
 * [EN] Approach: Store sum of digits in array, then process carries from right to left.
 * [中文] 思路: 先直接相加每位數存入陣列，再由最低位（右端）向最高位（左端）進行進位處理。
 * ==========================================================================
 */
#include <stdio.h>

void solve_uva10013(int m, const int *d1, const int *d2, int *res) {
    for (int i = 0; i < m; i++) res[i] = d1[i] + d2[i];
    for (int i = m - 1; i > 0; i--) {
        if (res[i] >= 10) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
}

int main(void) {
    int d1[4] = {4, 2, 5, 3};
    int d2[4] = {3, 9, 8, 7};
    int res[4];
    solve_uva10013(4, d1, d2, res);
    int ok = (res[0] == 8 && res[1] == 2 && res[2] == 4 && res[3] == 0);
    printf("%s: UVa 10013 - Super long sums\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
