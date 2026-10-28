/*
 * LeetCode 85. Maximal Rectangle／最大矩形
 * 題目（繁體中文）
 *   給定只含 '0'、'1' 的二維矩陣，找出只包含 '1' 的最大矩形面積。
 *   回傳面積；若沒有 '1'，回傳 0。矩陣的列數與欄數至少為 1。
 *
 * 例子
 *   10100
 *   10111
 *   11111
 *   10010
 *   最大全 1 矩形是第 2～3 列、第 3～5 欄，面積 6。
 *   全部都是 '0' 的矩陣 → 0。
 *
 * 解題思路
 *   1. 逐列往下看，把每一欄連續的 '1' 數量記成高度；遇到 '0' 就歸零。
 *   2. 這樣目前一列上方的矩陣，就變成一個直方圖。
 *   3. 在直方圖用單調遞增堆疊找每根柱子可延伸的最大寬度，計算
 *      高度 × 寬度，更新最大面積。
 *   4. 每列各算一次即可涵蓋所有矩形。時間 O(rows×columns)，
 *      額外空間 O(columns)。
 *
 * LeetCode 提交時保留 stdlib.h 與「提交區」即可。
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize) {
    if (matrixSize == 0) return 0;
    int columns = matrixColSize[0];
    int *heights = (int *)calloc((size_t)columns, sizeof *heights);
    int *stack = (int *)malloc((size_t)columns * sizeof *stack);
    int best = 0;
    if (heights == NULL || stack == NULL) {
        free(heights);
        free(stack);
        return 0;
    }

    for (int row = 0; row < matrixSize; row++) {
        for (int column = 0; column < columns; column++) {
            heights[column] = matrix[row][column] == '1' ? heights[column] + 1 : 0;
        }

        int top = -1;
        /* 用寬度為 0 的收尾柱，讓堆疊中所有柱子都結算一次。 */
        for (int column = 0; column <= columns; column++) {
            int currentHeight = column == columns ? 0 : heights[column];
            while (top >= 0 && heights[stack[top]] > currentHeight) {
                int height = heights[stack[top--]];
                int leftSmaller = top >= 0 ? stack[top] : -1;
                int width = column - leftSmaller - 1;
                int area = height * width;
                if (area > best) best = area;
            }
            if (column < columns) stack[++top] = column;
        }
    }

    free(heights);
    free(stack);
    return best;
}
/* ---------- end submission ---------- */

int main(void) {
    char row0[] = "10100", row1[] = "10111", row2[] = "11111", row3[] = "10010";
    char *matrix[] = {row0, row1, row2, row3};
    int widths[] = {5, 5, 5, 5};
    if (maximalRectangle(matrix, 4, widths) != 6) {
        puts("FAIL: 085 sample");
        return 1;
    }
    char empty0[] = "00", empty1[] = "00";
    char *emptyMatrix[] = {empty0, empty1};
    int emptyWidths[] = {2, 2};
    if (maximalRectangle(emptyMatrix, 2, emptyWidths) != 0) {
        puts("FAIL: 085 all-zero matrix");
        return 1;
    }
    puts("PASS: 085 maximal-rectangle");
    return 0;
}
