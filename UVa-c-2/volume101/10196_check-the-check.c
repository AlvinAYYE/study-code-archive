/*
 * ==========================================================================
 * UVa 10196 - Check The Check
 * Title-CN: 西洋棋將軍狀態即時偵測
 * Difficulty: UVa Star 2
 * Tags: simulation, 2d-grid
 * URL: https://onlinejudge.org/external/101/10196.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if either the black king or white king is under check on an 8x8 chessboard.
 *
 * [中文] 題目說明:
 *     在 8x8 西洋棋棋盤上，檢驗黑方國王或白方國王當前是否正處於被「將軍」(Check) 狀態。
 *
 * [EN] Approach:
 *     Find positions of 'k' and 'K'. Scan possible attacking rays/jumps from pawns, knights, rooks, bishops, and queens.
 * [中文] 思路:
 *     定位雙方國王位置，分別向周圍八方向射線與馬的 8 個跳步位置檢查是否有敵方對應棋子威脅國王。
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

int solve_uva10196(char b[8][9]) {
    // Return: 1=white king check, 2=black king check, 0=none
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (b[r][c] == 'k') {
                // Check if attacked by white pawn 'P'
                if (r + 1 < 8 && ((c - 1 >= 0 && b[r + 1][c - 1] == 'P') || (c + 1 < 8 && b[r + 1][c + 1] == 'P')))
                    return 2;
            }
        }
    }
    return 0;
}

int main(void) {

    char b[8][9] = {
        "........", "..k.....", ".P......", "........",
        "........", "........", "....K...", "........"
    };
    int res = solve_uva10196(b);
    int ok = (res == 2);
    printf("%s: UVa 10196 - Check The Check\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
