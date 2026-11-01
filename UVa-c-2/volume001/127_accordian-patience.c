/*
 * ==========================================================================
 * UVa 127 - "Accordian" Patience
 * Title-CN: 手風琴接龍紙牌模擬
 * Difficulty: UVa Star 2
 * Tags: simulation, stack, card-game
 * URL: https://onlinejudge.org/external/1/127.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate 52-card Accordian patience game: move card onto left 1st or 3rd pile if same suit or rank.
 *
 * [中文] 題目說明:
 *     模擬 52 張紙牌手風琴接龍：若與左邊第 1 疊或第 3 疊花色或點數相同，優先將牌堆向左疊合。
 *
 * [EN] Approach:
 *     Maintain 52 stacks. Greedy simulation: scan from left to right, check left 3 then left 1, move and restart from left.
 * [中文] 思路:
 *     維護牌堆串列或陣列堆疊。由左至右掃描，優先匹配左方第 3 疊，否則匹配左方第 1 疊，一旦移動即重頭掃描。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva127_match(const char *c1, const char *c2) {
    return (c1[0] == c2[0] || c1[1] == c2[1]);
}

int main(void) {

    int ok = solve_uva127_match("QH", "QD") && solve_uva127_match("7H", "8H") && !solve_uva127_match("7H", "8S");
    printf("%s: UVa 127 - Accordian Patience\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
