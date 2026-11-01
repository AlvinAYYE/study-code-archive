/*
 * ==========================================================================
 * UVa 661 - Blowing Fuses
 * Title-CN: 保險絲熔斷模擬
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/6/661.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate device toggles with power consumption. Determine if fuse blows (capacity C exceeded) and find max power reached.
 *
 * [中文] 題目說明:
 *     模擬電器開關切換過程中的功率總和：若累積功率超出保險絲負載 C 則熔斷；否則求過程中達到的最大功率瓦數。
 *
 * [EN] Approach:
 *     Maintain device states (on/off) and current total power. Track running maximum; check against capacity C.
 * [中文] 思路:
 *     以布林陣列維護各電器開關狀態，每次操作累計功率，維護歷史最高功率並隨時檢查是否超過容量 C。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva661(int n, int m, int cap, const int *power, const int *ops, int *max_p) {
    int state[25] = {0};
    int cur_p = 0;
    *max_p = 0;
    for (int i = 0; i < m; i++) {
        int dev = ops[i] - 1;
        if (state[dev]) {
            cur_p -= power[dev];
            state[dev] = 0;
        } else {
            cur_p += power[dev];
            state[dev] = 1;
            if (cur_p > cap) return 0; /* Fuse blown */
            if (cur_p > *max_p) *max_p = cur_p;
        }
    }
    return 1;
}

int main(void) {

    int pow[2] = {10, 20};
    int ops[3] = {1, 1, 2};
    int max_p;
    int safe = solve_uva661(2, 3, 25, pow, ops, &max_p);
    int ok = safe && (max_p == 20);
    printf("%s: UVa 661 - Blowing Fuses\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
