/*
 * ==========================================================================
 * UVa 568 - Just the Facts
 * Title-CN: 階乘末尾最後一個非零數字
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * ==========================================================================
 * [EN] Problem: Find the last non-zero digit of N! for N <= 10000.
 * [中文] 題目說明: 求 N! 末尾最後一個非零數字。
 * [EN] Approach: Maintain product modulo 100000 while dividing out factors of 10.
 * [中文] 思路: 每次乘法後消除末尾 0 並對適當大模數取餘數保持精度。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva568(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        while (ans % 10 == 0) ans /= 10;
        ans %= 100000;
    }
    return ans % 10;
}

int main(void) {
    int ok = (solve_uva568(5) == 2) && (solve_uva568(7) == 4);
    printf("%s: UVa 568 - Just the Facts\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
