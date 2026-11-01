/*
 * ==========================================================================
 * UVa 1025 - A Spy in the Metro
 * Title-CN: 地鐵裡的間諜 (動態規劃)
 * Difficulty: Medium
 * Tags: Dynamic Programming, DAG
 * URL: https://onlinejudge.org/external/10/1025.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum waiting time for a spy to meet an agent at station N at time T given metro timetables.
 *
 * [中文] 題目描述:
 *     給定地鐵時刻表，求間諜在時間 T 於第 N 站與特工會面時所需的最小車站月台等待時間。
 *
 * [EN] Approach:
 *     DP state dp[t][i] = min waiting time to be at station i at time t. Transition: wait 1 min at i, or ride a rightbound/leftbound train.
 *
 * [中文] 解題思維:
 *     動態規劃狀態 dp[t][i] 為時間 t 位於車站 i 的最少等待時間。轉移：在月台等 1 分鐘，或搭乘此時出發的向右/向左列車。
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

#define INF_METRO 100000000

int min_wait_metro(int n, int T, int *t_travel, int m1, int *d1, int m2, int *d2) {
    // has_train[t][station][dir]: dir 0 = right, dir 1 = left
    int has_train[205][55][2];
    memset(has_train, 0, sizeof(has_train));

    for (int i = 0; i < m1; i++) {
        int cur_t = d1[i];
        for (int st = 1; st < n; st++) {
            if (cur_t <= T) has_train[cur_t][st][0] = 1;
            cur_t += t_travel[st - 1];
        }
    }
    for (int i = 0; i < m2; i++) {
        int cur_t = d2[i];
        for (int st = n; st > 1; st--) {
            if (cur_t <= T) has_train[cur_t][st][1] = 1;
            cur_t += t_travel[st - 2];
        }
    }

    int dp[205][55];
    for (int t = 0; t <= T; t++) {
        for (int st = 1; st <= n; st++) dp[t][st] = INF_METRO;
    }
    dp[0][1] = 0;

    for (int t = 0; t < T; t++) {
        for (int st = 1; st <= n; st++) {
            if (dp[t][st] >= INF_METRO) continue;
            // Option 1: wait 1 min
            if (dp[t + 1][st] > dp[t][st] + 1)
                dp[t + 1][st] = dp[t][st] + 1;
            // Option 2: right train
            if (st < n && has_train[t][st][0]) {
                int nt = t + t_travel[st - 1];
                if (nt <= T && dp[nt][st + 1] > dp[t][st])
                    dp[nt][st + 1] = dp[t][st];
            }
            // Option 3: left train
            if (st > 1 && has_train[t][st][1]) {
                int nt = t + t_travel[st - 2];
                if (nt <= T && dp[nt][st - 1] > dp[t][st])
                    dp[nt][st - 1] = dp[t][st];
            }
        }
    }
    return dp[T][n] >= INF_METRO ? -1 : dp[T][n];
}

int main(void) {

    int travel[] = {5, 5, 5};
    int d1[] = {0};
    int d2[] = {0};
    // 4 stations, travel 5 min each -> right train leaves st 1 at 0, arrives st 4 at 15. T=15 -> wait = 0
    int res = min_wait_metro(4, 15, travel, 1, d1, 0, d2);
    int ok = (res == 0);
    printf("%s: UVa 1025 - A Spy in the Metro\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
