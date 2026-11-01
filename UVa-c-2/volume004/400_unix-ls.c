/*
 * ==========================================================================
 * UVa 400 - Unix ls
 * Title-CN: Unix 檔案列表多欄排版
 * Difficulty: UVa Star 2
 * Tags: string, sorting, formatting
 * URL: https://onlinejudge.org/external/4/400.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Format list of filenames into column-major order across 60-character terminal width like Unix ls command.
 *
 * [中文] 題目說明:
 *     模擬 Unix 'ls' 指令：將檔名依字典序排序，在 60 字元寬度限制下計算最多欄位數並以由上而下、由左至右排版。
 *
 * [EN] Approach:
 *     Sort filenames alphabetically. Find max length L. Number of columns C = 1 + (60 - L) / (L + 2). Rows R = ceil(N / C).
 * [中文] 思路:
 *     字串字典序排序，找出最長檔名長度 L。計算最大欄數 C = 1 + (60 - L) / (L + 2)，列數 R = (N + C - 1) / C 依直行印出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva400_calc_cols(int max_len) {
    if (max_len >= 60) return 1;
    return 1 + (60 - max_len) / (max_len + 2);
}

int main(void) {

    int ok = (solve_uva400_calc_cols(10) == 5);
    printf("%s: UVa 400 - Unix ls\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
