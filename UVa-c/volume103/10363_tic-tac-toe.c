/*
 * ==========================================================================
 * UVa 10363 - Tic Tac Toe
 * Title-CN: 井字棋棋盤有效性驗證
 * Difficulty: Medium
 * Tags: Game Theory, Grid Simulation
 * URL: https://onlinejudge.org/external/103/10363.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a given 3x3 Tic Tac Toe board state is valid and reachable from an empty board.
 *
 * [中文] 題目概述:
 *     判斷給定的 3x3 井字棋盤面是否合法且可由空棋盤依遊戲規則達到。
 *
 * [EN] Approach:
 *     Count X and O. X == O or X == O + 1. If X wins, X == O + 1. If O wins, X == O. Both cannot win simultaneously.
 * [中文] 解題思路:
 *     統計 X 與 O 數量：X 必等於 O 或 O+1；X 獲勝時 X 必為 O+1；O 獲勝時 X 必等於 O；兩者不可同時獲勝。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int count_char(char b[3][3], char c) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (b[i][j] == c) cnt++;
    return cnt;
}
bool is_win(char b[3][3], char c) {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == c && b[i][1] == c && b[i][2] == c) return true;
        if (b[0][i] == c && b[1][i] == c && b[2][i] == c) return true;
    }
    if (b[0][0] == c && b[1][1] == c && b[2][2] == c) return true;
    if (b[0][2] == c && b[1][1] == c && b[2][0] == c) return true;
    return false;
}
bool valid_tictactoe(char b[3][3]) {
    int nx = count_char(b, 'X'), no = count_char(b, 'O');
    if (nx != no && nx != no + 1) return false;
    bool wx = is_win(b, 'X'), wo = is_win(b, 'O');
    if (wx && wo) return false;
    if (wx && nx != no + 1) return false;
    if (wo && nx != no) return false;
    return true;
}

int main(void) {

    char b1[3][3] = {{'X','O','X'}, {'X','O','O'}, {'O','X','X'}};
    int ok = valid_tictactoe(b1);
    printf("%s: UVa 10363 - Tic Tac Toe\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
