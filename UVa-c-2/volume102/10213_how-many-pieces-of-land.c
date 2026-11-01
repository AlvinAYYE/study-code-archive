/*
 * ==========================================================================
 * UVa 10213 - How Many Pieces of Land ?
 * Title-CN: 多少塊土地？
 * Difficulty: Medium
 * Tags: Math, Combinatorics, Euler Formula
 * URL: https://onlinejudge.org/external/102/10213.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given n points on a circle connected by chords with no 3 intersecting at a point, find the maximum number of pieces of land.
 *
 * [中文] 題目概述:
 *     圓周上有 n 個點，任兩點連一條弦且無三弦共點，求圓被切成的最大區域數量。
 *
 * [EN] Approach:
 *     By Euler's formula V - E + F = 1: Pieces = 1 + C(n, 2) + C(n, 4) = 1 + n*(n-1)/2 + n*(n-1)*(n-2)*(n-3)/24.
 * [中文] 解題思路:
 *     由尤拉公式可得切割區域數為 1 + C(n, 2) + C(n, 4) = 1 + n*(n-1)/2 + n*(n-1)*(n-2)*(n-3)/24。
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

long long pieces_of_land(long long n) {
    if (n == 0) return 1;
    long long c2 = n * (n - 1) / 2;
    long long c4 = n * (n - 1) * (n - 2) * (n - 3) / 24;
    return 1 + c2 + c4;
}

int main(void) {

    int ok = (pieces_of_land(1) == 1) && (pieces_of_land(2) == 2) && (pieces_of_land(4) == 8);
    printf("%s: UVa 10213 - How Many Pieces of Land ?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
