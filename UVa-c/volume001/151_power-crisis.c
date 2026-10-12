/*
 * ==========================================================================
 * UVa 151 - Power Crisis
 * Title-CN: 電力危機
 * Difficulty: UVa Star 1
 * Tags: simulation, math, josephus
 * ==========================================================================
 * [EN] Problem: Find minimal step m such that region 13 is the last region shut off among N regions (region 1 first).
 * [中文] 題目說明: N 個地區停電，第 1 區最先停電，每次數 m 個人。求使得第 13 區為最後停電者的最小整數 m。
 * [EN] Approach: Iterate m from 1 upwards, simulate Josephus process for N-1 remaining regions.
 * [中文] 思路: 扣除第 1 區後剩下 N-1 個地區，枚舉 m 驗證最終倖存者編號是否為 13。
 * ==========================================================================
 */
#include <stdio.h>

int check_m(int n, int m) {
    int survivor = 0; /* 0-indexed in remaining n-1 */
    for (int i = 1; i < n; i++) {
        survivor = (survivor + m) % i;
    }
    return survivor; /* target region 13 is index 11 (2..13) */
}

int solve_uva151(int n) {
    for (int m = 1; ; m++) {
        int last = 0;
        for (int i = 1; i < n; i++) {
            last = (last + m) % i;
        }
        if (last == 11) return m; /* 13 - 2 = 11 */
    }
}

int main(void) {
    int m = solve_uva151(17);
    int ok = (m == 7);
    printf("%s: UVa 151 - Power Crisis\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
