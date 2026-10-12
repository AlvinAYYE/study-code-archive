/*
 * ==========================================================================
 * UVa 10696 - f91
 * Title-CN: 麥卡錫 91 函數
 * Difficulty: UVa Star 1
 * Tags: recursion, math
 * ==========================================================================
 * [EN] Problem: Evaluate McCarthy's f91 function.
 * [中文] 題目說明: 麥卡錫 91 函數計算：N <= 100 回傳 91，否則回傳 N - 10。
 * [EN] Approach: O(1) branch.
 * [中文] 思路: if (n <= 100) return 91; else return n - 10;
 * ==========================================================================
 */
#include <stdio.h>

int f91(int n) {
    if (n <= 100) return 91;
    return n - 10;
}

int main(void) {
    int ok = (f91(91) == 91) && (f91(101) == 91) && (f91(110) == 100);
    printf("%s: UVa 10696 - f91\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
