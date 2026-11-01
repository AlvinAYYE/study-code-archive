/*
 * ==========================================================================
 * UVa 10901 - Ferry Loading III
 * Title-CN: 渡輪裝載 III
 * Difficulty: Medium
 * Tags: Simulation, Queue
 * URL: https://onlinejudge.org/external/109/10901.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate a ferry carrying at most n cars across a river in time t, delivering them with minimum wait.
 *
 * [中文] 題目說明:
 *     模擬一次最多承載 n 輛車且單程耗時 t 的渡輪，求每輛車被運送抵達對岸的時間。
 *
 * [EN] Approach:
 *     Two queues for left and right banks. Ferry advances time to next available car if idle, loads up to n cars, and crosses.
 * [中文] 思路:
 *     左右兩岸各維護一個隊列，渡輪若空閒則時間推進到最早到達的車輛，裝載最多 n 輛車後航向對岸。
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

int simulate_ferry(int n, int t, int m, const int *arrival_time, const int *bank, int *unload_time) {
    int cur_time = 0, cur_bank = 0; // 0: left, 1: right
    int served = 0, loaded[20];
    int in_q[20] = {0};
    while (served < m) {
        int cnt = 0;
        for (int i = 0; i < m && cnt < n; i++) {
            if (!in_q[i] && bank[i] == cur_bank && arrival_time[i] <= cur_time) {
                loaded[cnt++] = i;
                in_q[i] = 1;
            }
        }
        if (cnt > 0) {
            cur_time += t;
            for (int i = 0; i < cnt; i++) {
                unload_time[loaded[i]] = cur_time;
                served++;
            }
            cur_bank = 1 - cur_bank;
        } else {
            // Check if there are cars on other side or waiting in future
            int next_t = 1000000;
            for (int i = 0; i < m; i++) {
                if (!in_q[i] && arrival_time[i] < next_t) next_t = arrival_time[i];
            }
            if (next_t > cur_time) cur_time = next_t;
            else { cur_time += t; cur_bank = 1 - cur_bank; }
        }
    }
    return cur_time;
}

int main(void) {

    int arr[] = {0, 10}, b[] = {0, 0}, un[2];
    simulate_ferry(2, 10, 2, arr, b, un);
    int ok = (un[0] == 10 && (un[1] == 10 || un[1] == 30));
    printf("%s: UVa 10901 - Ferry Loading III\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
