/*
 * LeetCode 741. Cherry Pickup
 * 題意（繁體中文）：方形地圖中，-1 是不能通過的荊棘，1 是櫻桃，0 是空格。
 * 從左上角走到右下角再返回左上角，每步只能向右或向下（返回時方向相反），
 * 同一格的櫻桃只能拿一次。求最多能拿到幾顆；若無法完成路線則回傳 0。
 *
 * 範例：[[0,1,-1],[1,0,-1],[1,1,1]] -> 5
 *       [[1,1,-1],[1,-1,1],[-1,1,1]] -> 0
 * 限制：1 <= n <= 50；格子只會是 -1、0、1；起點與終點不是荊棘。
 * 解法：把「去程與回程」改看成兩個人同時從左上走到右下。走了 t 步時，
 *       兩人的列座標決定欄座標。dp[r1][r2] 記錄兩人到達這兩列時的最多櫻桃；
 *       每一步各自可能從左邊或上方來，因此每格只需比較四種前一步狀態。
 *       若兩人踩在同一格，只加一次櫻桃；荊棘或不可達狀態跳過。
 * 複雜度：O(n^3) 時間、O(n^2) 額外空間。
 * LeetCode C API：int cherryPickup(int** grid, int gridSize, int* gridColSize)
 */
#include <stdio.h>

#define MAX_N 50
#define UNREACHABLE (-1000000000)

int cherryPickup(int** grid, int gridSize, int* gridColSize) {
    (void)gridColSize;
    int n = gridSize;
    if (grid[0][0] == -1 || grid[n - 1][n - 1] == -1) return 0;

    int dp[MAX_N][MAX_N], next[MAX_N][MAX_N];
    for (int r1 = 0; r1 < n; ++r1)
        for (int r2 = 0; r2 < n; ++r2)
            dp[r1][r2] = UNREACHABLE;
    dp[0][0] = grid[0][0];

    for (int steps = 1; steps <= 2 * n - 2; ++steps) {
        for (int r1 = 0; r1 < n; ++r1)
            for (int r2 = 0; r2 < n; ++r2)
                next[r1][r2] = UNREACHABLE;

        int lowRow = steps - (n - 1);
        if (lowRow < 0) lowRow = 0;
        int highRow = steps < n - 1 ? steps : n - 1;
        for (int r1 = lowRow; r1 <= highRow; ++r1) {
            int c1 = steps - r1;
            if (grid[r1][c1] == -1) continue;
            for (int r2 = lowRow; r2 <= highRow; ++r2) {
                int c2 = steps - r2;
                if (grid[r2][c2] == -1) continue;

                int best = dp[r1][r2];
                if (r1 > 0 && dp[r1 - 1][r2] > best) best = dp[r1 - 1][r2];
                if (r2 > 0 && dp[r1][r2 - 1] > best) best = dp[r1][r2 - 1];
                if (r1 > 0 && r2 > 0 && dp[r1 - 1][r2 - 1] > best)
                    best = dp[r1 - 1][r2 - 1];
                if (best == UNREACHABLE) continue;

                int cherries = grid[r1][c1];
                if (r1 != r2 || c1 != c2) cherries += grid[r2][c2];
                next[r1][r2] = best + cherries;
            }
        }
        for (int r1 = 0; r1 < n; ++r1)
            for (int r2 = 0; r2 < n; ++r2)
                dp[r1][r2] = next[r1][r2];
    }
    return dp[n - 1][n - 1] > 0 ? dp[n - 1][n - 1] : 0;
}

int main(void) {
    int a0[] = {0, 1, -1}, a1[] = {1, 0, -1}, a2[] = {1, 1, 1};
    int *example1[] = {a0, a1, a2};
    int sizes1[] = {3, 3, 3};
    int b0[] = {1, 1, -1}, b1[] = {1, -1, 1}, b2[] = {-1, 1, 1};
    int *example2[] = {b0, b1, b2};
    int sizes2[] = {3, 3, 3};
    int single[] = {1};
    int *example3[] = {single};
    int sizes3[] = {1};
    int passed = cherryPickup(example1, 3, sizes1) == 5 &&
                 cherryPickup(example2, 3, sizes2) == 0 &&
                 cherryPickup(example3, 1, sizes3) == 1;
    puts(passed ? "PASS: 741 cherry-pickup" : "FAIL: 741 cherry-pickup");
    return passed ? 0 : 1;
}
