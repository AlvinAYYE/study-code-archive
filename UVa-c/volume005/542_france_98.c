/*
 * ==========================================================================
 * UVa 542 - France '98
 * Title-CN: 1998 世界盃淘汰賽奪冠機率
 * Difficulty: Medium
 * Tags: Probability, Dynamic Programming, Tournament
 * URL: https://onlinejudge.org/external/5/542.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given match winning probabilities between all pairs of 16 teams, compute each team's probability of winning the tournament.
 *
 * [中文] 題目描述:
 *     給定 16 支球隊兩兩對戰的勝率矩陣，計算每支球隊最終贏得世界盃冠軍的機率。
 *
 * [EN] Approach:
 *     DP over tournament rounds 1 to 4. For round r, team i can play against team j iff (i >> (r-1)) ^ 1 == (j >> (r-1)).
 *
 * [中文] 解題思維:
 *     樹狀錦標賽動態規劃：在第 r 輪，隊伍 i 的對手為其所屬長度 2^r 的子區間內另一半的所有可能勝出者 j，累加條件機率。
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

void tournament_win_probabilities(double p[16][16], double win_prob[16]) {
    double dp[5][16];
    for (int i = 0; i < 16; i++) dp[0][i] = 1.0;

    for (int r = 1; r <= 4; r++) {
        int group_size = 1 << r;
        int half_size = group_size >> 1;
        for (int i = 0; i < 16; i++) {
            dp[r][i] = 0.0;
            int block = i / group_size;
            int in_half = (i % group_size) / half_size;
            int opp_half = 1 - in_half;
            int opp_start = block * group_size + opp_half * half_size;

            for (int j = opp_start; j < opp_start + half_size; j++) {
                dp[r][i] += dp[r - 1][i] * dp[r - 1][j] * p[i][j];
            }
        }
    }
    for (int i = 0; i < 16; i++) win_prob[i] = dp[4][i];
}

int main(void) {

    double p[16][16];
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) p[i][j] = 0.5;
    }
    double win[16];
    tournament_win_probabilities(p, win);
    // When all teams are equal, each team has 1/16 = 0.0625 chance
    int ok = (fabs(win[0] - 0.0625) < 1e-4);
    printf("%s: UVa 542 - France '98\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
