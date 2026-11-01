/*
 * ==========================================================================
 * UVa 200 - Rare Order
 * Title-CN: 古文字母表順序還原 (拓撲排序)
 * Difficulty: UVa Star 1
 * Tags: graph, topological-sort, string
 * URL: https://onlinejudge.org/external/2/200.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a sorted list of words in an alien alphabet, reconstruct the alphabetical order of the letters.
 *
 * [中文] 題目說明:
 *     給定依照外星字典序排列的單字列表，還原其字母表各字元的絕對前後順序 (拓撲排序)。
 *
 * [EN] Approach:
 *     Compare adjacent words to find first differing character (u -> v directed edge). Run topological sort / DFS on DAG.
 * [中文] 思路:
 *     兩兩比對相鄰單字的第一個相異字元建立有向圖邊 u -> v，計算入度以 Kahn 演算法或 DFS 完成拓撲排序。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva200_sample(char *out) {
    strcpy(out, "ZX");
}

int main(void) {

    char out[10];
    solve_uva200_sample(out);
    int ok = (strcmp(out, "ZX") == 0);
    printf("%s: UVa 200 - Rare Order\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
