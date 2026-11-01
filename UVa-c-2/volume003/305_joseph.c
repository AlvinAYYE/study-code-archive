/*
 * ==========================================================================
 * UVa 305 - Joseph
 * Title-CN: 約瑟夫的倖存計謀 (前 k 名好人保全)
 * Difficulty: UVa Star 2
 * Tags: math, simulation, josephus
 * URL: https://onlinejudge.org/external/3/305.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find smallest step m such that among 2k people (k good then k bad), all k bad people are executed before any good person.
 *
 * [中文] 題目說明:
 *     2k 個人圍成一圈 (前 k 個好人，後 k 個壞人)，求最小報數間隔 m 使得所有壞人都在好人之前被處決。
 *
 * [EN] Approach:
 *     Math cycle simulation. Since k < 14, m must be congruent to 0 or 1 mod (k+1). Precompute answers for 1 <= k < 14.
 * [中文] 思路:
 *     以約瑟夫位置公式模擬淘汰過程。因 k < 14，直接枚舉 m 進行驗證，或預先計算打表可在 O(1) 輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva305(int k) {
    int ans[14] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
    return (k >= 1 && k < 14) ? ans[k] : 0;
}

int main(void) {

    int ok = (solve_uva305(3) == 5) && (solve_uva305(4) == 30);
    printf("%s: UVa 305 - Joseph\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
