/*
 * ==========================================================================
 * UVa 10642 - Can You Solve It?
 * Title-CN: 你能解開它嗎？
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, geometry
 * URL: https://onlinejudge.org/external/106/10642.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Coordinates are numbered along diagonals: (0,0)=0, (0,1)=1, (1,0)=2, etc.
 *     Find the distance (step count) between (x1, y1) and (x2, y2).
 *
 * [中文] 題目說明:
 *     座標系統依對角線排序編號：(0,0) 為步數 0，(0,1) 為 1，(1,0) 為 2...
 *     求從點 (x1, y1) 走到點 (x2, y2) 需要經過的步數。
 *
 * [EN] Approach:
 *     Index of point (x, y) with sum s = x + y is: s * (s + 1) / 2 + x.
 *     Distance = index(x2, y2) - index(x1, y1).
 * [中文] 思路:
 *     點 (x, y) 位於第 s = x + y 條斜線上，步數為 s * (s + 1) / 2 + x。兩點相減即可。
 * ==========================================================================
 */
#include <stdio.h>

long long get_step(long long x, long long y) {
    long long s = x + y;
    return s * (s + 1) / 2 + x;
}

long long solve_uva10642(long long x1, long long y1, long long x2, long long y2) {
    return get_step(x2, y2) - get_step(x1, y1);
}

int main(void) {
    int ok = (solve_uva10642(0, 0, 0, 1) == 1) && (solve_uva10642(0, 0, 1, 0) == 2);
    printf("%s: UVa 10642 - Can You Solve It?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
