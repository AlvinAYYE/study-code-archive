/*
 * ==========================================================================
 * UVa 10918 - Tri Tiling
 * Title-CN: 3 x n 骨牌鋪滿計數
 * Difficulty: Medium
 * Tags: DP, Recurrence Relation
 * URL: https://onlinejudge.org/external/109/10918.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of ways to completely tile a 3 x n grid with 2 x 1 dominoes.
 *
 * [中文] 題目說明:
 *     求用 2 x 1 骨牌鋪滿 3 x n 矩形網格的方案總數（n 為奇數時為 0）。
 *
 * [EN] Approach:
 *     When n is odd, answer is 0. Recurrence: f(n) = 4*f(n-2) - f(n-4) with f(0)=1, f(2)=3.
 * [中文] 思路:
 *     n 為奇數時面積為奇數無法鋪滿（答案為 0）；偶數時滿足遞推關係式 f(n) = 4*f(n-2) - f(n-4)，初值 f(0)=1, f(2)=3。
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

long long tri_tiling(int n) {
    if (n % 2 != 0) return 0;
    long long f[35] = {0};
    f[0] = 1; f[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        f[i] = 4 * f[i - 2] - f[i - 4];
    }
    return f[n];
}

int main(void) {

    int ok = (tri_tiling(2) == 3) && (tri_tiling(4) == 11) && (tri_tiling(3) == 0);
    printf("%s: UVa 10918 - Tri Tiling\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
