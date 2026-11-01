/*
 * ==========================================================================
 * UVa 10908 - Largest Square
 * Title-CN: 網格中心擴展最大同色正方形
 * Difficulty: UVa Star 1
 * Tags: simulation, 2d-grid
 * URL: https://onlinejudge.org/external/109/10908.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find side length of largest square with same character centered at (r, c).
 *
 * [中文] 題目說明:
 *     在二維網格中給定中心點 (r, c)，求以該點為中心且內部字元完全相同的最大正方形邊長。
 *
 * [EN] Approach:
 *     Expand radius rad from 1 outward. Check border cells at distance rad. Stop on mismatch or grid edge.
 * [中文] 思路:
 *     中心半徑擴展：從半徑 rad = 1 開始逐圈向外驗證外邊界字元是否皆等於中心字元，最大邊長為 2*rad + 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10908(int m, int n, char g[105][105], int r, int c) {
    char ch = g[r][c];
    int rad = 0;
    while (1) {
        int nxt = rad + 1;
        if (r - nxt < 0 || r + nxt >= m || c - nxt < 0 || c + nxt >= n) break;
        int ok = 1;
        for (int i = r - nxt; i <= r + nxt; i++) {
            if (g[i][c - nxt] != ch || g[i][c + nxt] != ch) { ok = 0; break; }
        }
        for (int j = c - nxt; j <= c + nxt; j++) {
            if (g[r - nxt][j] != ch || g[r + nxt][j] != ch) { ok = 0; break; }
        }
        if (!ok) break;
        rad = nxt;
    }
    return 2 * rad + 1;
}

int main(void) {

    char g[3][105] = {"aaa", "aaa", "aaa"};
    int ok = (solve_uva10908(3, 3, g, 1, 1) == 3);
    printf("%s: UVa 10908 - Largest Square\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
