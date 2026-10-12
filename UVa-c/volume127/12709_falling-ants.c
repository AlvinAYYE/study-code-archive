/*
 * ==========================================================================
 * UVa 12709 - Falling Ants
 * Title-CN: 下落的螞蟻
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Max acceleration implies max height H. Among max H, find max volume L*W*H.
 * [中文] 題目說明: 尋找加速度最大（等價於高度 H 最大）的螞蟻，若高度相同則取體積 L*W*H 最大者。
 * [EN] Approach: Filter max H, then max L*W*H.
 * [中文] 思路: 雙重比較：高度優先，體積次之。
 * ==========================================================================
 */
#include <stdio.h>

void solve_uva12709(int n, const int ants[][3], int *best_vol) {
    int max_h = -1, max_v = -1;
    for (int i = 0; i < n; i++) {
        int l = ants[i][0], w = ants[i][1], h = ants[i][2];
        int vol = l * w * h;
        if (h > max_h || (h == max_h && vol > max_v)) {
            max_h = h;
            max_v = vol;
        }
    }
    *best_vol = max_v;
}

int main(void) {
    int ants[2][3] = {{10, 10, 10}, {5, 5, 20}};
    int vol;
    solve_uva12709(2, ants, &vol);
    int ok = (vol == 500); /* H=20 wins */
    printf("%s: UVa 12709 - Falling Ants\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
