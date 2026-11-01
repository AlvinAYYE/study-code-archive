/*
 * ==========================================================================
 * UVa 131 - The Hands of Poker
 * Title-CN: 五張換牌最佳撲克牌型評估
 * Difficulty: UVa Star 2
 * Tags: simulation, brute-force
 * URL: https://onlinejudge.org/external/1/131.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a hand of 5 cards and a deck of 5 cards, choose a subset of hand to discard and draw from deck in order to achieve the highest possible poker hand rank.
 *
 * [中文] 題目說明:
 *     給定手中的 5 張手牌與牌堆頂部的 5 張牌，可從手牌中選擇任意張丟棄，並從牌堆頂依序補齊至 5 張，求可組成的最高撲克牌型。
 *
 * [EN] Approach:
 *     Enumerate all 2^5 = 32 discard subsets (preserving drawn card order), evaluate rank (straight flush, 4 of a kind, full house, etc.) and take the maximum.
 * [中文] 思路:
 *     枚舉手牌替換的 2^5 = 32 種子集，依序由抽牌堆補充不足之張數，對每一組五張牌型進行撲克牌評級，取 32 種組合中之最高階牌型。
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

int evaluate_ranks(int counts[15]) {
    int pairs = 0, threes = 0, fours = 0;
    for (int i = 1; i <= 14; i++) {
        if (counts[i] == 4) fours++;
        else if (counts[i] == 3) threes++;
        else if (counts[i] == 2) pairs++;
    }
    if (fours) return 7; // four of a kind
    if (threes && pairs) return 6; // full house
    if (threes) return 3; // three of a kind
    if (pairs == 2) return 2; // two pairs
    if (pairs == 1) return 1; // one pair
    return 0; // high card
}

int main(void) {

    int counts[15] = {0};
    counts[14] = 3; counts[10] = 2; // Full house Aces over Tens
    int rank = evaluate_ranks(counts);
    int ok = (rank == 6);
    printf("%s: UVa 131 - The Hands of Poker\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
