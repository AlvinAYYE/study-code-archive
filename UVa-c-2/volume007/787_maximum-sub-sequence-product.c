/*
 * ==========================================================================
 * UVa 787 - Maximum Sub-sequence Product
 * Title-CN: 最大連續子數組乘積
 * Difficulty: Medium
 * Tags: DP, Math
 * URL: https://onlinejudge.org/external/7/787.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the maximum product of a non-empty contiguous subsequence in an integer sequence.
 *
 * [中文] 題目概述:
 *     求一個整數序列中連續非空子序列的最大乘積。
 *
 * [EN] Approach:
 *     Maintain max_product and min_product ending at current index (as negative numbers flip signs). Track global maximum.
 * [中文] 解題思路:
 *     動態規劃維護以當前元素結尾的最大乘積與最小乘積（負負得正），並持續更新全局最大值。
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

long long max_subarray_product(int n, const long long *a) {
    long long max_p = a[0], min_p = a[0], best = a[0];
    for (int i = 1; i < n; i++) {
        long long v = a[i];
        if (v < 0) { long long tmp = max_p; max_p = min_p; min_p = tmp; }
        max_p = (v > max_p * v ? v : max_p * v);
        min_p = (v < min_p * v ? v : min_p * v);
        if (max_p > best) best = max_p;
    }
    return best;
}

int main(void) {

    long long arr[] = {2, 4, -3, -2};
    long long res = max_subarray_product(4, arr);
    int ok = (res == 48);
    printf("%s: UVa 787 - Maximum Sub-sequence Product\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
