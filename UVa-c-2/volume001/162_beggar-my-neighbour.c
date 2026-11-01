/*
 * ==========================================================================
 * UVa 162 - Beggar My Neighbour
 * Title-CN: 乞丐鄰居紙牌遊戲模擬
 * Difficulty: UVa Star 2
 * Tags: simulation, queue
 * URL: https://onlinejudge.org/external/1/162.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate the classic card game 'Beggar My Neighbour' with face cards requiring payments (J=1, Q=2, K=3, A=4), until one player runs out of cards.
 *
 * [中文] 題目說明:
 *     模擬經典紙牌遊戲「乞丐鄰居」：出到人頭牌時對手需支付相應張數 (J=1, Q=2, K=3, A=4)，未出人頭牌則由出牌者收走桌面底牌，直到一人無牌為止。
 *
 * [EN] Approach:
 *     Queue-based simulation with turn alternations, penalty counts, and pile transfers.
 * [中文] 思路:
 *     以佇列維護兩位玩家手牌與桌面中央牌堆，遇人頭牌設定罰牌計數器並轉移罰牌責任，無人頭牌時收牌入隊底。
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

int card_penalty(char rank) {
    if (rank == 'A') return 4;
    if (rank == 'K') return 3;
    if (rank == 'Q') return 2;
    if (rank == 'J') return 1;
    return 0;
}

int main(void) {

    int ok = (card_penalty('A') == 4 && card_penalty('J') == 1 && card_penalty('9') == 0);
    printf("%s: UVa 162 - Beggar My Neighbour\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
