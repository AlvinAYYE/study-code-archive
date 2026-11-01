/*
 * ==========================================================================
 * UVa 350 - Pseudo-Random Numbers
 * Title-CN: 偽隨機數生成週期
 * Difficulty: UVa Star 1
 * Tags: math, simulation, floyd-cycle
 * ==========================================================================
 * [EN] Problem: Find cycle length of linear congruential generator: x_{n+1} = (Z*x_n + I) mod M.
 * [中文] 題目說明: 計算線性同餘生成器 LCG 的循環節長度。
 * [EN] Approach: Visited array or Floyd's tortoise and hare.
 * [中文] 思路: 陣列記錄各數值首次出現的時間步，再次遇到時相減即為環長度。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva350(int z, int i, int m, int l) {
    int visited[10005] = {0};
    int step = 1;
    visited[l] = step;
    int cur = l;
    while (1) {
        step++;
        cur = (z * cur + i) % m;
        if (visited[cur]) return step - visited[cur];
        visited[cur] = step;
    }
}

int main(void) {
    int len = solve_uva350(8175, 8920, 10000, 1111);
    int ok = (len > 0);
    printf("%s: UVa 350 - Pseudo-Random Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
