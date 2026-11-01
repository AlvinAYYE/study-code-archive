/*
 * ==========================================================================
 * UVa 11401 - Triangle Counting
 * Title-CN: 長度 1 到 N 線段構成三角形組合計數
 * Difficulty: UVa Star 2
 * Tags: math, combinatorics
 * URL: https://onlinejudge.org/external/114/11401.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given sticks of integer lengths 1, 2, ..., N, find the number of ways to pick 3 distinct sticks that can form a non-degenerate triangle.
 *
 * [中文] 題目概述:
 *     給定長度分別為 1, 2, ..., N 的木棒，求任意挑選三根相異木棒能構成非退化三角形的選法總數。
 *
 * [EN] Approach:
 *     Recurrence / closed form: delta(n) = (n-1)*(n-2)/2 - floor((n-1)/2). Accumulate delta to compute total triangles in O(N) or closed formula.
 * [中文] 解題思路:
 *     最長邊為 n 時，其餘兩邊之和須大於 n，新增三角形數為 ((n-1)(n-2)/2 - floor((n-1)/2))/2，遞推前綴和求解。
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

long long solve_uva11401(long long n) {
    if (n < 3) return 0;
    long long ans = 0;
    long long cur = 0;
    for (long long i = 4; i <= n; i++) {
        cur += (i - 2) / 2;
        ans += cur;
    }
    return ans;
}

int main(void) {

    int ok = (solve_uva11401(3) == 0 && solve_uva11401(4) == 1 && solve_uva11401(5) == 3);
    printf("%s: UVa 11401 - Triangle Counting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
