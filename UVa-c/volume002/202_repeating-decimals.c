/*
 * ==========================================================================
 * UVa 202 - Repeating Decimals
 * Title-CN: 循環小數與循環節長度
 * Difficulty: UVa Star 2
 * Tags: math, simulation, cycle-detection
 * URL: https://onlinejudge.org/external/2/202.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given fraction a/b, find its decimal representation, mark repeating cycle with brackets, and output cycle length.
 *
 * [中文] 題目說明:
 *     給定分數 a/b，計算其十進位小數表示法，以括號標註循環節並輸出循環節長度。
 *
 * [EN] Approach:
 *     Long division simulation. Store remainder positions in an array. When a remainder repeats, cycle starts there.
 * [中文] 思路:
 *     模擬長除法除算過程，以陣列記錄每個餘數第一次出現的商數位元位置，餘數重複出現處即為循環節起始。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva202_cycle_len(int a, int b) {
    int pos[3005] = {0};
    int rem = a % b;
    int cur_pos = 1;
    while (rem != 0 && pos[rem] == 0) {
        pos[rem] = cur_pos++;
        rem = (rem * 10) % b;
    }
    if (rem == 0) return 1;
    return cur_pos - pos[rem];
}

int main(void) {

    int ok = (solve_uva202_cycle_len(1, 3) == 1) && (solve_uva202_cycle_len(1, 7) == 6);
    printf("%s: UVa 202 - Repeating Decimals\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
