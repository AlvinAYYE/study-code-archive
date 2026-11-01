/*
 * ==========================================================================
 * UVa 10499 - The Land of Justice
 * Title-CN: 正義之國的球體切割獲利
 * Difficulty: UVa Star 1
 * Tags: math, geometry
 * URL: https://onlinejudge.org/external/104/10499.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A solid sphere is cut into N equal parts. Compute percentage profit based on surface area increase.
 *
 * [中文] 題目說明:
 *     將實心均勻球體切成 N 等分 (瓜瓣形)，表面積增加部分為獲利，求利潤百分比 (N=1 時利潤為 0%)。
 *
 * [EN] Approach:
 *     Sphere area = 4*pi*r^2. N slices add N great circle areas = N * pi * r^2. Profit ratio = N * pi * r^2 / (4 * pi * r^2) = N / 4 = 25 * N %.
 * [中文] 思路:
 *     球體原本表面積 4*pi*r^2，切成 N 等分增加 N 個大圓半圓面 (面積為 N*pi*r^2)，獲利為 25 * N % (特判 N=1 為 0%)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva10499(long long n) {
    if (n <= 1) return 0;
    return n * 25;
}

int main(void) {

    int ok = (solve_uva10499(1) == 0) && (solve_uva10499(2) == 50) && (solve_uva10499(4) == 100);
    printf("%s: UVa 10499 - The Land of Justice\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
