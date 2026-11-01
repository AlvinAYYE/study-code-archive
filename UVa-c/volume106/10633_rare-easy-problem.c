/*
 * ==========================================================================
 * UVa 10633 - Rare Easy Problem
 * Title-CN: 稀有簡單題 (N - N/10 = M 數學還原)
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/106/10633.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given M = N - floor(N/10), reconstruct all possible original integers N.
 *
 * [中文] 題目說明:
 *     已知 M = N - floor(N/10)，求所有可能的原始正整數 N (依升序輸出)。
 *
 * [EN] Approach:
 *     N = (10*M - d) / 9 where d is the last digit 0..9. Check if (10*M - d) % 9 == 0 and satisfies formula.
 * [中文] 思路:
 *     數學推導：N - N/10 = 9*(N/10) + (N%10) = M。因此 N 約為 10*M / 9，檢驗相鄰候選數值即可精確求出所有解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva10633(unsigned long long m, unsigned long long *ans, int *cnt) {
    *cnt = 0;
    for (int d = 9; d >= 0; d--) {
        if ((10 * m - d) % 9 == 0) {
            unsigned long long n = (10 * m - d) / 9;
            if (n - n / 10 == m) ans[(*cnt)++] = n;
        }
    }
}

int main(void) {

    unsigned long long ans[2]; int cnt;
    solve_uva10633(18, ans, &cnt);
    int ok = (cnt >= 1 && (ans[0] == 19 || ans[0] == 20));
    printf("%s: UVa 10633 - Rare Easy Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
