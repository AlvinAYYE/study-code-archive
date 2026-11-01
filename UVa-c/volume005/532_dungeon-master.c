/*
 * ==========================================================================
 * UVa 532 - Dungeon Master
 * Title-CN: 地牢大師 (3D 空間 BFS 最短路徑)
 * Difficulty: UVa Star 1
 * Tags: graph, bfs, shortest-path
 * URL: https://onlinejudge.org/external/5/532.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Escape a 3D dungeon (L x R x C). Move in 6 directions (North, South, East, West, Up, Down). Find min minutes to exit.
 *
 * [中文] 題目說明:
 *     在 L x R x C 的 3D 立體地牢中，由起點 'S' 移動至終點 'E'，每次可沿 6 個方向移動，求逃脫最短分鐘數。
 *
 * [EN] Approach:
 *     3D Breadth-First Search (BFS) using queue. Explore 6 neighbor directions, marking visited cells to find shortest distance.
 * [中文] 思路:
 *     標準 3D 空間 BFS 走訪：佇列儲存 (層, 列, 行)，朝上下前後左右 6 個相鄰方向擴展，首個抵達終點即為最短步數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva532_3d_bfs(int l, int r, int c, char dungeon[35][35][35], int sl, int sr, int sc, int el, int er, int ec) {
    int dl[6] = {1, -1, 0, 0, 0, 0};
    int dr[6] = {0, 0, 1, -1, 0, 0};
    int dc[6] = {0, 0, 0, 0, 1, -1};
    int dist[35][35][35];
    for (int i = 0; i < l; i++) for (int j = 0; j < r; j++) for (int k = 0; k < c; k++) dist[i][j][k] = -1;
    int q[35000][3], head = 0, tail = 0;
    q[tail][0] = sl; q[tail][1] = sr; q[tail++][2] = sc;
    dist[sl][sr][sc] = 0;
    while (head < tail) {
        int cl = q[head][0], cr = q[head][1], cc = q[head++][2];
        if (cl == el && cr == er && cc == ec) return dist[cl][cr][cc];
        for (int i = 0; i < 6; i++) {
            int nl = cl + dl[i], nr = cr + dr[i], nc = cc + dc[i];
            if (nl >= 0 && nl < l && nr >= 0 && nr < r && nc >= 0 && nc < c &&
                dungeon[nl][nr][nc] != '#' && dist[nl][nr][nc] == -1) {
                dist[nl][nr][nc] = dist[cl][cr][cc] + 1;
                q[tail][0] = nl; q[tail][1] = nr; q[tail++][2] = nc;
            }
        }
    }
    return -1;
}

int main(void) {

    char dung[35][35][35] = {{{'S', '.', 'E'}}};
    int res = solve_uva532_3d_bfs(1, 1, 3, dung, 0, 0, 0, 0, 0, 2);
    int ok = (res == 2);
    printf("%s: UVa 532 - Dungeon Master\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
