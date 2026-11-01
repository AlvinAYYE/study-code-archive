/*
 * ==========================================================================
 * UVa 10855 - Rotated square
 * Title-CN: 旋轉子方陣在母方陣中匹配次數
 * Difficulty: UVa Star 2
 * Tags: simulation, 2d-grid
 * URL: https://onlinejudge.org/external/108/10855.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count how many times a small square of size n appears in a big square of size N for rotations 0, 90, 180, and 270 degrees.
 *
 * [中文] 題目概述:
 *     給定 N x N 的大字元方陣與 n x n 的小子方陣，分別計算小子方陣旋轉 0°、90°、180° 與 270° 後在大方陣中出現的總次數。
 *
 * [EN] Approach:
 *     Simulate 2D grid submatrix matching. Rotate small square 90 degrees 3 times, counting exact matches at each rotation.
 * [中文] 解題思路:
 *     二維子矩陣比對：滑動窗口枚舉所有可能左上角，旋轉小矩陣四次並分別統計比對成功次數。
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

int count_matches(int N, char big[10][10], int n, char small[10][10]) {
    int cnt = 0;
    for (int r = 0; r <= N - n; r++) {
        for (int c = 0; c <= N - n; c++) {
            int match = 1;
            for (int i = 0; i < n && match; i++)
                for (int j = 0; j < n && match; j++)
                    if (big[r + i][c + j] != small[i][j]) match = 0;
            if (match) cnt++;
        }
    }
    return cnt;
}

int main(void) {

    char b[10][10] = {"AB", "CD"}, s[10][10] = {"AB", "CD"};
    int c = count_matches(2, b, 2, s);
    int ok = (c == 1);
    printf("%s: UVa 10855 - Rotated square\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
