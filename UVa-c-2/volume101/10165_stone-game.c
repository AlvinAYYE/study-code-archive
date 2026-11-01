/*
 * ==========================================================================
 * UVa 10165 - Stone Game
 * Title-CN: 尼姆博弈 (石子遊戲)
 * Difficulty: Easy
 * Tags: Game Theory, Nim Sum
 * URL: https://onlinejudge.org/external/101/10165.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if the first player has a winning strategy in a standard game of Nim with n piles of stones.
 *
 * [中文] 題目說明:
 *     判斷先手在有 n 堆石子的標準尼姆 (Nim) 博弈中是否具備必勝策略。
 *
 * [EN] Approach:
 *     Bouton's Theorem: First player wins if and only if the XOR sum of all pile sizes is non-zero.
 * [中文] 思路:
 *     由尼姆博弈博通定理 (Bouton's Theorem)，先手必勝若且唯若所有石子堆數量的異或和 (Nim-sum) 不為 0。
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

bool nim_first_player_wins(int n, const int *piles) {
    int xor_sum = 0;
    for (int i = 0; i < n; i++) xor_sum ^= piles[i];
    return xor_sum != 0;
}

int main(void) {

    int p1[] = {1, 2, 3}; // 1 ^ 2 ^ 3 = 0 (loss)
    int p2[] = {1, 2, 4}; // 1 ^ 2 ^ 4 != 0 (win)
    int ok = !nim_first_player_wins(3, p1) && nim_first_player_wins(3, p2);
    printf("%s: UVa 10165 - Stone Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
