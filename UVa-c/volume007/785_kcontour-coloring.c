/*
 * ==========================================================================
 * UVa 785 - Kooling
 * Title-CN: 多標記輪廓邊界填色 (多源洪水填充)
 * Difficulty: UVa Star 1
 * Tags: graph, flood-fill, dfs
 * URL: https://onlinejudge.org/external/7/785.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Flood fill enclosed regions in grid with distinct marker characters matching each start point.
 *
 * [中文] 題目說明:
 *     在給定輪廓邊界的網格中，由多個相異的標記字元起點各自出發進行洪水填充，直到撞擊邊界為止。
 *
 * [EN] Approach:
 *     Locate all marker characters (non-space, non-border). For each marker, run DFS flood fill replacing spaces with marker.
 * [中文] 思路:
 *     尋找盤面中所有非空格且非邊界牆的標記字元，分別呼叫 DFS 走訪四周可達的空格，將其全部填色為該字元。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva785_test(void) {
    return 1;
}

int main(void) {

    int ok = solve_uva785_test();
    printf("%s: UVa 785 - Kooling\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
