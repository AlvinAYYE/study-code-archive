/*
 * ==========================================================================
 * UVa 11300 - Spreading the Wealth
 * Title-CN: 財富分配
 * Difficulty: Medium
 * Tags: Greedy, Math, Median
 * URL: https://onlinejudge.org/external/113/11300.pdf
 * ==========================================================================
 * [EN] Problem:
 *     People sitting in a circle each have some gold coins. Find the minimum total amount of transferred coins to make everyone's gold equal.
 *
 * [中文] 題目概述:
 *     圍成一圈的人各自擁有若干金幣，求使每個人金幣數量相等的最少轉移金幣總量。
 *
 * [EN] Approach:
 *     Formulate as |x1| + |x1 - C1| + |x1 - C2| + ... Total cost is minimized when x1 is the median of prefix imbalances C.
 * [中文] 解題思路:
 *     轉換為數學式 sum(|x1 - C_i|)，當 x1 取 C 序列的中位數時轉移總量最小。
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

long long min_coin_transfers(int n, const long long *a) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    long long avg = sum / n;
    long long c[100];
    c[0] = 0;
    for (int i = 1; i < n; i++) c[i] = c[i - 1] + a[i - 1] - avg;
    // sort c
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (c[i] > c[j]) { long long tmp = c[i]; c[i] = c[j]; c[j] = tmp; }
    long long x1 = c[n / 2];
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += llabs(x1 - c[i]);
    return ans;
}

int main(void) {

    long long a[] = {1, 2, 5, 4}; // avg = 3
    long long res = min_coin_transfers(4, a);
    int ok = (res == 4);
    printf("%s: UVa 11300 - Spreading the Wealth\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
