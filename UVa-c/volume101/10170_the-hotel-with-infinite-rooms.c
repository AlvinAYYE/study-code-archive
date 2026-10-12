/*
 * ==========================================================================
 * UVa 10170 - The Hotel with Infinite Rooms
 * Title-CN: 無限房間的旅館
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/101/10170.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Group sizes are S, S+1, S+2..., each group stays for its size in days.
 *     Find group size at day D.
 *
 * [中文] 題目說明:
 *     團體大小為 S, S+1, S+2...，每個團體住的人數與天數相同。求第 D 天由哪個大小的團入住。
 *
 * [EN] Approach: Increment S and accumulate days until days >= D.
 * [中文] 思路: 模擬天數累加：while (D > S) { D -= S; S++; } return S。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva10170(long long s, long long d) {
    while (d > s) {
        d -= s;
        s++;
    }
    return s;
}

int main(void) {
    int ok = (solve_uva10170(1, 6) == 3) && (solve_uva10170(3, 10) == 5);
    printf("%s: UVa 10170 - The Hotel with Infinite Rooms\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
