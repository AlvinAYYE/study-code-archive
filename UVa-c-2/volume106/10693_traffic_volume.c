/*
 * ==========================================================================
 * UVa 10693 - Traffic Volume
 * Title-CN: 交通車流量最佳化
 * Difficulty: Easy
 * Tags: Physics, Math, Calculus
 * URL: https://onlinejudge.org/external/106/10693.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the optimal vehicle velocity and maximum traffic volume given car length L and deceleration rate f.
 *
 * [中文] 題目描述:
 *     給定車身常數 L 與煞車減速度 f，求能使交通車流量（每小時通過車輛數）最大化的最佳車速與最大流量。
 *
 * [EN] Approach:
 *     Braking distance s = v^2 / (2*f). Volume V = v / (L + s) * 3600. Max volume occurs when v = sqrt(2 * f * L).
 *
 * [中文] 解題思維:
 *     煞車安全距離為 s = v^2 / (2f)，車流量為 v / (L + s) * 3600。極值條件微分後得最佳車速 v = sqrt(2 * f * L)。
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

void optimal_traffic(double L, double f, double *v_opt, double *volume_max) {
    *v_opt = sqrt(2.0 * f * L);
    *volume_max = (*v_opt / (2.0 * L)) * 3600.0;
}

int main(void) {

    double v, vol;
    optimal_traffic(4.0, 2.0, &v, &vol);
    // v = sqrt(2*2*4) = 4.0 m/s; vol = 4 / 8 * 3600 = 1800
    int ok = (fabs(v - 4.0) < 1e-4 && fabs(vol - 1800.0) < 1e-4);
    printf("%s: UVa 10693 - Traffic Volume\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
