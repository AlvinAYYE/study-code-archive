/*
 * LeetCode 419. Battleships in a Board／棋盤上的戰艦
 *
 * 題目（繁體中文）
 *   給定由 'X'（戰艦）和 '.'（空格）組成的棋盤。戰艦只能是水平或垂直的
 *   連續直線，長度至少為 1；不同戰艦之間至少隔一格，因此不會上下或左右
 *   相鄰。請計算棋盤上有幾艘戰艦。
 *
 * 範例 1：board=[[X,.,.,X],[.,.,.,X],[.,.,.,X]]，輸出 2。
 * 範例 2：board=[[.]]，輸出 0。
 * 限制：1 <= 列數、欄數 <= 200；每格只會是 'X' 或 '.'。
 * 進階要求：單次掃描、額外空間 O(1)，且不修改棋盤。
 *
 * 解題步驟：
 *   1. 逐格掃描棋盤，只在 'X' 格子上考慮是否開始一艘新船。
 *   2. 若上方是 'X'，目前格子是垂直戰艦的中段；若左方是 'X'，則是水平
 *      戰艦的中段。這兩種情況都不另外計數。
 *   3. 因此，只要目前是 'X' 且上方、左方不是 'X'（或位於邊界），就計數加一。
 *   每格檢查一次，時間 O(mn)，額外空間 O(1)，不改動棋盤。
 *
 * LeetCode C API：int countBattleships(char** board, int boardSize,
 * int* boardColSize)。此檔案的 main 僅供本機測試。
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int countBattleships(char **board, int boardSize, int *boardColSize) {
    if (board == NULL || boardColSize == NULL || boardSize <= 0) return 0;
    int ships = 0;
    for (int row = 0; row < boardSize; ++row) {
        for (int column = 0; column < boardColSize[row]; ++column) {
            if (board[row][column] != 'X') continue;
            int hasShipAbove = row > 0 && board[row - 1][column] == 'X';
            int hasShipLeft = column > 0 && board[row][column - 1] == 'X';
            if (!hasShipAbove && !hasShipLeft) ++ships;
        }
    }
    return ships;
}
/* ---------- end submission ---------- */

int main(void) {
    char row0[] = "X..X", row1[] = "...X", row2[] = "...X";
    char *board[] = {row0, row1, row2};
    int columns[] = {4, 4, 4};
    int passed = countBattleships(board, 3, columns) == 2 &&
                 row0[0] == 'X' && row0[3] == 'X' &&
                 row1[3] == 'X' && row2[3] == 'X';

    char emptyRow[] = ".";
    char *emptyBoard[] = {emptyRow};
    int emptyColumns[] = {1};
    passed = passed && countBattleships(emptyBoard, 1, emptyColumns) == 0;

    puts(passed ? "PASS: 419 battleships-in-a-board"
                : "FAIL: 419 battleships-in-a-board");
    return passed ? 0 : 1;
}
