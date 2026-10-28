/*
 * LeetCode 2373. Largest Local Values in a Matrix
 * Title-CN: 矩陣中的局部最大值
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/largest-local-values-in-a-matrix/
 *
 * [中文] 題目說明
 *     給定 n x n 整數矩陣 grid。建立大小為 (n - 2) x (n - 2) 的 maxLocal；
 *     maxLocal[i][j] 是 grid 中以 (i,j) 為左上角的連續 3 x 3 區域最大值。
 *     回傳 maxLocal。
 *
 * [中文] 範例
 *     1. grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]，
 *        輸出 [[9,9],[8,6]]。
 *     2. 5 x 5 矩陣除了中央是 2、其餘為 1，輸出 3 x 3 的全 2 矩陣。
 *
 * [中文] 限制
 *     - grid 是 n x n 正方形，3 <= n <= 100。
 *     - 1 <= grid[i][j] <= 100。
 *
 * [中文] 解題步驟
 *     1. 輸出矩陣每邊長為 n - 2，逐一選擇每個輸出位置作為 3 x 3 視窗左上角。
 *     2. 用兩層小迴圈查看視窗中的 9 個數，保留最大值並放入輸出矩陣。
 *     3. 共有 (n - 2)^2 個視窗，每個看 9 格，時間 O(n^2)，輸出空間 O(n^2)。
 *
 * LeetCode C 函式簽名：
 *     int** largestLocal(int** grid, int gridSize, int* gridColSize,
 *                        int* returnSize, int** returnColumnSizes)
 */
#include <stdio.h>
#include <stdlib.h>

int **largestLocal(int **grid, int gridSize, int *gridColSize, int *returnSize, int **returnColumnSizes) {
    int side = gridSize - 2;
    int **answer = (int **)malloc((size_t)side * sizeof(int *));
    int i, j, r, c;
    (void)gridColSize;
    *returnSize = side;
    *returnColumnSizes = (int *)malloc((size_t)side * sizeof(int));
    for (i = 0; i < side; ++i) {
        answer[i] = (int *)malloc((size_t)side * sizeof(int));
        (*returnColumnSizes)[i] = side;
        for (j = 0; j < side; ++j) {
            int largest = grid[i][j];
            for (r = i; r < i + 3; ++r) {
                for (c = j; c < j + 3; ++c) {
                    if (grid[r][c] > largest) largest = grid[r][c];
                }
            }
            answer[i][j] = largest;
        }
    }
    return answer;
}

static void freeMatrix(int **matrix, int rows, int *columnSizes) {
    int i;
    for (i = 0; i < rows; ++i) free(matrix[i]);
    free(matrix);
    free(columnSizes);
}

static int matches(int **matrix, int rows, int cols, const int *expected) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            if (matrix[i][j] != expected[i * cols + j]) return 0;
        }
    }
    return 1;
}

int main(void) {
    int ok = 1, rows, *outCols;
    int g0[] = {9, 9, 8, 1}, g1[] = {5, 6, 2, 6}, g2[] = {8, 2, 6, 4}, g3[] = {6, 2, 2, 2};
    int *grid[] = {g0, g1, g2, g3};
    int cols[] = {4, 4, 4, 4};
    int expected[] = {9, 9, 8, 6};
    int **answer = largestLocal(grid, 4, cols, &rows, &outCols);
    ok = ok && rows == 2 && outCols[0] == 2 && outCols[1] == 2 && matches(answer, 2, 2, expected);
    freeMatrix(answer, rows, outCols);
    printf("%s: 2373 largest-local-values-in-a-matrix\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
