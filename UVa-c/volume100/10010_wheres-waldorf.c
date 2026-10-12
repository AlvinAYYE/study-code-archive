/*
 * ==========================================================================
 * UVa 10010 - Where's Waldorf?
 * Title-CN: 沃爾多在哪裡？
 * Difficulty: UVa Star 1
 * Tags: string, 2d-array, search
 * URL: https://onlinejudge.org/external/100/10010.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given an m x n grid of letters, find the start position (r, c) of a word in 8 directions.
 *
 * [中文] 題目說明:
 *     在 m x n 的英文字母矩陣中，沿 8 個方向（不分大小寫）尋找單字的起點座標。
 *
 * [EN] Approach: For each cell, check all 8 directions matching character by character.
 * [中文] 思路: 遍歷矩陣中每個起點，沿 8 個方向進行字串比對，找到第一組匹配即回傳。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static const int dr[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
static const int dc[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int solve_uva10010(int m, int n, char grid[55][55], const char *word, int *ans_r, int *ans_c) {
    int len = (int)strlen(word);
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            for (int d = 0; d < 8; d++) {
                int matched = 1;
                for (int k = 0; k < len; k++) {
                    int nr = r + dr[d] * k;
                    int nc = c + dc[d] * k;
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        tolower((unsigned char)grid[nr][nc]) != tolower((unsigned char)word[k])) {
                        matched = 0;
                        break;
                    }
                }
                if (matched) {
                    *ans_r = r + 1;
                    *ans_c = c + 1;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(void) {
    char grid[55][55] = {
        "abc",
        "def",
        "ghi"
    };
    int r, c;
    solve_uva10010(3, 3, grid, "fed", &r, &c); /* row 2 col 3 going left */
    int ok = (r == 2 && c == 3);
    printf("%s: UVa 10010 - Where's Waldorf?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
