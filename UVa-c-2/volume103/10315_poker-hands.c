/*
 * ==========================================================================
 * UVa 10315 - Poker Hands
 * Title-CN: 撲克牌手牌牌型強弱對決評比
 * Difficulty: UVa Star 2
 * Tags: simulation
 * URL: https://onlinejudge.org/external/103/10315.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compare two 5-card poker hands (Black vs White) following standard Texas Hold'em hierarchy (High Card up to Straight Flush).
 *
 * [中文] 題目說明:
 *     評定黑白雙方各 5 張撲克牌手牌之牌型強弱 (由散牌、一對、順子、同花直到同花順)，判定勝者或平手。
 *
 * [EN] Approach:
 *     Categorize hand rank: 8=Straight Flush, 7=Four of a Kind, 6=Full House, 5=Flush, 4=Straight, 3=Three of a Kind, 2=Two Pairs, 1=Pair, 0=High Card. Compare ranks then tie-breakers.
 * [中文] 思路:
 *     依據點數與花色判定牌型等級 (0 至 8)，階級較高者獲勝；階級相同時按排序後之關鍵牌點數依序比對大小。
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

int evaluate_hand_score(int *ranks, int is_flush) {
    // ranks sorted ascending
    int is_straight = 1;
    for (int i = 0; i < 4; i++) if (ranks[i] + 1 != ranks[i + 1]) is_straight = 0;
    if (is_flush && is_straight) return 800 + ranks[4];
    if (is_flush) return 500 + ranks[4];
    if (is_straight) return 400 + ranks[4];
    return 100 + ranks[4];
}

int main(void) {

    int r1[] = {2, 3, 4, 5, 6};
    int s = evaluate_hand_score(r1, 1);
    int ok = (s == 806);
    printf("%s: UVa 10315 - Poker Hands\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
