/*
 * ==========================================================================
 * UVa 10198 - Counting
 * Title-CN: 大數動態規劃數位和組合計數
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, math
 * URL: https://onlinejudge.org/external/101/10198.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count numbers composed of digits 1, 2, 3, 4 with sum n, where digit 4 is counted as having value 1.
 *
 * [中文] 題目說明:
 *     以數字 1, 2, 3, 4 (其中 4 的權重計為 1) 構成總和為 n 的數字組合數，推導動態規劃遞推式。
 *
 * [EN] Approach:
 *     DP recurrence: since two digits have value 1 (digits 1 and 4), T(n) = 2*T(n-1) + T(n-2) + T(n-3).
 * [中文] 思路:
 *     動態規劃狀態轉移：權重為 1 的有兩種選擇 (1 與 4)，故 T(n) = 2*T(n-1) + T(n-2) + T(n-3)。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

long long solve_uva10198(int n) {
    long long dp[50] = {0};
    dp[0] = 1; dp[1] = 2; dp[2] = 5;
    for (int i = 3; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main(void) {

    int ok = (solve_uva10198(1) == 2 && solve_uva10198(2) == 5 && solve_uva10198(3) == 13);
    printf("%s: UVa 10198 - Counting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
