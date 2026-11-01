/*
 * ==========================================================================
 * UVa 825 - Walking on the Safe Side
 * Title-CN: 安全街道漫步 (帶障礙網格路徑計數 DP)
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, grid
 * URL: https://onlinejudge.org/external/8/825.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count number of safest paths from (1, 1) to (W, N) in a grid avoiding unsafe intersections.
 *
 * [中文] 題目說明:
 *     在 W x N 網格街道中，避開所有不安全的路口，求從左上角 (1, 1) 走到右下角 (W, N) 的最短路徑總數。
 *
 * [EN] Approach:
 *     2D Grid DP: dp[r][c] = (unsafe ? 0 : dp[r-1][c] + dp[r][c-1]).
 * [中文] 思路:
 *     二維網格動態規劃：dp[r][c] = (障礙格 ? 0 : dp[r-1][c] + dp[r][c-1])，起點設為 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva825(int w, int n, int unsafe[105][105]) {
    long long dp[105][105] = {0};
    if (unsafe[1][1] || unsafe[w][n]) return 0;
    dp[1][1] = 1;
    for (int r = 1; r <= w; r++) {
        for (int c = 1; c <= n; c++) {
            if (unsafe[r][c]) continue;
            if (r > 1) dp[r][c] += dp[r - 1][c];
            if (c > 1) dp[r][c] += dp[r][c - 1];
        }
    }
    return dp[w][n];
}

int main(void) {

    int un[105][105] = {0};
    long long paths = solve_uva825(4, 5, un);
    int ok = (paths == 35); /* C(4+5-2, 4-1) = C(7, 3) = 35 */
    printf("%s: UVa 825 - Walking on the Safe Side\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
