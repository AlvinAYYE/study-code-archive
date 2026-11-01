/*
 * ==========================================================================
 * UVa 489 - Hangman Judge
 * Title-CN: 吊死鬼猜單字裁判
 * Difficulty: UVa Star 1
 * Tags: simulation, string
 * URL: https://onlinejudge.org/external/4/489.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate Hangman word game: player wins if all distinct letters guessed, loses if 7 wrong strokes accumulated.
 *
 * [中文] 題目說明:
 *     模擬吊死鬼猜字遊戲：7 次猜錯機會。在累計 7 次錯誤前猜出所有相異字母則勝；累積 7 次錯則負；中途放棄判定未結束。
 *
 * [EN] Approach:
 *     Track guessed letters. Correct guess decrements unique letter count; wrong new guess increments stroke count. Stop on win/loss.
 * [中文] 思路:
 *     標記已猜字母避免重複扣分。猜中相異字母則剩餘需猜數減 1，猜錯則錯誤計數加 1，達 7 次立即判負。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva489(const char *sol, const char *guess) {
    int needed[26] = {0};
    int rem = 0;
    for (int i = 0; sol[i]; i++) {
        if (!needed[sol[i] - 'a']) { needed[sol[i] - 'a'] = 1; rem++; }
    }
    int stroke = 0;
    int tried[26] = {0};
    for (int i = 0; guess[i]; i++) {
        int c = guess[i] - 'a';
        if (tried[c]) continue;
        tried[c] = 1;
        if (needed[c]) {
            rem--;
            if (rem == 0) return 1; /* Win */
        } else {
            stroke++;
            if (stroke >= 7) return -1; /* Lose */
        }
    }
    return 0; /* Chickened out */
}

int main(void) {

    int ok = (solve_uva489("cheese", "chese") == 1) && (solve_uva489("cheese", "abdfgij") == -1);
    printf("%s: UVa 489 - Hangman Judge\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
