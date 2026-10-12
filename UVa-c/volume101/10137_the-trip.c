/*
 * ==========================================================================
 * UVa 10137 - The Trip
 * Title-CN: 旅行帳務平衡
 * Difficulty: UVa Star 2
 * Tags: math, greedy, simulation
 * URL: https://onlinejudge.org/external/101/10137.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum money that must change hands to equalize expenses within $0.01.
 *
 * [中文] 題目說明:
 *     計算最少需要交換多少金額，才能讓所有人分擔的費用差距至多為 1 分錢。
 *
 * [EN] Approach:
 *     Work in integer cents. Compute avg = sum / n and remainder rem = sum % n.
 *     Top `rem` students pay avg + 1 cent, others pay avg. Sum positive differences.
 * [中文] 思路:
 *     全部轉為分（美分）整數運算。計算平均值與餘數，分攤多於平均與少於平均之差額。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

double solve_uva10137(int n, const double *expenses) {
    long long cents[1005];
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cents[i] = (long long)round(expenses[i] * 100.0);
        total += cents[i];
    }
    long long avg = total / n;
    long long rem = total % n;

    long long pos_diff = 0, neg_diff = 0;
    for (int i = 0; i < n; i++) {
        long long diff = cents[i] - avg;
        if (diff > 0) pos_diff += diff;
        else neg_diff -= diff;
    }
    long long exchange = (pos_diff > neg_diff) ? pos_diff : neg_diff;
    if (rem > 0) {
        /* Distribute the remainder cents */
        exchange = (pos_diff - rem > neg_diff) ? (pos_diff - rem) : neg_diff;
        if (exchange < pos_diff - rem) exchange = pos_diff - rem;
    }
    long long ans_cents = (pos_diff < neg_diff) ? pos_diff : neg_diff;
    return (double)ans_cents / 100.0;
}

int main(void) {
    double exp[3] = {10.00, 20.00, 30.00};
    double res = solve_uva10137(3, exp);
    int ok = (fabs(res - 10.00) < 0.05);
    printf("%s: UVa 10137 - The Trip\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
