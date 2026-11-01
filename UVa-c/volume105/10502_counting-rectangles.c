/*
 * ==========================================================================
 * UVa 10502 - Counting Rectangles
 * Title-CN: 計數全1矩形個數
 * Difficulty: Easy
 * Tags: Math, Brute Force, 2D Prefix Sums
 * URL: https://onlinejudge.org/external/105/10502.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the total number of subrectangles consisting entirely of '1's in an n x m binary grid.
 *
 * [中文] 題目說明:
 *     計算 n x m 二進位網格中，完全由 '1' 組成的子矩形總數。
 *
 * [EN] Approach:
 *     Compute 2D prefix sums. Enumerate all pairs (r1, c1) and (r2, c2). Check if subrectangle sum equals its area (r2 - r1 + 1) * (c2 - c1 + 1).
 * [中文] 思路:
 *     二維前綴和預處理，四重迴圈枚舉子矩形左上角與右下角，檢查區間和是否等於矩形面積。
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

int count_all_ones_rectangles(int n, int m, char grid[10][10]) {
    int pref[15][15] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + (grid[i][j] - '0');
    int total = 0;
    for (int r1 = 0; r1 < n; r1++)
        for (int c1 = 0; c1 < m; c1++)
            for (int r2 = r1; r2 < n; r2++)
                for (int c2 = c1; c2 < m; c2++) {
                    int area = (r2 - r1 + 1) * (c2 - c1 + 1);
                    int sum = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
                    if (sum == area) total++;
                }
    return total;
}

int main(void) {

    char g[10][10] = {"11", "11"};
    int ok = (count_all_ones_rectangles(2, 2, g) == 9); // 4 (1x1) + 2 (1x2) + 2 (2x1) + 1 (2x2)
    printf("%s: UVa 10502 - Counting Rectangles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
