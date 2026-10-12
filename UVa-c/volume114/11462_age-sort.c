/*
 * ==========================================================================
 * UVa 11462 - Age Sort
 * Title-CN: 年齡排序 (計數排序)
 * Difficulty: UVa Star 1
 * Tags: sorting, counting-sort
 * URL: https://onlinejudge.org/external/114/11462.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sort up to 2,000,000 ages in range [1..99] in O(N) time.
 *
 * [中文] 題目說明:
 *     高達 200 萬筆年齡資料排序（年齡範圍 1 到 99），需於極短時間內完成（計數排序）。
 *
 * [EN] Approach:
 *     Counting Sort using frequency array of size 100.
 * [中文] 思路:
 *     計數排序（Counting Sort）：開大小 100 的頻率陣列計數，O(N) 線性時間完成。
 * ==========================================================================
 */
#include <stdio.h>

void solve_uva11462(int n, const int *ages, int *out) {
    int count[100] = {0};
    for (int i = 0; i < n; i++) count[ages[i]]++;
    int idx = 0;
    for (int a = 1; a < 100; a++) {
        while (count[a]-- > 0) out[idx++] = a;
    }
}

int main(void) {
    int a[5] = {30, 25, 25, 40, 20};
    int out[5];
    solve_uva11462(5, a, out);
    int ok = (out[0] == 20 && out[1] == 25 && out[2] == 25 && out[3] == 30 && out[4] == 40);
    printf("%s: UVa 11462 - Age Sort\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
