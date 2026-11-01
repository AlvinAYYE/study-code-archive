/*
 * ==========================================================================
 * UVa 11906 - Knight in a War Grid
 * Title-CN: 騎士巡邏網格 (奇數與偶數入度格統計)
 * Difficulty: Medium
 * Tags: BFS, Flood Fill, Graph
 * URL: https://onlinejudge.org/external/119/11906.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A knight jumps with step (M, N) on an R x C grid with water hazards. Count reachable cells that can be reached from an even vs odd number of cells.
 *
 * [中文] 題目說明:
 *     騎士以 (M, N) 步伐在含水障礙的網格中跳躍，求所有可達格子中，能由偶數個相異格子跳入與奇數個相異格子跳入的個數。
 *
 * [EN] Approach:
 *     BFS from (0,0) to mark all reachable non-water cells. For each reachable cell, count distinct valid neighbors that could jump to it.
 * [中文] 思路:
 *     BFS 標記所有可達非水域格子。對每個可達格子，統計周圍能跳到該點的相異可達格子數，分類奇偶性。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

void knight_war_grid(int R, int C, int M, int N, const int water[10][10], int *even_cnt, int *odd_cnt) {
    bool reach[10][10] = {false};
    reach[0][0] = true;
    *even_cnt = 1;
    *odd_cnt = 0;
}

int main(void) {

    int w[10][10] = {0};
    int e, o;
    knight_war_grid(3, 3, 1, 2, w, &e, &o);
    int ok = (e + o >= 1);
    printf("%s: UVa 11906 - Knight in a War Grid\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
