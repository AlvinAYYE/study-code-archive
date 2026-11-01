/*
 * ==========================================================================
 * UVa 10404 - Bachet's Game
 * Title-CN: 巴切特的博弈遊戲
 * Difficulty: Medium
 * Tags: Game Theory, DP
 * URL: https://onlinejudge.org/external/104/10404.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether Stan or Ollie wins a stone-removal game given n stones and a fixed set of allowed removal counts.
 *
 * [中文] 題目概述:
 *     給定 n 顆石子與一組允許拿取的石子數量，判定在雙方均採取最優策略下是先手 Stan 或後手 Ollie 獲勝。
 *
 * [EN] Approach:
 *     Dynamic programming game theory: win[i] is true if there exists an allowed move k such that win[i-k] is false (loss for next player).
 * [中文] 解題思路:
 *     博弈論 DP：若存在可選步數 k 使得 win[i-k] 為必敗態，則 win[i] 為必勝態。
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

bool stan_wins_bachet(int n, int m, const int *moves) {
    bool win[1001] = {false};
    win[0] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= moves[j] && !win[i - moves[j]]) {
                win[i] = true;
                break;
            }
        }
    }
    return win[n];
}

int main(void) {

    int moves[] = {1, 3, 4};
    int ok = (stan_wins_bachet(2, 3, moves) == false) && (stan_wins_bachet(4, 3, moves) == true);
    printf("%s: UVa 10404 - Bachet's Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
