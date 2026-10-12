/*
 * ==========================================================================
 * UVa 10268 - 498-bis
 * Title-CN: 多項式微分求值
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, polynomial, horner-rule
 * URL: https://onlinejudge.org/external/102/10268.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute derivative P'(x) for a given polynomial at x using Horner's method.
 *
 * [中文] 題目說明:
 *     給定多項式係數與 x，計算導數 P'(x) 的值。
 *
 * [EN] Approach: Horner's method for derivative evaluation in O(n).
 * [中文] 思路: 霍納法則一次線性掃描，避免重複計算次方。
 * ==========================================================================
 */
#include <stdio.h>

long long solve_uva10268(long long x, const long long *a, int n) {
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = ans * x + a[i] * (n - 1 - i);
    }
    return ans;
}

int main(void) {
    long long a[] = {1, -2, 1}; /* P(x) = x^2 - 2x + 1, P'(x) = 2x - 2 */
    long long res = solve_uva10268(7, a, 3); /* P'(7) = 14 - 2 = 12 */
    int ok = (res == 12);
    printf("%s: UVa 10268 - 498-bis\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
