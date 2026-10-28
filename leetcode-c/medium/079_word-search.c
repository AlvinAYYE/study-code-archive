/*
 * LeetCode 79. Word Search／單字搜尋
 * 題目（繁體中文）
 *   給定 m×n 字母棋盤與字串 word，判斷能否從某格開始，依序走訪相鄰格子
 *   拼出整個單字。只可往上、下、左、右移動；同一格在一次拼字中不能重用。
 *   1 ≤ m,n ≤ 6，1 ≤ word 長度 ≤ 15，棋盤及單字只含大小寫英文字母。
 *
 * 例子：棋盤 ABCE / SFCS / ADEE
 *   "ABCCED" → true（沿相鄰格依序走）
 *   "SEE"    → true
 *   "ABCB"   → false（B 必須重用同一格）
 *
 * 解題思路
 *   1. 每個格子都可能是起點，逐一嘗試。
 *   2. 目前格若不等於 word 的目前字母，這條路立即失敗。
 *   3. 若相同，暫時把該格標成「走過」，再往四個方向找下一個字母。
 *   4. 四條路都不通，就把原字母放回去，讓其他路線仍能使用此格。
 *      找到單字最後一個字母便成功。這是深度優先搜尋加回溯。
 *   最壞時間 O(mn·4^L)（L 是單字長度），遞迴空間 O(L)。
 *
 * LeetCode 提交時保留 stdbool.h、string.h 與「提交區」即可。
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static bool searchFrom(char **board, int rows, int *widths,
                       const char *word, int index, int row, int column) {
    if (row < 0 || row >= rows || column < 0 || column >= widths[row] ||
        board[row][column] != word[index]) {
        return false;
    }
    if (word[index + 1] == '\0') return true;

    char original = board[row][column];
    board[row][column] = '\0';  /* 題目只有英文字母，故 NUL 可表示暫時走過。 */
    bool found = searchFrom(board, rows, widths, word, index + 1, row - 1, column) ||
                 searchFrom(board, rows, widths, word, index + 1, row + 1, column) ||
                 searchFrom(board, rows, widths, word, index + 1, row, column - 1) ||
                 searchFrom(board, rows, widths, word, index + 1, row, column + 1);
    board[row][column] = original;  /* 回溯：其他起點需要原棋盤。 */
    return found;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardColSize[row]; column++) {
            if (searchFrom(board, boardSize, boardColSize, word, 0, row, column)) {
                return true;
            }
        }
    }
    return false;
}
/* ---------- end submission ---------- */

int main(void) {
    char cells[3][5] = {"ABCE", "SFCS", "ADEE"};
    char *board[3] = {cells[0], cells[1], cells[2]};
    int widths[3] = {4, 4, 4};
    if (!exist(board, 3, widths, "ABCCED") ||
        !exist(board, 3, widths, "SEE") ||
        exist(board, 3, widths, "ABCB") ||
        strcmp(board[0], "ABCE") != 0) {
        puts("FAIL: 079 word-search");
        return 1;
    }
    puts("PASS: 079 word-search");
    return 0;
}
