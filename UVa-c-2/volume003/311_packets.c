/*
 * ==========================================================================
 * UVa 311 - Packets
 * Title-CN: 裝箱問題 (貪婪裝入 6x6 箱子)
 * Difficulty: UVa Star 2
 * Tags: greedy, math
 * URL: https://onlinejudge.org/external/3/311.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given quantities of 1x1 through 6x6 items, find minimum number of 6x6 parcels needed to pack them.
 *
 * [中文] 題目說明:
 *     給定尺寸 1x1 至 6x6 的六種包裹數量，求最少需要多少個 6x6 的大箱子才能全部裝下。
 *
 * [EN] Approach:
 *     Greedy strategy from largest (6x6) to smallest (1x1). Fill leftover gaps with smaller items.
 * [中文] 思路:
 *     由大到小貪婪裝箱：6x6 各自一箱；5x5 剩餘空間填 1x1；4x4 剩餘填 2x2 再填 1x1；3x3 每 4 個一箱，餘數用 2x2 與 1x1 填滿。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva311(int p[7]) {
    int total = p[6] + p[5] + p[4] + (p[3] + 3) / 4;
    int space2 = p[4] * 5;
    if (p[3] % 4 == 1) space2 += 5;
    else if (p[3] % 4 == 2) space2 += 3;
    else if (p[3] % 4 == 3) space2 += 1;
    if (p[2] > space2) total += (p[2] - space2 + 8) / 9;
    return total;
}

int main(void) {

    int p[7] = {0, 0, 0, 0, 4, 0, 2};
    int ok = (solve_uva311(p) == 6);
    printf("%s: UVa 311 - Packets\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
