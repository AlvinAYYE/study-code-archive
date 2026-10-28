/*
 * LeetCode 688. Knight Probability in Chessboard（騎士在棋盤上的機率）
 *
 * 題意（繁體中文）：
 *   在 n x n 棋盤上，騎士從 (row,column) 出發，恰好移動 k 次。每次從八種
 *   馬步中等機率隨機選一種，即使那一步會走出棋盤也照樣選；一旦走出棋盤，
 *   騎士就不會再回來。請回傳走完 k 步後仍留在棋盤內的機率。列與欄都從 0
 *   開始編號。
 *
 * 範例：
 *   1. n=3, k=2, row=0, column=0，回傳約 0.06250。
 *      第一步有 2/8 機率留在棋盤，從這兩格各有 2/8 機率再留下，因此為 1/16。
 *   2. n=1, k=0, row=0, column=0，回傳 1.00000，因為尚未移動。
 *   3. n=3, k=1, row=1, column=1，回傳 0，中心格的八種馬步都會離開棋盤。
 *
 * 限制：1 <= n <= 25；0 <= k <= 100；起點座標皆在棋盤範圍內。
 *
 * 解題步驟：
 *   1. dp[r][c] 表示目前走到第幾步時，騎士在格子 (r,c) 的機率。起點機率為 1。
 *   2. 每一步把每格機率平均分成八份，累加到八個合法目的格；走出棋盤的
 *      那幾份不再累加，因此自然代表已離開的機率。
 *   3. 重複 k 次後，把棋盤上所有格子的機率相加，就是仍留在棋盤的機率。
 *
 * 複雜度：時間 O(k*n^2)，額外空間 O(n^2)。
 * LeetCode C API：double knightProbability(int n, int k, int row, int column)
 */
#include <stdio.h>
#include <string.h>

double knightProbability(int n, int k, int row, int column) {
    double current[25][25] = {{0.0}};
    double next[25][25];
    current[row][column] = 1.0;
    const int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    const int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int step = 0; step < k; ++step) {
        memset(next, 0, sizeof next);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (current[r][c] == 0.0) continue;
                double share = current[r][c] / 8.0;
                for (int move = 0; move < 8; ++move) {
                    int nr = r + dr[move];
                    int nc = c + dc[move];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n)
                        next[nr][nc] += share;
                }
            }
        }
        memcpy(current, next, sizeof current);
    }

    double probability = 0.0;
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c) probability += current[r][c];
    return probability;
}

static int closeEnough(double a, double b) {
    double difference = a - b;
    if (difference < 0.0) difference = -difference;
    return difference < 1e-9;
}

int main(void) {
    int passed = closeEnough(knightProbability(3, 2, 0, 0), 0.0625) &&
                 closeEnough(knightProbability(1, 0, 0, 0), 1.0) &&
                 closeEnough(knightProbability(3, 1, 1, 1), 0.0) &&
                 closeEnough(knightProbability(3, 1, 0, 0), 0.25);
    puts(passed ? "PASS: 688 knight-probability-in-chessboard"
                : "FAIL: 688 knight-probability-in-chessboard");
    return passed ? 0 : 1;
}
