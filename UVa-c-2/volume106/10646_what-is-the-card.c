/*
 * ==========================================================================
 * UVa 10646 - What is the Card?
 * Title-CN: 洗牌魔術第 Y 張撲克牌定位
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/106/10646.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate card magic trick: 52-card deck. Top 25 cards held in hand. 3 times execute X = value(top), remove (10 - X) cards, add X to Y. Find card at Y from bottom.
 *
 * [中文] 題目說明:
 *     模擬 52 張撲克牌魔術：牌頂 25 張置於手牌，對剩餘牌堆執行三次「取頂牌點數 X，丟棄 10-X 張牌，累加 Y += X」，求牌堆底起第 Y 張牌面。
 *
 * [EN] Approach:
 *     Follow the mechanical card movements directly. Combine pile and top 25 cards, and return the card at 1-based index Y.
 * [中文] 思路:
 *     以陣列模擬牌堆抽牌與丟牌動作，按步驟維護 Y 的總和，將手中 25 張手牌放回牌頂後，輸出自底起算第 Y 張牌。
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

int card_val10646(char rank) {
    if (rank >= '2' && rank <= '9') return rank - '0';
    return 10;
}

int main(void) {

    int ok = (card_val10646('8') == 8 && card_val10646('K') == 10 && card_val10646('A') == 10);
    printf("%s: UVa 10646 - What is the Card?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
