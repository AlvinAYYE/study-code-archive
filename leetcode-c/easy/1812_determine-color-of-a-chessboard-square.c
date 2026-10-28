/*
 * LeetCode 1812. Determine Color of a Chessboard Square
 * Title-CN: 判斷棋盤格子的顏色
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
 *
 * [中文] 題目說明
 *     給定棋盤座標 coordinates，第一個字元是欄位 a 到 h，第二個字元是
 *     列號 1 到 8。棋盤左下角 a1 是黑格，顏色沿著橫向或縱向每走一格
 *     就交替一次。若指定格子是白色回傳 true，否則回傳 false。
 *
 * [中文] 範例
 *     1. coordinates = a1，輸出 false（a1 是黑色）。
 *     2. coordinates = h3，輸出 true。
 *     3. coordinates = c7，輸出 false。
 *
 * [中文] 限制
 *     - coordinates 長度為 2。
 *     - 'a' <= coordinates[0] <= 'h'，'1' <= coordinates[1] <= '8'。
 *
 * [中文] 解題步驟
 *     1. 將欄位字母換成 0 到 7，列號換成 0 到 7。
 *     2. 欄索引與列索引相加為偶數時，與 a1 同色（黑色）；奇數時為白色。
 *     3. 回傳奇偶判斷結果。時間 O(1)，額外空間 O(1)。
 *
 * LeetCode C 函式簽名：bool squareIsWhite(char* coordinates)
 */
#include <stdio.h>
#include <stdbool.h>

bool squareIsWhite(char *coordinates) {
    int column = coordinates[0] - 'a';
    int row = coordinates[1] - '1';
    return ((column + row) % 2) != 0;
}

int main(void) {
    int ok = squareIsWhite("a1") == false &&
             squareIsWhite("h3") == true &&
             squareIsWhite("c7") == false &&
             squareIsWhite("b1") == true;
    printf("%s: 1812 determine-color-of-a-chessboard-square\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
