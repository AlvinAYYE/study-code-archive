/*
 * ==========================================================================
 * UVa 836 - Largest Submatrix
 * Title-CN: 全為 1 之最大二維子矩陣面積
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming
 * URL: https://onlinejudge.org/external/8/836.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum area of a submatrix composed entirely of '1's in a binary grid of characters.
 *
 * [中文] 題目說明:
 *     在二維 0/1 字元矩陣中，尋找內部所有元素全為 '1' 的最大子矩陣面積。
 *
 * [EN] Approach:
 *     2D prefix sums: check in O(1) if submatrix (r1, c1) to (r2, c2) has sum == (r2-r1+1)*(c2-c1+1). Take maximum area.
 * [中文] 思路:
 *     二維前綴和：以 O(1) 檢驗任意子矩陣元素和是否等於其寬長乘積 (即全為 1)，枚舉維護最大面積。
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

int solve_uva836(int n, char g[20][20]) {
    int pref[25][25] = {0};
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            pref[r][c] = (g[r - 1][c - 1] - '0') + pref[r - 1][c] + pref[r][c - 1] - pref[r - 1][c - 1];
        }
    }
    int max_area = 0;
    for (int r1 = 1; r1 <= n; r1++) {
        for (int c1 = 1; c1 <= n; c1++) {
            for (int r2 = r1; r2 <= n; r2++) {
                for (int c2 = c1; c2 <= n; c2++) {
                    int area = (r2 - r1 + 1) * (c2 - c1 + 1);
                    int sum = pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1];
                    if (sum == area && area > max_area) max_area = area;
                }
            }
        }
    }
    return max_area;
}

int main(void) {

    char g[20][20] = {"110", "110", "000"};
    int a = solve_uva836(3, g);
    int ok = (a == 4);
    printf("%s: UVa 836 - Largest Submatrix\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
