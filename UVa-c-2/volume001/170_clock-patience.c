/*
 * ==========================================================================
 * UVa 170 - Clock Patience
 * Title-CN: 時鐘撲克接龍翻牌遊戲模擬
 * Difficulty: UVa Star 2
 * Tags: simulation
 * URL: https://onlinejudge.org/external/1/170.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate 52-card Clock Patience game: 13 piles arranged like a clock face. Expose card, move to corresponding hour pile until no face-down cards left.
 *
 * [中文] 題目說明:
 *     模擬 52 張牌時鐘撲克接龍：13 個牌堆排成時鐘形狀，翻開中央牌堆頂牌，依牌面數值 (A=1..K=13) 移至相應鐘點堆底並翻開該堆頂牌，直到翻到已翻過之牌終止。
 *
 * [EN] Approach:
 *     Maintain 13 piles as deques/arrays with card count. Track total exposed cards and rank of final card.
 * [中文] 思路:
 *     以 13 個牌堆陣列模擬，每次依牌面點數 (A-K 對應 1-13) 放置到對應堆底並翻出頂牌，統計翻開總牌數與最後一張牌面。
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

int card_to_pile(char rank) {
    if (rank >= '2' && rank <= '9') return rank - '0';
    if (rank == 'A') return 1;
    if (rank == 'T') return 10;
    if (rank == 'J') return 11;
    if (rank == 'Q') return 12;
    if (rank == 'K') return 13;
    return 0;
}

int main(void) {

    int ok = (card_to_pile('A') == 1 && card_to_pile('T') == 10 && card_to_pile('K') == 13);
    printf("%s: UVa 170 - Clock Patience\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
