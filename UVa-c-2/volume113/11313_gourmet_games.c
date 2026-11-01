/*
 * ==========================================================================
 * UVa 11313 - Gourmet Games
 * Title-CN: 美食大賽淘汰賽輪數
 * Difficulty: Easy
 * Tags: Math, Simulation
 * URL: https://onlinejudge.org/external/113/11313.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given n contestants and m contestants participating in each game with 1 winner, determine total games to find a champion, or report if impossible.
 *
 * [中文] 題目描述:
 *     給定 n 名選手，每場比賽由 m 人參賽且產生 1 名勝者（淘汰 m-1 人），求決出冠軍所需的總場數，若無法決出則回傳 -1。
 *
 * [EN] Approach:
 *     In each match m-1 contestants are eliminated. Total to eliminate is n-1. If (n-1) % (m-1) == 0, rounds = (n-1)/(m-1), else impossible.
 *
 * [中文] 解題思維:
 *     每場比賽淘汰 m-1 人，總共需淘汰 n-1 人。若 (n-1) % (m-1) == 0 則答案為 (n-1)/(m-1)，否則無法完成淘汰。
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

int solve_11313(int n, int m) {
    if (m <= 1) return -1;
    if ((n - 1) % (m - 1) == 0) return (n - 1) / (m - 1);
    return -1;
}

int main(void) {

    int ok = (solve_11313(5, 2) == 4) &&
             (solve_11313(5, 3) == 2) &&
             (solve_11313(6, 3) == -1);
    printf("%s: UVa 11313 - Gourmet Games\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
