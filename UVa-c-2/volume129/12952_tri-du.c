/*
 * ==========================================================================
 * UVa 12952 - Tri-du
 * Title-CN: Tri-du 紙牌遊戲最優第三張牌
 * Difficulty: UVa Star 1
 * Tags: math, greedy
 * URL: https://onlinejudge.org/external/129/12952.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two cards A and B, determine third card C to maximize probability of getting a Three-of-a-kind or Pair with highest rank.
 *
 * [中文] 題目說明:
 *     在 Tri-du 撲克遊戲中已知兩張手牌 A 與 B，挑選第三張牌 C 使牌型最優 (若 A==B 選 A 組成三條，否則選 max(A, B) 組成大對子)。
 *
 * [EN] Approach:
 *     If A == B pick A; else pick max(A, B). Mathematically always max(A, B).
 * [中文] 思路:
 *     貪婪勝率最大化：若兩張相同則選同點數組成三條；若不同則選較大者組成較大的對子。結果恆為 max(A, B)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva12952(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {

    int ok = (solve_uva12952(10, 10) == 10) && (solve_uva12952(2, 5) == 5);
    printf("%s: UVa 12952 - Tri-du\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
