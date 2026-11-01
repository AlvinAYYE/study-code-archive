/*
 * ==========================================================================
 * UVa 10696 - f91
 * Title-CN: 麥卡錫 91 函數 (McCarthy 91 Function)
 * Difficulty: UVa Star 1
 * Tags: math, recursion
 * URL: https://onlinejudge.org/external/106/10696.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute recursive McCarthy 91 function: f91(n) = n - 10 if n > 100, else f91(f91(n + 11)).
 *
 * [中文] 題目說明:
 *     計算著名的麥卡錫 91 遞迴函數：若 n <= 100 恆等於 91；若 n >= 101 恆等於 n - 10。
 *
 * [EN] Approach:
 *     Mathematical property: for all n <= 100, f91(n) = 91. For n >= 101, f91(n) = n - 10.
 * [中文] 思路:
 *     數論分析結論：當 n <= 100 時結果必為 91；當 n >= 101 時結果為 n - 10，直接 O(1) 輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10696(int n) {
    return (n <= 100) ? 91 : (n - 10);
}

int main(void) {

    int ok = (solve_uva10696(500) == 490) && (solve_uva10696(91) == 91);
    printf("%s: UVa 10696 - f91\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
