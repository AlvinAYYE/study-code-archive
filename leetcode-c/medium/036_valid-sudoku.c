/*
 * LeetCode 36. Valid Sudoku／有效的數獨
 * 題目（繁體中文）
 *   給定 9×9 數獨棋盤，判斷「目前已填入的數字」是否合規。
 *   每一列、每一行、每一個 3×3 小方格內，數字 1 到 9 都不可重複。
 *   '.' 代表尚未填入；棋盤不必能解完，只需檢查現有數字。
 *   棋盤固定 9 列、每列 9 格，格子只會是 '1'～'9' 或 '.'。
 *
 * 例子
 *   第一列是 53..7.... 的官方範例棋盤 → true。
 *   將它左上角的 5 改成 8，左上 3×3 方格便有兩個 8 → false。
 *
 * 解題思路
 *   1. 為 9 列、9 行、9 個小方格各準備一張「已看過數字」表。
 *   2. 逐格掃描；空格跳過，數字 d 則找出所在列、行與小方格。
 *   3. 三處只要有一處已出現 d，就立刻回傳 false；否則把三處標記。
 *   4. 走完仍無重複，就回傳 true。固定 81 格，時間與空間 O(1)。
 *
 * LeetCode 提交時保留 stdbool.h 與「提交區」即可。
 */
#include <stdbool.h>
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
    bool inRow[9][9] = {{false}};
    bool inColumn[9][9] = {{false}};
    bool inBox[9][9] = {{false}};

    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardColSize[row]; column++) {
            char cell = board[row][column];
            if (cell == '.') continue;

            int digit = cell - '1';       /* '1' 對應索引 0，'9' 對應索引 8 */
            int box = (row / 3) * 3 + column / 3;
            if (inRow[row][digit] || inColumn[column][digit] || inBox[box][digit]) {
                return false;
            }
            inRow[row][digit] = true;
            inColumn[column][digit] = true;
            inBox[box][digit] = true;
        }
    }
    return true;
}
/* ---------- end submission ---------- */

int main(void) {
    char rows[9][10] = {
        "53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
        "7...2...6", ".6....28.", "...419..5", "....8..79"
    };
    char *board[9];
    int widths[9];
    for (int i = 0; i < 9; i++) {
        board[i] = rows[i];
        widths[i] = 9;
    }
    if (!isValidSudoku(board, 9, widths)) {
        puts("FAIL: 036 valid board");
        return 1;
    }
    rows[0][0] = '8';
    if (isValidSudoku(board, 9, widths)) {
        puts("FAIL: 036 duplicate in box");
        return 1;
    }
    puts("PASS: 036 valid-sudoku");
    return 0;
}
