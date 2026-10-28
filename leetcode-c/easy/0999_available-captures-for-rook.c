/*
 * Title-CN: 車可以吃掉的棋子數
 * LeetCode 999. Available Captures for Rook
 *
 * 題意完整翻譯：
 *   給定 8 × 8 西洋棋盤，R 表示唯一的白色車、B 表示白色主教、p 表示黑色兵、.
 *   表示空格。車可沿水平或垂直方向移動，但不能越過任何棋子。回傳車能在一步內吃掉的黑兵數。
 *
 * 範例：
 *   1. 棋盤中央的車四個方向都沒有阻擋，可吃掉三個黑兵，輸出 3。
 *   2. 車被主教包圍，所有方向都被擋住，輸出 0。
 *   3. 車能吃掉左、上、右方向最近的黑兵，輸出 3。
 *
 * 限制：
 *   - board 是 8 × 8
 *   - 格子只會是 R、.、B 或 p
 *   - 恰有一個 R
 *
 * 解題步驟：
 *   1. 先在棋盤中找到 R 的列與欄。
 *   2. 從車的位置向上、下、左、右各走一格一格檢查。
 *   3. 遇到空格就繼續；遇到主教或其他阻擋棋子就停止該方向；若第一個棋子是黑兵，計數加一後停止該方向。
 *
 * 複雜度：
 *   時間：O(8 × 4)，棋盤大小固定，可視為 O(1)。
 *   空間：O(1)，只使用座標、方向與計數。
 *
 * LeetCode C API：
 *   int numRookCaptures(char** board, int boardSize, int* boardColSize);
 */
#include <assert.h>
#include <stdio.h>

int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    const int rowStep[4] = {-1, 1, 0, 0};
    const int colStep[4] = {0, 0, -1, 1};
    int rookRow = 0;
    int rookCol = 0;
    int captures = 0;
    int row;
    int col;
    int direction;

    (void)boardColSize;

    for (row = 0; row < boardSize; ++row) {
        for (col = 0; col < boardSize; ++col) {
            if (board[row][col] == 'R') {
                rookRow = row;
                rookCol = col;
            }
        }
    }

    for (direction = 0; direction < 4; ++direction) {
        row = rookRow + rowStep[direction];
        col = rookCol + colStep[direction];

        while (row >= 0 && row < boardSize && col >= 0 && col < boardSize) {
            if (board[row][col] == 'p') {
                ++captures;
                break;
            }
            if (board[row][col] != '.') {
                break; /* 主教等棋子擋住車的路徑。 */
            }

            row += rowStep[direction];
            col += colStep[direction];
        }
    }

    return captures;
}

int main(void) {
    char row0[] = "........";
    char row1[] = "...p....";
    char row2[] = "...R...p";
    char row3[] = "........";
    char row4[] = "........";
    char row5[] = "...p....";
    char row6[] = "........";
    char row7[] = "........";
    char* board[] = {row0,row1,row2,row3,row4,row5,row6,row7};
    int columns[] = {8,8,8,8,8,8,8,8};

    assert(numRookCaptures(board, 8, columns) == 3);
    puts("PASS 0999 numRookCaptures");
    return 0;
}
