/*
 * ==========================================================================
 * UVa 11057 - Exact Sum
 * Title-CN: 精準買書金額配對 (雙指標差值最小化)
 * Difficulty: UVa Star 1
 * Tags: two-pointers, sorting, binary-search
 * URL: https://onlinejudge.org/external/110/11057.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find pair of book prices summing to M with minimum difference between prices.
 *
 * [中文] 題目說明:
 *     從書籍價格清單中挑選兩本書，總價格恰等於 M，且兩本書價差最小 (排序後雙指標搜尋)。
 *
 * [EN] Approach:
 *     Sort array. Use two pointers (left=0, right=n-1). When sum == M, update best pair and advance left.
 * [中文] 思路:
 *     將書籍價格升序排序，左右雙指標由兩端向中間逼近。和等於 M 時記錄最佳配對，逼近至相遇即保證價差最小。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva11057(int n, int *prices, int m, int *b1, int *b2) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices[i] > prices[j]) { int t = prices[i]; prices[i] = prices[j]; prices[j] = t; }
        }
    }
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = prices[l] + prices[r];
        if (sum == m) {
            *b1 = prices[l]; *b2 = prices[r];
            l++; r--;
        } else if (sum < m) l++;
        else r--;
    }
}

int main(void) {

    int p[5] = {10, 2, 5, 8, 40};
    int b1, b2;
    solve_uva11057(5, p, 10, &b1, &b2);
    int ok = (b1 == 2 && b2 == 8);
    printf("%s: UVa 11057 - Exact Sum\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
