/*
 * ==========================================================================
 * UVa 11420 - Chest of Drawers
 * Title-CN: 抽屜鎖定問題 (鎖定抽屜計數DP)
 * Difficulty: Easy
 * Tags: DP, Combinatorics
 * URL: https://onlinejudge.org/external/114/11420.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A vertical stack of n drawers can each be locked or unlocked. A drawer is secured if it is locked AND the drawer above it is locked (top drawer is secured if locked). Count ways to have exactly s secured drawers.
 *
 * [中文] 題目描述:
 *     n 層抽屜各自可上鎖或不上鎖。抽屜安全當且僅當自身上鎖且其上方抽屜亦上鎖（頂層上鎖即安全），求恰好有 s 個安全抽屜的方案數。
 *
 * [EN] Approach:
 *     DP state dp[i][j][state]: i drawers, j secured, state = 1 if current is locked else 0. Update based on transitions.
 *
 * [中文] 解題思維:
 *     動態規劃：dp[i][j][0/1] 表示前 i 個抽屜中恰有 j 個安全抽屜且當前抽屜未鎖/已鎖的方案數。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

long long count_secured_drawers(int n, int s) {
    long long dp[70][70][2] = {0};
    dp[1][1][1] = 1; // locked top -> secured
    dp[1][0][0] = 1; // unlocked top -> unsecured
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            // lock drawer i: if above (i-1) locked, secured increases by 1
            if (j > 0) dp[i][j][1] += dp[i-1][j-1][1];
            dp[i][j][1] += dp[i-1][j][0];
            // unlock drawer i: unsecured
            dp[i][j][0] += dp[i-1][j][1] + dp[i-1][j][0];
        }
    }
    return dp[n][s][0] + dp[n][s][1];
}

int main(void) {

    int ok = (count_secured_drawers(1, 1) == 1) && (count_secured_drawers(2, 0) == 2);
    printf("%s: UVa 11420 - Chest of Drawers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
