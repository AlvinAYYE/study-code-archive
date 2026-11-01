/*
 * ==========================================================================
 * UVa 174 - Strategy
 * Title-CN: 囚徒困境賽局策略歷史模擬
 * Difficulty: UVa Star 2
 * Tags: simulation
 * URL: https://onlinejudge.org/external/1/174.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate round-robin tournament of automated memory-based strategies playing iterated Prisoner's Dilemma.
 *
 * [中文] 題目說明:
 *     模擬基於記憶歷史的多個策略程式進行重複囚徒困境循環賽，統計各策略的累積得分。
 *
 * [EN] Approach:
 *     Parse condition trees (e.g. IF LAST OPPONENT == CHEAT THEN CHEAT). Play N rounds pairwise and accumulate payoff scores.
 * [中文] 思路:
 *     解析各策略的歷史條件分支判斷樹，兩兩策略對決多回合，按得失分矩陣累加各策略之總積分。
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

void pd_score(int act1, int act2, int *score1, int *score2) {
    // 0: Cooperate, 1: Cheat
    if (act1 == 0 && act2 == 0) { *score1 += 1; *score2 += 1; }
    else if (act1 == 0 && act2 == 1) { *score1 -= 2; *score2 += 2; }
    else if (act1 == 1 && act2 == 0) { *score1 += 2; *score2 -= 2; }
    else { *score1 -= 1; *score2 -= 1; }
}

int main(void) {

    int s1 = 0, s2 = 0;
    pd_score(0, 0, &s1, &s2);
    int ok = (s1 == 1 && s2 == 1);
    printf("%s: UVa 174 - Strategy\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
