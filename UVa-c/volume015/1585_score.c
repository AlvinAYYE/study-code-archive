/*
 * ==========================================================================
 * UVa 1585 - Score
 * Title-CN: OX 答題連續得分計算
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * ==========================================================================
 * [EN] Problem: Calculate quiz score where consecutive 'O' earns increasing points: 1, 2, 3... and 'X' resets to 0.
 * [中文] 題目說明: OX 答題計分：連續答對 'O' 依序得 1, 2, 3... 分，答錯 'X' 則分數歸零重計，求總得分。
 * [EN] Approach: Linear scan maintaining streak counter.
 * [中文] 思路: 維護連續 streak 計數器累加總分。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva1585(const char *s) {
    int streak = 0, total = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'O') {
            streak++;
            total += streak;
        } else {
            streak = 0;
        }
    }
    return total;
}

int main(void) {
    int ok = (solve_uva1585("OOXXOXXOOO") == 10) && (solve_uva1585("OOXXOOXXOO") == 9);
    printf("%s: UVa 1585 - Score\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
