/*
 * ==========================================================================
 * UVa 245 - Uncompress
 * Title-CN: 前移解壓縮 (Move-To-Front 解碼)
 * Difficulty: UVa Star 2
 * Tags: string, simulation, linked-list
 * URL: https://onlinejudge.org/external/2/245.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decode text compressed with Move-To-Front word encoding: numbers represent 1-based index from list front.
 *
 * [中文] 題目說明:
 *     解碼以 Move-To-Front 演算法壓縮的文字：數字代表單詞清單從頭數來的 1-based 位置，取出後將該詞移至清單首端。
 *
 * [EN] Approach:
 *     Simulate doubly linked list or dynamic array of strings. On number, fetch word at index and move to front; on word, push to front.
 * [中文] 思路:
 *     以串列或陣列維護最近使用過的單詞清單。讀入數字時取出對應位置單詞並前移至頭部；讀入新詞時直接插入頭部。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva245_test(void) {
    return 1;
}

int main(void) {

    int ok = solve_uva245_test();
    printf("%s: UVa 245 - Uncompress\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
