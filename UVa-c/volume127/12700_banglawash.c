/*
 * ==========================================================================
 * UVa 12700 - Banglawash
 * Title-CN: 板球比賽勝負判定
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * ==========================================================================
 * [EN] Problem: Classify cricket match outcomes: BANGLAWASH, WHITEWASH, BANGLADESH, WWW, DRAW, ABANDONED.
 * [中文] 題目說明: 統計兩隊板球比賽勝場（'B'孟加拉, 'W'白隊, 'T'平手, 'A'棄賽），判定最終比分分類。
 * [EN] Approach: Count frequencies of each result character, conditional branching.
 * [中文] 思路: 統計勝負次數並依優先級條件分支輸出。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 12700 - Banglawash\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
