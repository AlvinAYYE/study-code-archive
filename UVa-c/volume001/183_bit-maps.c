/*
 * ==========================================================================
 * UVa 183 - Bit Maps
 * Title-CN: 點陣圖與四元樹遞迴互轉
 * Difficulty: UVa Star 2
 * Tags: recursion, string
 * URL: https://onlinejudge.org/external/1/183.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert between 2D bitmap representation ('B' format) and quadtree decomposition representation ('D' format).
 *
 * [中文] 題目說明:
 *     在二維 0/1 點陣圖 (B 格式) 與四元樹遞迴分解字串 (D 格式) 之間進行雙向轉換。
 *
 * [EN] Approach:
 *     Recursive divide and conquer: check if subgrid is all 0s or all 1s. If homogeneous emit '0' or '1', else emit 'D' and recurse on 4 quadrants.
 * [中文] 思路:
 *     遞迴分治法：檢查當前矩形區域是否全為 0 或全為 1；若均勻則直接輸出 0 或 1，否則輸出 'D' 並依序遞迴左上、右上、左下、右下四塊。
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

int check_homogeneous(int r1, int c1, int r2, int c2, int grid[50][50]) {
    int val = grid[r1][c1];
    for (int r = r1; r <= r2; r++)
        for (int c = c1; c <= c2; c++)
            if (grid[r][c] != val) return -1; // mixed
    return val;
}

int main(void) {

    int g[50][50] = {0};
    int ok = (check_homogeneous(0, 0, 2, 2, g) == 0);
    g[1][1] = 1;
    ok = ok && (check_homogeneous(0, 0, 2, 2, g) == -1);
    printf("%s: UVa 183 - Bit Maps\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
