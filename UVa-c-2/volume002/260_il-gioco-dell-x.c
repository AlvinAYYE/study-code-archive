/*
 * ==========================================================================
 * UVa 260 - Il Gioco dell'X
 * Title-CN: 六角棋連通勝利判定 (Hex Game BFS)
 * Difficulty: UVa Star 1
 * Tags: graph, bfs, flood-fill
 * URL: https://onlinejudge.org/external/2/260.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if Black wins (connecting top to bottom) or White wins (connecting left to right) on n x n Hex board.
 *
 * [中文] 題目說明:
 *     在 n x n 六角網格棋盤中，判定是黑棋連通頂部與底部獲勝，還是白棋連通左側與右側獲勝。
 *
 * [EN] Approach:
 *     Flood fill BFS from all top-row black stones. If any path reaches bottom row, Black wins; otherwise White wins.
 * [中文] 思路:
 *     對第一列的所有黑棋進行 6 方向廣度優先搜尋 (BFS)，若能抵達最後一列則黑棋獲勝，否則白棋獲勝。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva260_black_wins(int n, char board[205][205]) {
    int q[40005][2];
    int head = 0, tail = 0;
    int visited[205][205] = {0};
    int dr[6] = {-1, -1, 0, 0, 1, 1};
    int dc[6] = {-1, 0, -1, 1, 0, 1};
    for (int c = 0; c < n; c++) {
        if (board[0][c] == 'b') {
            q[tail][0] = 0; q[tail++][1] = c;
            visited[0][c] = 1;
        }
    }
    while (head < tail) {
        int r = q[head][0], c = q[head++][1];
        if (r == n - 1) return 1;
        for (int i = 0; i < 6; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && board[nr][nc] == 'b') {
                visited[nr][nc] = 1;
                q[tail][0] = nr; q[tail++][1] = nc;
            }
        }
    }
    return 0;
}

int main(void) {

    char b[4][205] = {"bbbb", "bbbb", "bbbb", "bbbb"};
    int ok = (solve_uva260_black_wins(4, b) == 1);
    printf("%s: UVa 260 - Il Gioco dell'X\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
