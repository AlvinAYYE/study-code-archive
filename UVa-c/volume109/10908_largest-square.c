/*
 * ==========================================================================
 * UVa 10908 - Largest Square
 * Title-CN: 最大同心方陣
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: 2d-array, simulation
 * URL: https://onlinejudge.org/external/109/10908.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given an M x N grid of characters and a center query (r, c), find the side length
 *     of the largest square centered at (r, c) where all cells contain the same character.
 *
 * [中文] 題目說明:
 *     給定 M x N 的字元網格與中心點 (r, c)。求以 (r, c) 為中心、內部所有字元皆與
 *     中心字元相同的最大正方形之邊長。
 *
 * [EN] Approach:
 *     Grow radius rad = 1, 2, ... Check perimeter border cells until mismatch or out of bounds.
 * [中文] 思路:
 *     以中心點為基準，半徑 rad 由 1 逐步向外擴展，檢查外圈每一格是否符合且未越界。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10908(int m, int n, char grid[105][105], int r, int c) {
    char target = grid[r][c];
    int rad = 1;
    while (1) {
        if (r - rad < 0 || r + rad >= m || c - rad < 0 || c + rad >= n) break;
        int ok = 1;
        for (int i = r - rad; i <= r + rad && ok; i++) {
            if (grid[i][c - rad] != target || grid[i][c + rad] != target) ok = 0;
        }
        for (int j = c - rad; j <= c + rad && ok; j++) {
            if (grid[r - rad][j] != target || grid[r + rad][j] != target) ok = 0;
        }
        if (!ok) break;
        rad++;
    }
    return 2 * (rad - 1) + 1;
}

int main(void) {
    char grid[105][105] = {
        "abbba",
        "abbba",
        "abbba"
    };
    int len = solve_uva10908(3, 5, grid, 1, 2);
    int ok = (len == 3);
    printf("%s: UVa 10908 - Largest Square\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
