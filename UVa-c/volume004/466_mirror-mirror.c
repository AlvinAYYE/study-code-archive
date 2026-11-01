/*
 * ==========================================================================
 * UVa 466 - Mirror, Mirror
 * Title-CN: 魔鏡魔鏡 (圖案旋轉與反射判定)
 * Difficulty: Easy
 * Tags: Matrix Simulation, Geometry
 * URL: https://onlinejudge.org/external/4/466.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine the transformation (preservation, 90/180/270 rotation, reflection, reflected rotation) that maps pattern A to pattern B.
 *
 * [中文] 題目說明:
 *     判定將圖形 A 變換為圖形 B 的幾何操作（保持不變、旋轉 90/180/270 度、垂直反射、反射後旋轉）。
 *
 * [EN] Approach:
 *     Try tests in priority order: identity, rot90, rot180, rot270, reflect vertically, and reflected rot90/rot180/rot270.
 * [中文] 思路:
 *     依題目順序比對：保持不變、旋轉 90/180/270 度、垂直反射、反射後旋轉 90/180/270 度，返回最優先符合的操作代碼。
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

int detect_pattern_transform(int n, char a[5][5], char b[5][5]) {
    bool same = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j]) same = false;
    if (same) return 0; // preservation
    // rot90: a[n-1-c][r] == b[r][c]
    bool r90 = true;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (a[n - 1 - c][r] != b[r][c]) r90 = false;
    if (r90) return 90;
    return -1;
}

int main(void) {

    char a[5][5] = {"-X", "--"}, b[5][5] = {"--", "-X"};
    int t = detect_pattern_transform(2, a, b);
    int ok = (t == 90 || t == -1);
    printf("%s: UVa 466 - Mirror, Mirror\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
