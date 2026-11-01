/*
 * ==========================================================================
 * UVa 12468 - Zapping
 * Title-CN: 電視遙控器選台最少按鍵次數
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/124/12468.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute minimum button presses to switch from channel a to channel b on a 100-channel TV (0..99 circular).
 *
 * [中文] 題目說明:
 *     在 100 個頻道 (0 到 99 環形相連) 的電視中由頻道 a 切換至 b，求上鍵或下鍵的最少按壓次數。
 *
 * [EN] Approach:
 *     Direct difference and wraparound difference: min(abs(a - b), 100 - abs(a - b)).
 * [中文] 思路:
 *     環形最短距離：計算直接距離 abs(a - b) 與跨越 0 號頻道的距離 100 - abs(a - b) 的最小值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stdlib.h>

int solve_uva12468(int a, int b) {
    int diff = abs(a - b);
    return (diff < 100 - diff) ? diff : (100 - diff);
}

int main(void) {

    int ok = (solve_uva12468(10, 15) == 5) && (solve_uva12468(0, 99) == 1);
    printf("%s: UVa 12468 - Zapping\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
