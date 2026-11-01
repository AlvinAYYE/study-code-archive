/*
 * ==========================================================================
 * UVa 11352 - Crazy King
 * Title-CN: 瘋狂國王 (閃避騎士的最短步數)
 * Difficulty: Medium
 * Tags: Graph, BFS, Chess
 * URL: https://onlinejudge.org/external/113/11352.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum King moves from A to B on a chessboard avoiding enemy knights 'Z' and their attacked squares.
 *
 * [中文] 題目描述:
 *     在有敵方騎士 'Z' 的棋盤上，求國王從 'A' 走到 'B' 的最少步數，且不得踩到騎士及其攻擊格。
 *
 * [EN] Approach:
 *     Mark knight attacked squares as blocked (except 'A' and 'B'). Run 8-directional BFS from 'A' to 'B'.
 *
 * [中文] 解題思維:
 *     先標記所有騎士能攻擊到的格子為障礙物（但不得阻擋起點 A 與終點 B），再使用 8 方向 BFS 求最短路徑步數。
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

static const int kx_11352[] = {-2, -2, -1, -1, 1, 1, 2, 2};
static const int ky_11352[] = {-1, 1, -2, 2, -2, 2, -1, 1};
static const int king_dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
static const int king_dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int min_king_moves(int R, int C, const char board[105][105]) {
    int ax = -1, ay = -1, bx = -1, by = -1;
    int danger[105][105];
    memset(danger, 0, sizeof(danger));

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == 'A') { ax = r; ay = c; }
            if (board[r][c] == 'B') { bx = r; by = c; }
            if (board[r][c] == 'Z') {
                danger[r][c] = 1;
                for (int d = 0; d < 8; d++) {
                    int nr = r + kx_11352[d], nc = c + ky_11352[d];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                        danger[nr][nc] = 1;
                    }
                }
            }
        }
    }
    danger[ax][ay] = 0;
    danger[bx][by] = 0;

    int dist[105][105];
    memset(dist, -1, sizeof(dist));
    int qx[105 * 105], qy[105 * 105], head = 0, tail = 0;
    dist[ax][ay] = 0;
    qx[tail] = ax; qy[tail] = ay; tail++;

    while (head < tail) {
        int x = qx[head], y = qy[head]; head++;
        if (x == bx && y == by) return dist[x][y];
        for (int d = 0; d < 8; d++) {
            int nx = x + king_dx[d], ny = y + king_dy[d];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && !danger[nx][ny] && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                qx[tail] = nx; qy[tail] = ny; tail++;
            }
        }
    }
    return -1;
}

int main(void) {

    char b[105][105] = {
        ".A.",
        "...",
        ".B."
    };
    int res = min_king_moves(3, 3, b);
    int ok = (res == 2);
    printf("%s: UVa 11352 - Crazy King\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
