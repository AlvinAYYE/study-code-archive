/*
 * ==========================================================================
 * UVa 575 - Skew Binary
 * Title-CN: 斜二進位制轉十進位
 * Difficulty: UVa Star 1
 * Tags: math, base-conversion
 * ==========================================================================
 * [EN] Problem: Convert skew binary string (k-th digit from right has weight 2^k - 1) to decimal.
 * [中文] 題目說明: 斜二進位第 k 位權重為 2^k - 1，將其轉為十進位數值。
 * [EN] Approach: Sum d_k * ((1 << k) - 1).
 * [中文] 思路: 從最低位向高位遍歷，依公式 d * ((1 << k) - 1) 累加。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

long long solve_uva575(const char *s) {
    int len = (int)strlen(s);
    long long sum = 0;
    for (int i = 0; i < len; i++) {
        int k = len - i;
        long long weight = (1LL << k) - 1;
        sum += (s[i] - '0') * weight;
    }
    return sum;
}

int main(void) {
    int ok = (solve_uva575("10120") == 44) && (solve_uva575("110") == 10);
    printf("%s: UVa 575 - Skew Binary\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
