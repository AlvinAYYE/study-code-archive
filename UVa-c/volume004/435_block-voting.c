/*
 * ==========================================================================
 * UVa 435 - Block Voting
 * Title-CN: 投票集團權力指數 (班茨哈夫指數)
 * Difficulty: UVa Star 2
 * Tags: math, subset-sum, combinatorics
 * URL: https://onlinejudge.org/external/4/435.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute Banzhaf Power Index for each party: number of winning coalitions where party is a critical swing voter.
 *
 * [中文] 題目說明:
 *     計算各黨派的班茨哈夫權力指數：該黨在所有過半數聯盟中，扣除其票數即變為不過半的關鍵搖擺次數。
 *
 * [EN] Approach:
 *     Subset sum dynamic programming or brute-force bitmask (P <= 20). Check whether sum without party is in [majority - v, majority - 1].
 * [中文] 思路:
 *     因黨派數 P <= 20，可以位元列舉或動態規劃背包求其餘黨派的票數組合，若票數落在 [過半-v, 過半-1] 則為關鍵票。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva435(int p, const int *votes, int *power) {
    int sum = 0;
    for (int i = 0; i < p; i++) sum += votes[i];
    int maj = sum / 2 + 1;
    for (int i = 0; i < p; i++) {
        int v = votes[i];
        int dp[1005] = {0};
        dp[0] = 1;
        for (int j = 0; j < p; j++) {
            if (i == j) continue;
            for (int k = maj - 1; k >= votes[j]; k--) {
                dp[k] += dp[k - votes[j]];
            }
        }
        int swing = 0;
        int low = (maj - v > 0) ? (maj - v) : 0;
        for (int k = low; k < maj; k++) swing += dp[k];
        power[i] = swing;
    }
}

int main(void) {

    int v[3] = {4, 2, 1};
    int p[3];
    solve_uva435(3, v, p);
    int ok = (p[0] > 0);
    printf("%s: UVa 435 - Block Voting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
