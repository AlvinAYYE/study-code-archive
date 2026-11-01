/*
 * ==========================================================================
 * UVa 121 - Pipe Fitters
 * Title-CN: 網格與交錯排管幾何堆疊
 * Difficulty: UVa Star 1
 * Tags: geometry, greedy
 * URL: https://onlinejudge.org/external/1/121.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given grid dimensions a x b, calculate maximum number of unit pipes packed using standard grid vs skew (hexagonal) packing.
 *
 * [中文] 題目說明:
 *     給定容器長寬 a x b，計算單位圓管以標準正交網格排列與交錯蜂巢排列下最多可容納之管子數量。
 *
 * [EN] Approach:
 *     Standard grid count is floor(a) * floor(b). Skew packing places rows at vertical spacing sqrt(3)/2, alternating between floor(a) and floor(a - 0.5) pipes per row.
 * [中文] 思路:
 *     網格排列為 floor(a)*floor(b)；交錯排列每層垂直間距為 sqrt(3)/2，相鄰層管數交替為 floor(a) 與 floor(a-0.5)，雙向計算取最大值。
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

int skew_count(double w, double h) {
    if (w < 1.0 || h < 1.0) return 0;
    int cols = (int)w;
    int rows = 1 + (int)((h - 1.0) / (sqrt(3.0) / 2.0));
    int even_rows = (rows + 1) / 2;
    int odd_rows = rows / 2;
    int odd_cols = (w - cols >= 0.5) ? cols : (cols - 1);
    return even_rows * cols + odd_rows * odd_cols;
}

int solve_uva121(double a, double b, int *is_skew) {
    int grid = (int)a * (int)b;
    int s1 = skew_count(a, b);
    int s2 = skew_count(b, a);
    int s_max = s1 > s2 ? s1 : s2;
    if (s_max > grid) {
        *is_skew = 1;
        return s_max;
    } else {
        *is_skew = 0;
        return grid;
    }
}

int main(void) {

    int is_skew;
    int cnt = solve_uva121(4.7, 3.5, &is_skew);
    int ok = (cnt == 15 && is_skew == 1);
    printf("%s: UVa 121 - Pipe Fitters\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
