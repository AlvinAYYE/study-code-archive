/*
 * LeetCode 130. Surrounded Regions／被圍繞的區域
 * 題目：在 m × n 的 X/O 棋盤中，將所有被 X 完全包住的 O 區域改成 X。
 *       與棋盤邊界相連的 O 不會被包圍，必須保留。直接修改原棋盤，不回傳值。
 *
 * 範例 1：
 *   輸入：[["X","X","X","X"],["X","O","O","X"],
 *         ["X","X","O","X"],["X","O","X","X"]]
 *   輸出：[["X","X","X","X"],["X","X","X","X"],
 *         ["X","X","X","X"],["X","O","X","X"]]
 *   說明：左下角的 O 接觸邊界，所以保留；其他 O 都被 X 包圍。
 * 範例 2：[["X"]] -> [["X"]]。
 * 限制：1 <= m,n <= 200；每格只會是 X 或 O。
 *
 * 解題步驟：
 *   1. 從最上、最下、最左、最右邊界的 O 開始搜尋。
 *   2. 將這些 O 以及與它們上下左右相連的 O 暫時標記成安全記號 S。
 *   3. 掃描整張棋盤：未標記的 O 被包圍，改成 X；S 還原成 O。
 *   邊界搜尋使用佇列，時間 O(m*n)，額外空間 O(m*n)。
 *
 * LeetCode 提供 char** board；本機 main 使用可修改的字元列測試。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void markSafe(char **board, int row, int col, int rows, int cols,
                     int *queue, int *tail) {
    if (row < 0 || row >= rows || col < 0 || col >= cols ||
        board[row][col] != 'O') {
        return;
    }
    board[row][col] = 'S';
    queue[(*tail)++] = row * cols + col;
}

/* ---------- LeetCode submission / 提交區 ---------- */
void solve(char **board, int boardSize, int *boardColSize) {
    int rows = boardSize;
    int cols;
    int *queue;
    int head = 0, tail = 0;

    if (board == NULL || boardColSize == NULL || rows == 0) return;
    cols = boardColSize[0];
    if (cols == 0) return;

    queue = (int *)malloc((size_t)rows * (size_t)cols * sizeof *queue);
    if (queue == NULL) return;

    /* 四邊的 O 都可能連到棋盤外，因此不能被翻轉。 */
    for (int col = 0; col < cols; ++col) {
        markSafe(board, 0, col, rows, cols, queue, &tail);
        markSafe(board, rows - 1, col, rows, cols, queue, &tail);
    }
    for (int row = 0; row < rows; ++row) {
        markSafe(board, row, 0, rows, cols, queue, &tail);
        markSafe(board, row, cols - 1, rows, cols, queue, &tail);
    }

    while (head < tail) {
        int cell = queue[head++];
        int row = cell / cols, col = cell % cols;
        markSafe(board, row - 1, col, rows, cols, queue, &tail);
        markSafe(board, row + 1, col, rows, cols, queue, &tail);
        markSafe(board, row, col - 1, rows, cols, queue, &tail);
        markSafe(board, row, col + 1, rows, cols, queue, &tail);
    }

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            board[row][col] = board[row][col] == 'S' ? 'O' : 'X';
        }
    }
    free(queue);
}
/* ---------- end submission ---------- */

static int boardEquals(char **board, const char *expected[], int rows) {
    for (int row = 0; row < rows; ++row) {
        if (board[row] == NULL || strcmp(board[row], expected[row]) != 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    char row0[] = "XXXX", row1[] = "XOOX";
    char row2[] = "XXOX", row3[] = "XOXX";
    char *board[] = {row0, row1, row2, row3};
    int columns[] = {4, 4, 4, 4};
    const char *expected[] = {"XXXX", "XXXX", "XXXX", "XOXX"};
    char single[] = "X";
    char *singleBoard[] = {single};
    int singleColumn[] = {1};
    const char *singleExpected[] = {"X"};
    int passed;

    solve(board, 4, columns);
    solve(singleBoard, 1, singleColumn);
    passed = boardEquals(board, expected, 4) &&
             boardEquals(singleBoard, singleExpected, 1);
    puts(passed ? "PASS: 130 surrounded-regions"
                : "FAIL: 130 surrounded-regions");
    return passed ? 0 : 1;
}
