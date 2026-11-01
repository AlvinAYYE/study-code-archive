/*
 * ==========================================================================
 * UVa 12709 - Falling Ants
 * Title-CN: 下落螞蟻加速度最大重力判定
 * Difficulty: UVa Star 1
 * Tags: physics, math, sorting
 * URL: https://onlinejudge.org/external/127/12709.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Downward acceleration is maximized when height H is highest (lowest air resistance). Among max H, maximize volume L*W*H.
 *
 * [中文] 題目說明:
 *     下落加速度在高度 H 最大時達到極大值。在 H 最大時，求長寬高乘積 (體積 L*W*H) 最大的螞蟻體積。
 *
 * [EN] Approach:
 *     Physics formula simplifies to picking max H. Tie-breaker is max volume L * W * H.
 * [中文] 思路:
 *     由空氣阻力公式推導可知下落速度極大值完全由高度 H 決定。先篩選最大 H，再取體積 L*W*H 最大值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva12709(int n, int l[], int w[], int h[]) {
    int max_h = 0, max_vol = 0;
    for (int i = 0; i < n; i++) {
        int vol = l[i] * w[i] * h[i];
        if (h[i] > max_h || (h[i] == max_h && vol > max_vol)) {
            max_h = h[i];
            max_vol = vol;
        }
    }
    return max_vol;
}

int main(void) {

    int l[2] = {2, 3}, w[2] = {2, 3}, h[2] = {5, 4};
    int ok = (solve_uva12709(2, l, w, h) == 20);
    printf("%s: UVa 12709 - Falling Ants\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
