/*
 * ==========================================================================
 * UVa 10368 - Euclid's Game
 * Title-CN: 歐幾里得博弈
 * Difficulty: Medium
 * Tags: Game Theory, Math, GCD
 * URL: https://onlinejudge.org/external/103/10368.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Stan and Ollie play a game subtracting multiples of smaller number from larger. First to reach 0 wins.
 *
 * [中文] 題目說明:
 *     兩人輪流從大數中減去小數的整數倍，最先使某數變為 0 者獲勝，判定先手 Stan 是否獲勝。
 *
 * [EN] Approach:
 *     If a % b == 0, current player wins. If a / b >= 2, current player can force a win by choosing whether to leave (b, a%b) or (a%b + b, b). Otherwise single move forced.
 * [中文] 思路:
 *     若 a % b == 0 則當前玩家勝；若 a / b >= 2 則當前玩家擁有選擇權必勝；否則只能執行唯一一步 a - b，交替輪轉局面。
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

bool stan_wins_euclid(long long a, long long b) {
    if (a < b) { long long t = a; a = b; b = t; }
    bool stan_turn = true;
    while (b > 0) {
        if (a % b == 0 || a / b >= 2) return stan_turn;
        a -= b;
        long long t = a; a = b; b = t;
        stan_turn = !stan_turn;
    }
    return stan_turn;
}

int main(void) {

    int ok = stan_wins_euclid(34, 12); // 34/12 = 2 >= 2 -> first player wins
    printf("%s: UVa 10368 - Euclid's Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
