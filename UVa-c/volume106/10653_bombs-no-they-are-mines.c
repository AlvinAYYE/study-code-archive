/*
 * ==========================================================================
 * UVa 10653 - Bombs! NO they are Mines!!
 * Title-CN: 地雷網格最短路徑 BFS
 * Difficulty: UVa Star 2
 * Tags: graph, bfs
 * URL: https://onlinejudge.org/external/106/10653.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum steps to navigate a robot across an R x C grid from start to destination, avoiding bomb-filled cells.
 *
 * [中文] 題目說明:
 *     在 R x C 網格地圖中避開佈滿地雷的格子，計算機器人從起點行進至終點所需之最短移動步數。
 *
 * [EN] Approach:
 *     Breadth-First Search on 2D grid with 4-directional transitions, tracking visited cells and distance.
 * [中文] 思路:
 *     標準二維網格 BFS：將障礙地雷標記為不可通行，以佇列走訪四方向相鄰空格，記錄到達終點之最短距離。
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

int solve_uva10653(int R, int C, int g[20][20], int sr, int sc, int dr, int dc) {
    int dist[20][20];
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) dist[r][c] = -1;
    int qr[400], qc[400], head = 0, tail = 0;
    qr[tail] = sr; qc[tail++] = sc;
    dist[sr][sc] = 0;
    int drs[] = {-1, 1, 0, 0}, dcs[] = {0, 0, -1, 1};
    while (head < tail) {
        int r = qr[head], c = qc[head++];
        if (r == dr && c == dc) return dist[r][c];
        for (int i = 0; i < 4; i++) {
            int nr = r + drs[i], nc = c + dcs[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && !g[nr][nc] && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                qr[tail] = nr; qc[tail++] = nc;
            }
        }
    }
    return -1;
}

int main(void) {

    int g[20][20] = {0};
    g[1][1] = 1; // bomb
    int d = solve_uva10653(3, 3, g, 0, 0, 2, 2);
    int ok = (d == 4);
    printf("%s: UVa 10653 - Bombs! NO they are Mines!!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
