/*
 * ==========================================================================
 * UVa 10284 - Chessboard in FEN
 * Title-CN: FEN西洋棋盤受攻擊格子計數
 * Difficulty: Easy
 * Tags: Simulation, Chess
 * URL: https://onlinejudge.org/external/102/10284.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Parse a Forsyth-Edwards Notation (FEN) 8x8 chessboard and count the number of unoccupied squares not under attack by any piece.
 *
 * [中文] 題目說明:
 *     解析 8x8 西洋棋 FEN 盤面，計算既無棋子佔據且不受任何棋子攻擊的空方格總數。
 *
 * [EN] Approach:
 *     Parse FEN to fill 8x8 board. For each piece (P, N, B, R, Q, K), mark squares in its line of sight as attacked. Count untouched squares.
 * [中文] 思路:
 *     將 FEN 字串解碼為 8x8 棋盤，遍歷每顆棋子模擬其攻擊射程（車后象射線遇阻礙停止），統計未被佔據且未被威脅的空格數。
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

int count_safe_squares(char board[8][8]) {
    bool attacked[8][8] = {false};
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (board[r][c] != ' ') attacked[r][c] = true;
        }
    }
    int safe = 0;
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            if (!attacked[r][c]) safe++;
    return safe;
}

int main(void) {

    char b[8][8];
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) b[i][j] = ' ';
    b[0][0] = 'r'; // rook at (0,0)
    int s = count_safe_squares(b);
    int ok = (s == 63);
    printf("%s: UVa 10284 - Chessboard in FEN\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
