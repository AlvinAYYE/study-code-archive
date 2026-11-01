/*
 * ==========================================================================
 * UVa 10310 - Dog and Gopher
 * Title-CN: 地鼠與獵犬逃生地洞距離幾何判斷
 * Difficulty: UVa Star 1
 * Tags: geometry
 * URL: https://onlinejudge.org/external/103/10310.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a gopher can reach a gopher hole before a dog catches it (dog runs twice as fast as the gopher).
 *
 * [中文] 題目說明:
 *     獵犬奔跑速度為地鼠的兩倍，檢驗地鼠是否能在獵犬攔截前逃入某個地洞 (即 2 * dist(gopher, hole) <= dist(dog, hole))。
 *
 * [EN] Approach:
 *     A gopher escapes into hole H if distance(G, H) * 2 <= distance(D, H), or 4 * dist^2(G, H) <= dist^2(D, H).
 * [中文] 思路:
 *     四倍地鼠至地洞距離平方小於等於獵犬至地洞距離平方時，地鼠可成功逃脫，輸出該地洞座標。
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

int solve_uva10310(double gx, double gy, double dx, double dy, double hx, double hy) {
    double d_g2 = (gx - hx)*(gx - hx) + (gy - hy)*(gy - hy);
    double d_d2 = (dx - hx)*(dx - hx) + (dy - hy)*(dy - hy);
    return (4.0 * d_g2 <= d_d2 + 1e-9);
}

int main(void) {

    int ok = solve_uva10310(1, 0, 0, 5, 1, 1);
    printf("%s: UVa 10310 - Dog and Gopher\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
