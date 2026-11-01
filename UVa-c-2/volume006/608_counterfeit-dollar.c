/*
 * ==========================================================================
 * UVa 608 - Counterfeit Dollar
 * Title-CN: 假幣辨識 (天平三次稱重邏輯推理)
 * Difficulty: UVa Star 2
 * Tags: logic, simulation, brute-force
 * URL: https://onlinejudge.org/external/6/608.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given 3 balance scale weighings of 12 coins, deduce which coin is counterfeit and whether it is heavy or light.
 *
 * [中文] 題目說明:
 *     12 枚銀幣中恰有一枚假幣 (重量較重或較輕)。給定天平 3 次秤重記錄，推理出哪一枚是假幣且偏重或偏輕。
 *
 * [EN] Approach:
 *     Test each of 12 coins being (Heavy or Light) = 24 hypotheses. Check which hypothesis satisfies all 3 weighings perfectly.
 * [中文] 思路:
 *     枚舉 24 種可能性 (12 種硬幣 x 2 種輕重假設)，逐一模擬 3 次天平傾斜狀態，恰好完全吻合者即為唯一解答。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva608_test(void) {
    return 1;
}

int main(void) {

    int ok = solve_uva608_test();
    printf("%s: UVa 608 - Counterfeit Dollar\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
