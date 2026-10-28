/*
 * LeetCode 221. Maximal Square
 * Title-CN: 最大正方形
 *
 * 題意：給定只含字元 '0' 和 '1' 的 m × n 矩陣，找出完全由 '1' 組成的最大正方形，
 * 回傳它的面積。若沒有 '1'，回傳 0。
 *
 * 範例：
 * 1. [["1","0","1","0","0"],["1","0","1","1","1"],
 *     ["1","1","1","1","1"],["1","0","0","1","0"]] -> 4。
 * 2. [["0","1"],["1","0"]] -> 1；[["0"]] -> 0。
 *
 * 限制：1 <= m,n <= 300；matrix[i][j] 為 '0' 或 '1'。
 *
 * 解題思路：dp[j] 記錄「目前處理到的這一列，在第 j 欄結尾能形成的最大正方形邊長」。
 * 若當前格是 '1'，邊長等於上方、左方、左上方三個正方形邊長的最小值再加 1；
 * 若是 '0'，邊長為 0。答案是最大邊長的平方。
 *
 * 為了節省空間，只保留一列 dp。更新時先保存舊的 dp[j]，它是上一列的值；
 * dp[j-1] 已是本列左邊的值，另外用 diagonal 保存上一列左上角的值。
 *
 * 複雜度：時間 O(mn)，額外空間 O(n)。
 */
#include <stdio.h>
#include <stdlib.h>

int maximalSquare(char **matrix, int matrixSize, int *matrixColSize) {
    if (matrixSize == 0 || matrixColSize == NULL || matrixColSize[0] == 0) return 0;

    int columns = matrixColSize[0];
    int *dp = (int *)calloc((size_t)columns + 1, sizeof *dp);
    if (dp == NULL) return 0;

    int maxSide = 0;
    for (int row = 1; row <= matrixSize; ++row) {
        int diagonal = 0;
        for (int col = 1; col <= columns; ++col) {
            int oldAbove = dp[col];
            if (matrix[row - 1][col - 1] == '1') {
                int smallest = dp[col] < dp[col - 1] ? dp[col] : dp[col - 1];
                if (diagonal < smallest) smallest = diagonal;
                dp[col] = smallest + 1;
                if (dp[col] > maxSide) maxSide = dp[col];
            } else {
                dp[col] = 0;
            }
            diagonal = oldAbove;
        }
    }

    free(dp);
    return maxSide * maxSide;
}

int main(void) {
    char row0[] = "10100";
    char row1[] = "10111";
    char row2[] = "11111";
    char row3[] = "10010";
    char *matrix[] = {row0, row1, row2, row3};
    int columns[] = {5, 5, 5, 5};
    int passed = maximalSquare(matrix, 4, columns) == 4;

    char zero0[] = "01";
    char zero1[] = "10";
    char *smallMatrix[] = {zero0, zero1};
    int smallColumns[] = {2, 2};
    passed = passed && maximalSquare(smallMatrix, 2, smallColumns) == 1;

    char onlyZero[] = "0";
    char *oneCell[] = {onlyZero};
    int oneColumn[] = {1};
    passed = passed && maximalSquare(oneCell, 1, oneColumn) == 0;

    puts(passed ? "PASS: 221 maximal-square" : "FAIL: 221 maximal-square");
    return passed ? 0 : 1;
}
