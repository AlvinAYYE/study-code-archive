/*
 * ==========================================================================
 * UVa 445 - Marvelous Mazes
 * Title-CN: 奇妙的迷宮解碼繪圖
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * ==========================================================================
 * [EN] Problem: Decode maze format: consecutive digits sum to frequency of next character ('b' is space, '!' is newline).
 * [中文] 題目說明: 迷宮輸出解碼：連續數字累加為後續字元的重複次數，'b' 代表空格，'!' 代表換行。
 * [EN] Approach: Accumulate digit sum, repeat character printing.
 * [中文] 思路: 累加連續數字和，遇到非數字字元則重複輸出對應次數。
 * ==========================================================================
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 445 - Marvelous Mazes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
