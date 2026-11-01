/*
 * ==========================================================================
 * UVa 10978 - Let's Play Magic!
 * Title-CN: 玩魔術！ (拼詞數牌撲克牌還原)
 * Difficulty: Easy
 * Tags: Simulation, Array
 * URL: https://onlinejudge.org/external/109/10978.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Reconstruct the initial deck arrangement of N cards from a sequence of (card, word) pairs where each card is placed after counting empty slots by word length.
 *
 * [中文] 題目描述:
 *     根據依單字字母長度數空卡槽放置卡片的過程，還原初始 N 張撲克牌的擺放順序。
 *
 * [EN] Approach:
 *     Start with N empty slots. For each (card, word), advance pointer across unoccupied slots by length(word) positions circularly and place the card.
 *
 * [中文] 解題思維:
 *     建立長度為 N 的空環形陣列，對每張牌依單字字母數在未佔用的空位上循環數步，停步處即為該卡牌位置。
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

void place_magic_cards(int n, const char cards[][5], const char words[][20], char deck[][5]) {
    for (int i = 0; i < n; i++) deck[i][0] = '\0';
    int pos = -1;
    for (int i = 0; i < n; i++) {
        int steps = strlen(words[i]);
        while (steps > 0) {
            pos = (pos + 1) % n;
            if (deck[pos][0] == '\0') steps--;
        }
        strcpy(deck[pos], cards[i]);
    }
}

int main(void) {

    char c[2][5] = {"AH", "KD"}, w[2][20] = {"ONE", "TWO"}, d[2][5];
    place_magic_cards(2, c, w, d);
    int ok = (d[0][0] != '\0' && d[1][0] != '\0');
    printf("%s: UVa 10978 - Let's Play Magic!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
