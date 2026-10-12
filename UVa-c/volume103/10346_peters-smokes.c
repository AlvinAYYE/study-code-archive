/*
 * ==========================================================================
 * UVa 10346 - Peter's Smokes
 * Title-CN: 彼得的煙蒂
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * ==========================================================================
 * [EN] Problem: Max cigarettes smoked given n initial and k butts per roll.
 * [中文] 題目說明: n 支煙、每 k 個煙蒂換 1 支新煙，求最多抽幾支。
 * [EN] Approach: Simulate rolling while butts >= k. Formula n + (n - 1) / (k - 1).
 * [中文] 思路: 迴圈模擬換煙直到煙蒂不足 k 根。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10346(int n, int k) {
    int total = n;
    int butts = n;
    while (butts >= k) {
        int new_cigs = butts / k;
        total += new_cigs;
        butts = (butts % k) + new_cigs;
    }
    return total;
}

int main(void) {
    int ok = (solve_uva10346(4, 3) == 5) && (solve_uva10346(10, 3) == 14);
    printf("%s: UVa 10346 - Peters Smokes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
