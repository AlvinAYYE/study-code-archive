/*
 * ==========================================================================
 * UVa 13059 - Tournament
 * Title-CN: 單淘汰錦標賽總比賽場次
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/130/13059.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find total matches played in single-elimination tournament of N players until one champion remains.
 *
 * [中文] 題目說明:
 *     N 名選手進行單淘汰錦標賽，每場比賽淘汰 1 人，直到決出唯一的冠軍，求總共需進行幾場比賽。
 *
 * [EN] Approach:
 *     Each match eliminates exactly 1 player. To eliminate N - 1 players, exactly N - 1 matches are played.
 * [中文] 思路:
 *     每場淘汰賽必有且僅有 1 位淘汰者。要從 N 人決出 1 位冠軍需淘汰 N - 1 人，比賽總場次恆為 N - 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva13059(long long n) {
    return n - 1;
}

int main(void) {

    int ok = (solve_uva13059(2) == 1) && (solve_uva13059(100) == 99);
    printf("%s: UVa 13059 - Tournament\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
