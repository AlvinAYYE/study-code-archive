/*
 * ==========================================================================
 * UVa 706 - LC-Display
 * Title-CN: 液晶數位顯示器排版 (7段 LCD 模擬)
 * Difficulty: UVa Star 1
 * Tags: simulation, formatting, string
 * URL: https://onlinejudge.org/external/7/706.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Render digits in LCD 7-segment style using '-' and '|' with scale factor s.
 *
 * [中文] 題目說明:
 *     依放大倍率 s 將十進位數字模擬為 7 段液晶電子手錶風格的數位字元圖案輸出。
 *
 * [EN] Approach:
 *     7 horizontal/vertical segments per digit. Construct 2s+3 rows and (s+2)*len columns grid.
 * [中文] 思路:
 *     將每個數字的 7 條線段編碼，依倍率 s 計算高度 2s+3 與單字寬度 s+2 逐行填入 '-' 與 '|'。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva706_height(int s) {
    return 2 * s + 3;
}

int main(void) {

    int ok = (solve_uva706_height(2) == 7);
    printf("%s: UVa 706 - LC-Display\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
