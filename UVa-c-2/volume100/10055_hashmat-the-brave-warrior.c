/*
 * ==========================================================================
 * UVa 10055 - Hashmat the Brave Warrior
 * Title-CN: 勇敢的勇士 Hashmat (絕對差值計算)
 * Difficulty: UVa Star 1 / CPE 49 顆星入門必考題
 * Tags: math, basic-io, 64-bit-integer
 * URL: https://onlinejudge.org/external/100/10055.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     Hashmat is a brave warrior who with his group of young soldiers moves
 *     from one place to another to fight against his opponents. Before fighting,
 *     he just calculates one thing, the difference between his soldiers number
 *     and the opponent's soldier number.
 *     Given the two numbers representing Hashmat's army and his opponent's army,
 *     find the difference between them.
 *
 * [中文] 題目說明:
 *     Hashmat 是一位英勇的戰士，他率領著年輕的士兵穿梭各地與對手戰鬥。
 *     在每場戰鬥之前，他都會計算一件事情：他自己的人數與對手人數之間的差距。
 *     給定兩個整數代表兩軍的人數，求出他們人數之差（絕對值）。
 *     注意：數值可能高達 2^32，必須使用 64 位元整數（long long）。
 *
 * Examples:
 *   Input:
 *     10 12
 *     10 14
 *     100 200
 *   Output:
 *     2
 *     4
 *     100
 *
 * Constraints:
 *   - The numbers are not greater than 2^32.
 *
 * [EN] Approach:
 *     Use unsigned long long or long long and output absolute difference |a - b|.
 * [中文] 思路:
 *     讀入兩數並輸出兩數相減的絕對值。注意數值範圍可能超出 32-bit signed int，需使用 long long。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva10055(long long a, long long b) {
    return (a > b) ? (a - b) : (b - a);
}

int main(void) {
    int ok = 1;
    ok = ok && (solve_uva10055(10, 12) == 2);
    ok = ok && (solve_uva10055(10, 14) == 4);
    ok = ok && (solve_uva10055(100, 200) == 100);
    ok = ok && (solve_uva10055(4294967296LL, 0LL) == 4294967296LL);
    printf("%s: UVa 10055 - Hashmat the Brave Warrior\n", ok ? "PASS" : "FAIL");

    /*
     * For UVa Online Judge submission / UVa 送出模式：
     *
     * long long a, b;
     * while (scanf("%lld %lld", &a, &b) == 2) {
     *     printf("%lld\n", solve_uva10055(a, b));
     * }
     */
    return ok ? 0 : 1;
}
