/*
 * ==========================================================================
 * UVa 314 - Robot
 * Title-CN: 機器人網格最短路徑
 * Difficulty: Medium
 * Tags: Graph, BFS, Shortest Path
 * URL: https://onlinejudge.org/external/3/314.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum time for a robot to navigate a grid with obstacle blocks by moving forward 1-3 steps or turning.
 *
 * [中文] 題目描述:
 *     在帶障礙物的方格網中，求機器人從起點沿格線行走到終點所需的最少時間（可前進 1~3 格，或左右轉 90 度）。
 *
 * [EN] Approach:
 *     BFS with state (r, c, dir). Robot is located on intersections of grid lines; blocks occupy grid squares.
 *
 * [中文] 解題思維:
 *     以 (r, c, 方向) 為狀態進行 BFS，注意機器人是在頂點行進，若相鄰的 4 個格子中有障礙物則該交點不可通行。
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

static const int dr314[] = {-1, 0, 1, 0}; // 0: north, 1: east, 2: south, 3: west
static const int dc314[] = {0, 1, 0, -1};

int min_time_robot(int R, int C, int grid[55][55], int sr, int sc, int er, int ec, int sdir) {
    if (sr == er && sc == ec) return 0;
    // Check vertex validity: intersection (r, c) blocked if any of 4 adjacent cells has 1
    int blocked[55][55];
    memset(blocked, 0, sizeof(blocked));
    for (int r = 1; r < R; r++) {
        for (int c = 1; c < C; c++) {
            if (grid[r-1][c-1] || grid[r-1][c] || grid[r][c-1] || grid[r][c]) {
                blocked[r][c] = 1;
            }
        }
    }
    if (blocked[sr][sc] || blocked[er][ec]) return -1;

    int dist[55][55][4];
    memset(dist, -1, sizeof(dist));
    int qr[55 * 55 * 4], qc[55 * 55 * 4], qd[55 * 55 * 4];
    int head = 0, tail = 0;

    dist[sr][sc][sdir] = 0;
    qr[tail] = sr; qc[tail] = sc; qd[tail] = sdir; tail++;

    while (head < tail) {
        int r = qr[head], c = qc[head], d = qd[head]; head++;
        if (r == er && c == ec) return dist[r][c][d];

        // Turn left
        int nd = (d + 3) % 4;
        if (dist[r][c][nd] == -1) {
            dist[r][c][nd] = dist[r][c][d] + 1;
            qr[tail] = r; qc[tail] = c; qd[tail] = nd; tail++;
        }
        // Turn right
        nd = (d + 1) % 4;
        if (dist[r][c][nd] == -1) {
            dist[r][c][nd] = dist[r][c][d] + 1;
            qr[tail] = r; qc[tail] = c; qd[tail] = nd; tail++;
        }
        // Move 1, 2, 3 steps
        for (int step = 1; step <= 3; step++) {
            int nr = r + dr314[d] * step;
            int nc = c + dc314[d] * step;
            if (nr <= 0 || nr >= R || nc <= 0 || nc >= C) break;
            if (blocked[nr][nc]) break; // cannot pass through obstacle
            if (dist[nr][nc][d] == -1) {
                dist[nr][nc][d] = dist[r][c][d] + 1;
                qr[tail] = nr; qc[tail] = nc; qd[tail] = d; tail++;
            }
        }
    }
    return -1;
}

int main(void) {

    int g[55][55];
    memset(g, 0, sizeof(g));
    // Straight path from (1, 1) to (1, 4) going East (dir 1) -> 1 step of 3
    int res = min_time_robot(5, 5, g, 1, 1, 1, 4, 1);
    int ok = (res == 1);
    printf("%s: UVa 314 - Robot\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
