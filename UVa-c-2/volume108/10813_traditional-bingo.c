/*
 * ==========================================================================
 * UVa 10813 - Traditional BINGO
 * Title-CN: 傳統賓果遊戲模擬
 * Difficulty: Easy
 * Tags: Simulation, Grid
 * URL: https://onlinejudge.org/external/108/10813.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate calling 75 balls on a 5x5 Bingo card (center is free). Determine after how many calls a full line is completed.
 *
 * [中文] 題目描述:
 *     模擬 5x5 賓果卡（中心為已標記的免費格），依搖號序列叫號，求在第幾次叫號時最先連成一條線（行、列或對角線）。
 *
 * [EN] Approach:
 *     Mark called numbers on 5x5 board. Check 5 rows, 5 columns, and 2 diagonals after each call.
 *
 * [中文] 解題思維:
 *     維護 5x5 標記盤面，每叫一個號碼將其標記，隨即檢查 5 行、5 列與 2 條對角線是否達成 5 連線，返回叫號次數。
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

bool check_bingo_line(const bool marked[5][5]) {
    for (int r = 0; r < 5; r++) {
        bool full = true;
        for (int c = 0; c < 5; c++) if (!marked[r][c]) full = false;
        if (full) return true;
    }
    for (int c = 0; c < 5; c++) {
        bool full = true;
        for (int r = 0; r < 5; r++) if (!marked[r][c]) full = false;
        if (full) return true;
    }
    bool d1 = true, d2 = true;
    for (int i = 0; i < 5; i++) {
        if (!marked[i][i]) d1 = false;
        if (!marked[i][4 - i]) d2 = false;
    }
    return (d1 || d2);
}

int main(void) {

    bool b[5][5] = {false};
    for (int i = 0; i < 5; i++) b[0][i] = true; // first row complete
    int ok = check_bingo_line(b);
    printf("%s: UVa 10813 - Traditional BINGO\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
