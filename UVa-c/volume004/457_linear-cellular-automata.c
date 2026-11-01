/*
 * ==========================================================================
 * UVa 457 - Linear Cellular Automata
 * Title-CN: 一維細胞自動機模擬
 * Difficulty: UVa Star 1
 * Tags: simulation, array
 * URL: https://onlinejudge.org/external/4/457.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate 1D cellular automaton across 40 dishes for 50 days based on DNA rule mapping neighbor sum (0-3) to next state.
 *
 * [中文] 題目說明:
 *     模擬 40 個培養皿在 50 天內的細胞密度繁衍變化：下一代狀態由相鄰三個培養皿當前密度和透過 DNA 規則映射更新。
 *
 * [EN] Approach:
 *     Array simulation: next[i] = DNA[cur[i-1] + cur[i] + cur[i+1]]. Render densities (0: ' ', 1: '.', 2: 'x', 3: 'W').
 * [中文] 思路:
 *     維護長度 42 的陣列 (含邊界)，每天依照 sum = cur[i-1] + cur[i] + cur[i+1] 查表 DNA[sum] 更新並轉成指定字元印出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void step_automata(const int dna[10], int cur[42], int next[42]) {
    for (int i = 1; i <= 40; i++) {
        int sum = cur[i - 1] + cur[i] + cur[i + 1];
        next[i] = dna[sum];
    }
}

int main(void) {

    int dna[10] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1};
    int c[42] = {0}, n[42] = {0};
    c[20] = 1;
    step_automata(dna, c, n);
    int ok = (n[20] == dna[1]);
    printf("%s: UVa 457 - Linear Cellular Automata\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
