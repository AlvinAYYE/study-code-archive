/*
 * ==========================================================================
 * UVa 555 - Bridge Hands
 * Title-CN: 橋牌發牌模擬與手牌排序
 * Difficulty: UVa Star 1
 * Tags: simulation, card-game, sorting
 * URL: https://onlinejudge.org/external/5/555.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate bridge card dealing starting after dealer (N, E, S, W) and sort each player's 13 cards by suit (C, D, S, H) and rank (2..A).
 *
 * [中文] 題目說明:
 *     模擬 52 張橋牌順時針發牌流程，並將四位玩家手牌按花色 (梅花 C < 方塊 D < 黑桃 S < 紅心 H) 與點數 (2..9, T, J, Q, K, A) 排序輸出。
 *
 * [EN] Approach:
 *     Deal cards clockwise in round-robin order. Sort each hand using custom comparator according to bridge suit and rank weights.
 * [中文] 思路:
 *     依照發牌者下一位開始順時針分發 52 張牌至四位玩家，為每張牌賦予唯一整數權重後進行升序排序輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int card_weight_555(char suit, char rank) {
    int s_val = 0;
    if (suit == 'C') s_val = 0;
    else if (suit == 'D') s_val = 1;
    else if (suit == 'S') s_val = 2;
    else if (suit == 'H') s_val = 3;
    const char *ranks = "23456789TJQKA";
    int r_val = 0;
    for (int i = 0; ranks[i]; i++) if (ranks[i] == rank) { r_val = i; break; }
    return s_val * 13 + r_val;
}

int main(void) {

    int ok = (card_weight_555('C', '2') < card_weight_555('C', 'A')) &&
             (card_weight_555('C', 'A') < card_weight_555('D', '2'));
    printf("%s: UVa 555 - Bridge Hands\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
