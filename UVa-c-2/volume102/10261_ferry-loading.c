/*
 * ==========================================================================
 * UVa 10261 - Ferry Loading
 * Title-CN: 渡輪裝載雙軌背包
 * Difficulty: Medium
 * Tags: DP, Knapsack
 * URL: https://onlinejudge.org/external/102/10261.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Load cars of varying lengths onto two parallel lanes (port and starboard) of a ferry of length L to maximize number of loaded cars.
 *
 * [中文] 題目說明:
 *     將不同長度的車輛裝載上長度為 L 的雙軌渡輪（左舷與右舷），求最多能裝載的車輛數。
 *
 * [EN] Approach:
 *     DP state dp[i][left_len] = can load first i cars with left_len on left track. Right track length = sum_lens - left_len <= L.
 * [中文] 思路:
 *     動態規劃：dp[i][j] 表示前 i 輛車在左舷總長度為 j 是否可行；右舷長度可由總長減 j 導出，檢查兩舷均 <= L。
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

int max_ferry_cars(int ferry_len_m, int n, const int *car_lens) {
    int L = ferry_len_m * 100;
    int dp[105][205] = {0};
    dp[0][0] = 1;
    int sum = 0, best = 0;
    for (int i = 0; i < n; i++) {
        int len = car_lens[i];
        bool any = false;
        for (int j = 0; j <= L && j <= 200; j++) {
            if (dp[i][j]) {
                // place on left
                if (j + len <= L && j + len <= 200) { dp[i + 1][j + len] = 1; any = true; }
                // place on right
                if (sum - j + len <= L) { dp[i + 1][j] = 1; any = true; }
            }
        }
        if (!any) break;
        sum += len;
        best = i + 1;
    }
    return best;
}

int main(void) {

    int cars[] = {50, 50, 50, 50}; // in cm
    int res = max_ferry_cars(1, 4, cars); // 1m = 100cm, can hold 2 on left, 2 on right -> 4
    int ok = (res == 4);
    printf("%s: UVa 10261 - Ferry Loading\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
