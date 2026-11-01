/*
 * ==========================================================================
 * UVa 10827 - Maximum sum on a torus
 * Title-CN: 環面上的最大子矩陣和
 * Difficulty: Medium
 * Tags: DP, Maximum Submatrix
 * URL: https://onlinejudge.org/external/108/10827.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum submatrix sum on an N x N torus (wrapping both horizontally and vertically).
 *
 * [中文] 題目概述:
 *     在一個 N x N 的環面上（水平與垂直方向均循環相連），尋找最大子矩陣和。
 *
 * [EN] Approach:
 *     Duplicate the torus to 2N x 2N. Compute 2D prefix sums and find max sum of subgrid of size at most N x N.
 * [中文] 解題思路:
 *     將環面擴展為 2N x 2N 網格，計算二維前綴和，枚舉高寬各不超過 N 的子矩陣最大和。
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

int max_torus_sum(int n, int a[5][5]) {
    int max_s = -1000000;
    for (int r1 = 0; r1 < n; r1++) {
        for (int c1 = 0; c1 < n; c1++) {
            for (int h = 1; h <= n; h++) {
                for (int w = 1; w <= n; w++) {
                    int cur = 0;
                    for (int i = 0; i < h; i++)
                        for (int j = 0; j < w; j++)
                            cur += a[(r1 + i) % n][(c1 + j) % n];
                    if (cur > max_s) max_s = cur;
                }
            }
        }
    }
    return max_s;
}

int main(void) {

    int a[5][5] = {{1, -1}, {-1, 1}};
    int ok = (max_torus_sum(2, a) == 1);
    printf("%s: UVa 10827 - Maximum sum on a torus\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
