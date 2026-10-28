/*
 * LeetCode 37. Sudoku Solver／解數獨
 * 題目（繁體中文）
 *   在給定的 9×9 棋盤中填滿所有 '.'，使每一列、每一行，以及每個
 *   3×3 小方格都恰好包含 1～9。輸入棋盤保證只有一組解，須直接修改原棋盤。
 *   每格是 '1'～'9' 或 '.'；已填入的數字不需要更動。
 *
 * 例子
 *   53..7.... / 6..195... / .98....6. / 8...6...3 / 4..8.3..1 /
 *   7...2...6 / .6....28. / ...419..5 / ....8..79
 *   解完第一列會是 534678912，整張棋盤都不再有空格。
 *
 * 解題思路
 *   1. 先記錄每一列、每一行與每個 3×3 方格已有的數字。
 *   2. 從左上往右下找下一個空格，依序試 1～9。
 *   3. 某數字在三處都還沒用過，才先填上並標記，遞迴處理下一格。
 *   4. 後面若走不通，就把這次填入與標記撤銷，改試下一個數字。
 *      這叫回溯；找到最後一格的合法填法就完成。
 *   最壞需嘗試 O(9^E) 種可能（E 為空格數）；標記表和遞迴深度
 *   在固定 9×9 棋盤下是 O(1) 空間。
 *
 * LeetCode 提交時保留 stdbool.h 與「提交區」即可。
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static bool fillSudoku(char **board, bool rows[9][9], bool columns[9][9],
                       bool boxes[9][9], int position) {
    if (position == 81) return true;  /* 81 格都已處理 */

    int row = position / 9;
    int column = position % 9;
    if (board[row][column] != '.') {
        return fillSudoku(board, rows, columns, boxes, position + 1);
    }

    int box = (row / 3) * 3 + column / 3;
    for (int digit = 0; digit < 9; digit++) {
        if (rows[row][digit] || columns[column][digit] || boxes[box][digit]) {
            continue;
        }

        board[row][column] = (char)('1' + digit);
        rows[row][digit] = columns[column][digit] = boxes[box][digit] = true;
        if (fillSudoku(board, rows, columns, boxes, position + 1)) return true;

        /* 這個選擇無解：恢復棋盤與三張記錄表。 */
        board[row][column] = '.';
        rows[row][digit] = columns[column][digit] = boxes[box][digit] = false;
    }
    return false;
}

void solveSudoku(char **board, int boardSize, int *boardColSize) {
    bool rows[9][9] = {{false}};
    bool columns[9][9] = {{false}};
    bool boxes[9][9] = {{false}};

    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardColSize[row]; column++) {
            char cell = board[row][column];
            if (cell == '.') continue;
            int digit = cell - '1';
            int box = (row / 3) * 3 + column / 3;
            rows[row][digit] = columns[column][digit] = boxes[box][digit] = true;
        }
    }
    fillSudoku(board, rows, columns, boxes, 0);
}
/* ---------- end submission ---------- */

int main(void) {
    char cells[9][10] = {
        "53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
        "7...2...6", ".6....28.", "...419..5", "....8..79"
    };
    const char *expected[9] = {
        "534678912", "672195348", "198342567", "859761423", "426853791",
        "713924856", "961537284", "287419635", "345286179"
    };
    char *board[9];
    int widths[9];
    for (int i = 0; i < 9; i++) {
        board[i] = cells[i];
        widths[i] = 9;
    }
    solveSudoku(board, 9, widths);
    for (int i = 0; i < 9; i++) {
        if (strcmp(board[i], expected[i]) != 0) {
            printf("FAIL: 037 row %d\n", i + 1);
            return 1;
        }
    }
    puts("PASS: 037 sudoku-solver");
    return 0;
}
