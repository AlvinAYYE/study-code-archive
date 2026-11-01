/*
 * ==========================================================================
 * UVa 11824 - A Minimum Land Price
 * Title-CN: 最小土地總價格 (貪心排序)
 * Difficulty: Easy
 * Tags: Greedy, Sorting, Math
 * URL: https://onlinejudge.org/external/118/11824.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given parcel prices L_i, buying in order 1..k costs sum 2 * (L_i)^i. Find min cost and check if <= budget 5,000,000.
 *
 * [中文] 題目說明:
 *     給定土地基準價格，第 i 年購買成本為 2 * (L)^i，求最優購買順序下的最小總價，並檢查是否超支 5,000,000。
 *
 * [EN] Approach:
 *     Sort parcel prices descending so largest base prices receive smallest exponents i = 1, 2, ...
 * [中文] 思路:
 *     貪心法：將土地基準價格由大到小排序，最大者分配最小指數，使得總成本 2 * L^i 最小。
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

int cmp_desc_land(const void *a, const void *b) { return (*(int*)b - *(int*)a); }
long long min_land_cost(int n, int *prices) {
    qsort(prices, n, sizeof(int), cmp_desc_land);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long p = 1;
        for (int k = 0; k <= i; k++) p *= prices[i];
        total += 2 * p;
        if (total > 5000000) return -1; // Too expensive
    }
    return total;
}

int main(void) {

    int p[] = {7, 2};
    long long cost = min_land_cost(2, p); // 2*(7^1) + 2*(2^2) = 14 + 8 = 22
    int ok = (cost == 22);
    printf("%s: UVa 11824 - A Minimum Land Price\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
