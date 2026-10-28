/*
 * Title-CN: 掃雷遊戲
 * LeetCode 529. Minesweeper
 *
 * 題意翻譯：給定掃雷棋盤與一次點擊。點到地雷 M 時，將它標成 X（遊戲結束）。
 * 點到未揭露格 E 時，若周圍八格有地雷，就把它改成相鄰地雷數字；若沒有，
 * 就標成空白 B，並自動揭露周圍的未揭露格。回傳更新後的棋盤。
 *
 * 範例：在空曠區點擊，會先顯示 B，再逐步展開附近沒有地雷的格子，直到邊界
 * 的數字格為止。
 *
 * 限制：棋盤為 m x n，1 <= m,n <= 50；格子為 M、E、B、1 到 8 或 X。
 * 點擊座標一定在棋盤內。
 *
 * 解題思路：若點到 M，直接改成 X。否則從點擊位置計算八個方向的地雷數：
 * 有地雷就顯示數字；沒有地雷就改成 B，並遞迴處理八個鄰格。遞迴只進入 E，
 * 因此已揭露的格子不會重複處理。
 *
 * 複雜度：時間 O(mn)，每格最多揭露一次；遞迴堆疊最壞 O(mn)。
 * LeetCode 介面：保留 updateBoard；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

static const int rowOffset[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
static const int colOffset[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

static void reveal(char **board, int rows, int cols, int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'E') return;

    int mines = 0;
    for (int direction = 0; direction < 8; ++direction) {
        int nearRow = row + rowOffset[direction];
        int nearCol = col + colOffset[direction];
        if (nearRow >= 0 && nearRow < rows && nearCol >= 0 && nearCol < cols
            && board[nearRow][nearCol] == 'M') {
            ++mines;
        }
    }

    if (mines > 0) {
        board[row][col] = (char)('0' + mines);
        return;
    }

    board[row][col] = 'B';
    for (int direction = 0; direction < 8; ++direction) {
        reveal(board, rows, cols, row + rowOffset[direction], col + colOffset[direction]);
    }
}

char **updateBoard(char **board, int boardSize, int *boardColSize, int *click,
                   int clickSize, int *returnSize, int **returnColumnSizes) {
    (void)clickSize;
    *returnSize = boardSize;
    *returnColumnSizes = NULL;
    if (boardSize <= 0 || board == NULL) {
        *returnSize = 0;
        return board;
    }

    int *columns = malloc((size_t)boardSize * sizeof(*columns));
    if (columns == NULL) {
        *returnSize = 0;
        return board;
    }
    int cols = boardColSize[0];
    for (int row = 0; row < boardSize; ++row) columns[row] = boardColSize[row];

    int row = click[0];
    int col = click[1];
    if (board[row][col] == 'M') board[row][col] = 'X';
    else reveal(board, boardSize, cols, row, col);
    *returnColumnSizes = columns;
    return board;
}

int main(void) {
    char row0[] = "EEEEE";
    char row1[] = "EEMEE";
    char row2[] = "EEEEE";
    char row3[] = "EEEEE";
    char *board[] = {row0, row1, row2, row3};
    int columnSizes[] = {5, 5, 5, 5};
    int click[] = {3, 0};
    int returnSize = 0;
    int *returnColumns = NULL;
    char **answer = updateBoard(board, 4, columnSizes, click, 2,
                                &returnSize, &returnColumns);
    const char *expected[] = {"B1E1B", "B1M1B", "B111B", "BBBBB"};
    assert(returnSize == 4 && answer == board);
    for (int row = 0; row < 4; ++row) {
        assert(returnColumns[row] == 5);
        for (int col = 0; col < 5; ++col) assert(answer[row][col] == expected[row][col]);
    }
    free(returnColumns);

    char mineRow[] = "M";
    char *mineBoard[] = {mineRow};
    int oneColumn[] = {1};
    int mineClick[] = {0, 0};
    answer = updateBoard(mineBoard, 1, oneColumn, mineClick, 2,
                         &returnSize, &returnColumns);
    assert(answer[0][0] == 'X' && returnSize == 1 && returnColumns[0] == 1);
    free(returnColumns);
    return 0;
}
