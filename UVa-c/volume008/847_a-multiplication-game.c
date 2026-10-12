/*
 * ==========================================================================
 * UVa 847 - A Multiplication Game
 * Title-CN: 乘法博弈遊戲
 * Difficulty: UVa Star 1
 * Tags: math, game-theory
 * ==========================================================================
 * [EN] Problem: Game starting at p=1, multiply by 2..9 in turns. Winner reaches >= n.
 * [中文] 題目說明: 乘法遊戲由 p=1 開始，兩人輪流乘上 2~9，最先使數值 >= n 者獲勝。
 * [EN] Approach: Stan wins intervals: [2..9], [19..162], etc. Divide n by 18, check if <= 9.
 * [中文] 思路: 區間對策論，每次除以 9 再除以 2（除以 18），若當前剩餘值 <= 9 則 Stan 獲勝。
 * ==========================================================================
 */
#include <stdio.h>

const char *solve_uva847(long long n) {
    long long p = 1;
    while (1) {
        p *= 9;
        if (p >= n) return "Stan wins.";
        p *= 2;
        if (p >= n) return "Ollie wins.";
    }
}

int main(void) {
    int ok = (solve_uva847(17)[0] == 'O') && (solve_uva847(340)[0] == 'S');
    printf("%s: UVa 847 - A Multiplication Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
