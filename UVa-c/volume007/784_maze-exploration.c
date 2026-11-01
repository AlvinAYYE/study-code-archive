/*
 * ==========================================================================
 * UVa 784 - Maze Exploration
 * Title-CN: 迷宮探索填色 (四方向連通 DFS 塗色)
 * Difficulty: UVa Star 1
 * Tags: graph, flood-fill, dfs
 * URL: https://onlinejudge.org/external/7/784.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given maze of walls, start at '*' and color all connected empty spaces with '#'.
 *
 * [中文] 題目說明:
 *     在帶有不規則圍牆的迷宮中，由起點 '*' 開始向上下左右四方向走訪，將所有可達的空白格全部塗為 '#'。
 *
 * [EN] Approach:
 *     Standard flood fill DFS/BFS: replace empty ' ' and start '*' with '#'. Stop on wall characters.
 * [中文] 思路:
 *     四方向深度優先搜尋 (DFS) 洪水填充：遇空格與起點置換為 '#'，遇任何邊界或圍牆字元停止擴展。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void dfs_maze_784(int r, int c, char maze[35][85]) {
    maze[r][c] = '#';
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (maze[nr][nc] == ' ') {
            dfs_maze_784(nr, nc, maze);
        }
    }
}

int main(void) {

    char m[35][85] = {"XXXXX", "X * X", "XXXXX"};
    dfs_maze_784(1, 2, m);
    int ok = (m[1][2] == '#' && m[1][1] == '#');
    printf("%s: UVa 784 - Maze Exploration\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
