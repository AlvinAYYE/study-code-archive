/*
 * ==========================================================================
 * UVa 11498 - Division of Nlogonia
 * Title-CN: 恩羅戈尼亞國界分割象限判定
 * Difficulty: UVa Star 1
 * Tags: simulation, geometry
 * URL: https://onlinejudge.org/external/114/11498.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given division origin (N, M), determine whether query points lie on border (divisa) or in NE, SE, NO, SO quadrants.
 *
 * [中文] 題目說明:
 *     以分割基準點 (N, M) 為原點，判定詢問點位在邊界上 (divisa) 或是落於 NE、SE、NO (西北)、SO (西南) 象限。
 *
 * [EN] Approach:
 *     Direct coordinate comparisons: x == N or y == M is 'divisa'; otherwise check sign differences for 4 quadrants.
 * [中文] 思路:
 *     座標直接比對：若 x == N 或 y == M 輸出 divisa；否則依 x 與 y 相對於基準點的大於小於關係輸出四個象限方位。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char* solve_uva11498(int n, int m, int x, int y) {
    if (x == n || y == m) return "divisa";
    if (x > n && y > m) return "NE";
    if (x > n && y < m) return "SE";
    if (x < n && y > m) return "NO";
    return "SO";
}

int main(void) {

    int ok = (strcmp(solve_uva11498(10, 10, 10, 15), "divisa") == 0) &&
             (strcmp(solve_uva11498(10, 10, 12, 12), "NE") == 0);
    printf("%s: UVa 11498 - Division of Nlogonia\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
