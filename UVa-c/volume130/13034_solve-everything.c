/*
 * ==========================================================================
 * UVa 13034 - Solve Everything :-)
 * Title-CN: 解決所有題目判定
 * Difficulty: UVa Star 1
 * Tags: simulation
 * ==========================================================================
 * [EN] Problem: Check if all 13 contest problem counts are strictly > 0.
 * [中文] 題目說明: 13 道競賽題目解題數，若每題皆至少有 1 隊解出輸出 "Yes"，否則 "No"。
 * [EN] Approach: Check if any element is 0.
 * [中文] 思路: 遍歷 13 個整數若有 0 則回傳 0。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva13034(const int *solved) {
    for (int i = 0; i < 13; i++) if (solved[i] <= 0) return 0;
    return 1;
}

int main(void) {
    int s[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int ok = solve_uva13034(s);
    printf("%s: UVa 13034 - Solve Everything\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
