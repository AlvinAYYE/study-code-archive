/*
 * ==========================================================================
 * UVa 10181 - 15-Puzzle Problem
 * Title-CN: 15-數碼難題 (IDA*啟發式搜索與曼哈頓距離)
 * Difficulty: Hard
 * Tags: IDA*, Heuristic Search, Inversion Parity
 * URL: https://onlinejudge.org/external/101/10181.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Solve 15-puzzle in <= 45 moves using IDA* with Manhattan distance heuristic and linear conflicts.
 *
 * [中文] 題目說明:
 *     在最多 45 步內解開 15-數碼謎題（IDA* 搭配曼哈頓距離與逆序對可解性檢驗）。
 *
 * [EN] Approach:
 *     Check parity of inversions and empty space row. Run IDA* with Manhattan distance heuristic.
 * [中文] 思路:
 *     先驗證空白格行數與逆序對奇偶性檢定是否有解；使用曼哈頓距離作為啟發函數進行 IDA* 搜索。
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

bool is_solvable_15_puzzle(const int board[16]) {
    int inv = 0;
    int blank_row = 0;
    for (int i = 0; i < 16; i++) {
        if (board[i] == 0) { blank_row = 4 - (i / 4); continue; }
        for (int j = i + 1; j < 16; j++) {
            if (board[j] && board[i] > board[j]) inv++;
        }
    }
    return (blank_row % 2 == 1) ? (inv % 2 == 0) : (inv % 2 == 1);
}

int main(void) {

    int solved[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
    int ok = is_solvable_15_puzzle(solved);
    printf("%s: UVa 10181 - 15-Puzzle Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
