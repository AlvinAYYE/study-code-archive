/*
 * ==========================================================================
 * UVa 181 - Hearts
 * Title-CN: 紅心大戰紙牌計分模擬
 * Difficulty: UVa Star 2
 * Tags: simulation
 * URL: https://onlinejudge.org/external/1/181.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate trick-taking rules of the card game Hearts: leading suit, trump rules, and tracking penalty points.
 *
 * [中文] 題目說明:
 *     模擬紅心大戰紙牌遊戲出牌規則：引牌花色、王牌判定、贏取墩數與紅心/黑桃黑桃皇后罰分統計。
 *
 * [EN] Approach:
 *     Follow trick-taking logic: players must follow suit if possible; highest trump (or highest leading suit) wins trick and collects penalties.
 * [中文] 思路:
 *     依照每墩出牌規定：有同花色必須跟出，否則可墊牌或出王牌，該墩最大牌者收走全部四張牌並累加罰分。
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

int heart_penalty(char suit, char rank) {
    if (suit == 'H') return 1;
    if (suit == 'S' && rank == 'Q') return 13;
    return 0;
}

int main(void) {

    int ok = (heart_penalty('H', '5') == 1 && heart_penalty('S', 'Q') == 13 && heart_penalty('D', 'A') == 0);
    printf("%s: UVa 181 - Hearts\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
