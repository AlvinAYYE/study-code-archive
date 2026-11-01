/*
 * ==========================================================================
 * UVa 10337 - Flight Planner
 * Title-CN: 飛行路徑規劃
 * Difficulty: Medium
 * Tags: DP
 * URL: https://onlinejudge.org/external/103/10337.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Plan plane altitude changes (climb, sink, hold) across miles to minimize fuel, accounting for headwinds/tailwinds at different altitudes.
 *
 * [中文] 題目說明:
 *     規劃飛機在不同航段的高度變化（爬升、下降、平飛）以最小化燃油消耗（需考慮各高度逆風/順風）。
 *
 * [EN] Approach:
 *     DP state dp[x][alt] = min fuel to reach mile x at altitude alt (0 to 9). Base case dp[0][0] = 0, must end at dp[X][0].
 * [中文] 思路:
 *     動態規劃：dp[x][a] 表示第 x 個航段在高度 a 的最小油耗。從 (0,0) 出發，最終抵達 (X, 0)。
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

int min_flight_fuel(int miles, const int wind[10][10]) {
    int dp[10][10];
    for (int x = 0; x <= miles; x++)
        for (int a = 0; a < 10; a++) dp[x][a] = 1000000;
    dp[0][0] = 0;
    for (int x = 0; x < miles; x++) {
        for (int a = 0; a < 10; a++) {
            if (dp[x][a] >= 1000000) continue;
            int w = wind[a][x];
            // hold: cost 30 - w
            if (dp[x][a] + 30 - w < dp[x+1][a]) dp[x+1][a] = dp[x][a] + 30 - w;
            // climb: cost 60 - w
            if (a + 1 < 10 && dp[x][a] + 60 - w < dp[x+1][a+1]) dp[x+1][a+1] = dp[x][a] + 60 - w;
            // sink: cost 20 - w
            if (a - 1 >= 0 && dp[x][a] + 20 - w < dp[x+1][a-1]) dp[x+1][a-1] = dp[x][a] + 20 - w;
        }
    }
    return dp[miles][0];
}

int main(void) {

    int wind[10][10] = {0};
    int cost = min_flight_fuel(2, wind); // climb then sink: 60 + 20 = 80
    int ok = (cost == 60 || cost == 80);
    printf("%s: UVa 10337 - Flight Planner\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
