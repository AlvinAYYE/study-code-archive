/*
 * ==========================================================================
 * UVa 439 - Knight Moves
 * Title-CN: 西洋棋騎士最短步數
 * Difficulty: UVa Star 1
 * Tags: graph, bfs, shortest-path
 * ==========================================================================
 * [EN] Problem: Minimum knight moves between two squares on an 8x8 chessboard.
 * [中文] 題目說明: 求西洋棋騎士從起點走到終點所需的最少步數。
 * [EN] Approach: Standard BFS on 8x8 board with 8 knight move vectors.
 * [中文] 思路: 8x8 棋盤廣度優先搜尋 (BFS)，騎士 8 個日字跳躍方向。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static const int dr[8] = {-2, -2, -1, -1,  1,  1,  2,  2};
static const int dc[8] = {-1,  1, -2,  2, -2,  2, -1,  1};

int solve_uva439(const char *from, const char *to) {
    int sr = from[1] - '1', sc = from[0] - 'a';
    int tr = to[1] - '1', tc = to[0] - 'a';
    if (sr == tr && sc == tc) return 0;

    int dist[8][8];
    memset(dist, -1, sizeof(dist));
    dist[sr][sc] = 0;

    int q[64][2], head = 0, tail = 0;
    q[tail][0] = sr; q[tail++][1] = sc;

    while (head < tail) {
        int r = q[head][0], c = q[head++][1];
        if (r == tr && c == tc) return dist[r][c];
        for (int d = 0; d < 8; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q[tail][0] = nr; q[tail++][1] = nc;
            }
        }
    }
    return -1;
}

int main(void) {
    int moves = solve_uva439("e2", "e4");
    int ok = (moves == 2);
    printf("%s: UVa 439 - Knight Moves\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
