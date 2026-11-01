/*
 * ==========================================================================
 * UVa 541 - Error Correction
 * Title-CN: 二維奇偶校驗矩陣修正
 * Difficulty: UVa Star 1
 * Tags: 2d-array, simulation
 * ==========================================================================
 * [EN] Problem: Check if 0/1 matrix has even row and column sums. If 1 bit is wrong, output coordinate. Otherwise Corrupt.
 * [中文] 題目說明: 檢查二維布林矩陣各行各列和是否皆為偶數（OK）；若恰有一行一列為奇數輸出翻轉座標；否則 Corrupt。
 * [EN] Approach: Count odd row sums and odd col sums.
 * [中文] 思路: 統計奇數列與奇數位數，恰各為 1 則可修正，超過則為 Corrupt。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva541(int n, const int mat[105][105], int *ans_r, int *ans_c) {
    int odd_r = -1, odd_c = -1, r_cnt = 0, c_cnt = 0;
    for (int i = 0; i < n; i++) {
        int r_sum = 0, c_sum = 0;
        for (int j = 0; j < n; j++) {
            r_sum += mat[i][j];
            c_sum += mat[j][i];
        }
        if (r_sum % 2 != 0) { odd_r = i + 1; r_cnt++; }
        if (c_sum % 2 != 0) { odd_c = i + 1; c_cnt++; }
    }
    if (r_cnt == 0 && c_cnt == 0) return 0; /* OK */
    if (r_cnt == 1 && c_cnt == 1) {
        *ans_r = odd_r; *ans_c = odd_c;
        return 1; /* Change bit */
    }
    return 2; /* Corrupt */
}

int main(void) {
    int m[4][105] = {
        {1, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 1}
    };
    int r, c;
    int res = solve_uva541(4, m, &r, &c);
    int ok = (res == 0);
    printf("%s: UVa 541 - Error Correction\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
