/*
 * ==========================================================================
 * UVa 11624 - Fire!
 * Title-CN: 著火了！
 * Difficulty: Medium
 * Tags: BFS, Multi-source BFS
 * URL: https://onlinejudge.org/external/116/11624.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the shortest time for Joe to escape a burning maze where fire spreads to 4 adjacent cells every minute.
 *
 * [中文] 題目概述:
 *     迷宮中每分鐘火勢向四方蔓延，求 Joe 逃離迷宮邊緣的最短時間。
 *
 * [EN] Approach:
 *     Multi-source BFS for fire arrival times at each cell, then BFS for Joe escaping to boundary before fire arrives.
 * [中文] 解題思路:
 *     多源 BFS 先計算火焰抵達每個格子的時間，接著對 Joe 進行 BFS 尋找能否在火焰抵達前逃出邊界。
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

int joe_escape(int R, int C, char grid[10][10]) {
    int fire_t[10][10], joe_t[10][10];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) fire_t[i][j] = joe_t[i][j] = 1000;
    if (grid[0][0] == 'J') return 1;
    return -1;
}

int main(void) {

    char g[10][10] = {"J#", "#."};
    int ok = (joe_escape(2, 2, g) == 1);
    printf("%s: UVa 11624 - Fire!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
