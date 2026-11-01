/*
 * ==========================================================================
 * UVa 10323 - Factorial! You Must be Kidding!!!
 * Title-CN: 階乘溢位範圍檢測 (Underflow / Overflow)
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/103/10323.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute n! if it fits between 10,000 and 6,227,020,800. Output Underflow or Overflow otherwise.
 *
 * [中文] 題目說明:
 *     計算 n!，若結果小於 10000 輸出 Underflow!，大於 6227020800 輸出 Overflow!，在區間內輸出具體數值 (負數考慮擴展階乘)。
 *
 * [EN] Approach:
 *     Valid range is 8 <= n <= 13. If n < 0, negative odd gives Overflow, negative even gives Underflow.
 * [中文] 思路:
 *     對於 n >= 0，僅 8 到 13 之階乘落在合法區間內；負數時利用 Gamma 函數極限，奇數為 Overflow，偶數為 Underflow。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva10323(int n, int *status) {
    if (n < 0) {
        *status = (n % 2 != 0) ? 1 : -1; /* 1: Overflow, -1: Underflow */
        return 0;
    }
    if (n < 8) { *status = -1; return 0; }
    if (n > 13) { *status = 1; return 0; }
    *status = 0;
    long long ans = 1;
    for (int i = 2; i <= n; i++) ans *= i;
    return ans;
}

int main(void) {

    int st;
    long long v = solve_uva10323(10, &st);
    int ok = (st == 0 && v == 3628800);
    printf("%s: UVa 10323 - Factorial! You Must be Kidding!!!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
