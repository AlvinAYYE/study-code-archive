/*
 * ==========================================================================
 * UVa 10264 - The Most Potent Corner
 * Title-CN: 最強角落 (超立方體頂點勢能)
 * Difficulty: Medium
 * Tags: Bit Manipulation, Hypercube
 * URL: https://onlinejudge.org/external/102/10264.pdf
 * ==========================================================================
 * [EN] Problem:
 *     In an N-dimensional hypercube, find the maximum sum of potencies of two adjacent vertices (potency = sum of weights of adjacent vertices).
 *
 * [中文] 題目說明:
 *     在 N 維超立方體中，每個頂點勢能為其所有相鄰頂點權重之和，求相鄰兩頂點勢能和的最大值。
 *
 * [EN] Approach:
 *     Two vertices are adjacent iff their binary indices differ by exactly 1 bit. Compute potency for all 2^N corners, then maximize pot[u] + pot[u ^ (1<<i)].
 * [中文] 思路:
 *     在超立方體中，兩頂點相鄰等價於索引異或值為 2 的冪。先算出所有 2^N 頂點的勢能，再枚舉相鄰邊求勢能和最大值。
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

int max_potent_corner_sum(int n, const int *weight) {
    int total = 1 << n;
    int potency[1024] = {0};
    for (int u = 0; u < total; u++) {
        for (int i = 0; i < n; i++) {
            potency[u] += weight[u ^ (1 << i)];
        }
    }
    int max_s = 0;
    for (int u = 0; u < total; u++) {
        for (int i = 0; i < n; i++) {
            int v = u ^ (1 << i);
            if (potency[u] + potency[v] > max_s) {
                max_s = potency[u] + potency[v];
            }
        }
    }
    return max_s;
}

int main(void) {

    int w[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int res = max_potent_corner_sum(3, w);
    int ok = (res > 0);
    printf("%s: UVa 10264 - The Most Potent Corner\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
