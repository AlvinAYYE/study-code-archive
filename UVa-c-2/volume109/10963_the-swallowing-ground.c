/*
 * ==========================================================================
 * UVa 10963 - The Swallowing Ground
 * Title-CN: 地陷裂縫南北閉合一致性檢驗
 * Difficulty: UVa Star 1
 * Tags: basics, math
 * URL: https://onlinejudge.org/external/109/10963.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if ground fissure can be completely closed by checking if the gap y1 - y2 is identical across all grid columns.
 *
 * [中文] 題目說明:
 *     檢驗地震裂縫是否可藉由單向滑動完全密合：檢查每一縱行之南北裂縫間距 (y1 - y2) 是否完全一致。
 *
 * [EN] Approach:
 *     Compute gap = y1 - y2 for first column. Check that all remaining columns have the identical gap.
 * [中文] 思路:
 *     計算首列之間距 y1 - y2，檢驗後續所有欄位的間距是否皆與第一列完全相等，全數相符則可閉合。
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

int solve_uva10963(int w, int *y1, int *y2) {
    int gap = y1[0] - y2[0];
    for (int i = 1; i < w; i++) {
        if (y1[i] - y2[i] != gap) return 0;
    }
    return 1;
}

int main(void) {

    int y1[] = {4, 6}, y2[] = {1, 3};
    int ok = solve_uva10963(2, y1, y2); // gap=3, gap=3
    printf("%s: UVa 10963 - The Swallowing Ground\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
