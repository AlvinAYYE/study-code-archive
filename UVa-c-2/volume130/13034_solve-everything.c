/*
 * ==========================================================================
 * UVa 13034 - Solve Everything?!
 * Title-CN: 全部解出？！(各題解出數大於零判定)
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/130/13034.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Check if team solved at least one question in each of the 13 problem sets.
 *
 * [中文] 題目說明:
 *     評判隊伍是否在 13 道題目中每一題皆至少解出了一次 (即 13 個數值皆 > 0)。
 *
 * [EN] Approach:
 *     Verify all 13 integers are strictly positive (> 0).
 * [中文] 思路:
 *     檢查輸入的 13 個整數：若全部皆大於 0 輸出 Yes，只要有任一題解出數為 0 則輸出 No。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva13034(const int *p13) {
    for (int i = 0; i < 13; i++) if (p13[i] == 0) return 0;
    return 1;
}

int main(void) {

    int a1[13] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
    int a2[13] = {1,1,1,1,0,1,1,1,1,1,1,1,1};
    int ok = solve_uva13034(a1) && !solve_uva13034(a2);
    printf("%s: UVa 13034 - Solve Everything?!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
