/*
 * ==========================================================================
 * UVa 130 - Roman Roulette
 * Title-CN: 羅馬輪盤 (約瑟夫環換位變形)
 * Difficulty: UVa Star 2
 * Tags: simulation, josephus
 * URL: https://onlinejudge.org/external/1/130.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Josephus variant: the k-th person eliminated is replaced by the next k-th person. Find starting position for survivor 1.
 *
 * [中文] 題目說明:
 *     約瑟夫環變形：第 k 個被數到的人被處決後，由接下來數到的第 k 個人替補其位置。求使 1 號存活的起始者位置。
 *
 * [EN] Approach:
 *     Circular array simulation. Shift starting offset until the survivor is person 1.
 * [中文] 思路:
 *     以循環陣列模擬淘汰與遞補換位流程。由 1 到 n 嘗試起始點，直到最後存活者為 1 號。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int run_josephus_130(int n, int k, int start) {
    int alive[105];
    for (int i = 0; i < n; i++) alive[i] = i + 1;
    int cur = (start - 1 + n) % n;
    int rem = n;
    while (rem > 1) {
        cur = (cur + k - 1) % rem;
        int victim_pos = cur;
        int bury = (victim_pos + k - 1) % (rem - 1);
        int replacer = alive[bury >= victim_pos ? bury + 1 : bury];
        int r_idx = 0;
        for (int i = 0; i < rem; i++) {
            if (alive[i] == replacer) { r_idx = i; break; }
        }
        for (int i = r_idx; i < rem - 1; i++) alive[i] = alive[i + 1];
        rem--;
        if (victim_pos > r_idx) victim_pos--;
        alive[victim_pos] = replacer;
        cur = (victim_pos + 1) % rem;
    }
    return alive[0];
}

int solve_uva130(int n, int k) {
    for (int s = 1; s <= n; s++) {
        if (run_josephus_130(n, k, s) == 1) return s;
    }
    return 1;
}

int main(void) {

    int ok = (solve_uva130(5, 2) == 3);
    printf("%s: UVa 130 - Roman Roulette\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
