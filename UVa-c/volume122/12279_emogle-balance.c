/*
 * ==========================================================================
 * UVa 12279 - EMOOGLE BALANCE
 * Title-CN: 微笑平衡值
 * Difficulty: UVa Star 1
 * Tags: simulation
 * ==========================================================================
 * [EN] Problem: Count elements > 0 minus elements == 0.
 * [中文] 題目說明: 給定整數數列，計算正數個數減去 0 的個數。
 * [EN] Approach: Single pass counter difference.
 * [中文] 思路: 一次迴圈統計 (數值 > 0 的個數) - (數值 == 0 的個數)。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva12279(int n, const int *arr) {
    int balance = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) balance++;
        else balance--;
    }
    return balance;
}

int main(void) {
    int a[5] = {0, 1, 0, 2, 0};
    int res = solve_uva12279(5, a); /* 2 pos - 3 zeros = -1 */
    int ok = (res == -1);
    printf("%s: UVa 12279 - EMOGLE BALANCE\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
