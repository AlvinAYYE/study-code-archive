/*
 * ==========================================================================
 * UVa 10440 - Ferry Loading II
 * Title-CN: 渡輪載車 II (最小航行時間與趟數)
 * Difficulty: Medium
 * Tags: Greedy, Dynamic Programming
 * URL: https://onlinejudge.org/external/104/10440.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine the minimum total time and trips to ferry all cars across a river with capacity n and one-way trip time t.
 *
 * [中文] 題目描述:
 *     渡輪每次最多乘載 n 輛車，單程時間 t，求運送全部 m 輛車過河所需的最小總時間與渡輪航行趟數。
 *
 * [EN] Approach:
 *     Greedy strategy: The first trip carries m % n cars (or n if m % n == 0) to ensure remaining trips carry full loads of n cars.
 *
 * [中文] 解題思維:
 *     貪心策略：第一趟運載 m % n 輛車（若為 0 則運 n 輛），使後續每一趟均載滿 n 輛車以達成最少總趟數與最短完成時間。
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

void ferry_loading_ii(int n, int t, int m, int *car_times, int *total_time, int *trips) {
    int first_load = (m % n == 0) ? n : (m % n);
    int cur_time = car_times[first_load - 1] + 2 * t;
    int num_trips = 1;

    for (int i = first_load + n - 1; i < m; i += n) {
        if (cur_time < car_times[i]) cur_time = car_times[i];
        cur_time += 2 * t;
        num_trips++;
    }
    *total_time = cur_time - t; // subtract return trip of last batch
    *trips = num_trips;
}

int main(void) {

    int cars[] = {0, 10, 20}; // n=2, t=10, m=3 -> first trip carries 1 car (at time 0, returns at 20), second carries 2 (at time 20, arrives at 30)
    int time, trips;
    ferry_loading_ii(2, 10, 3, cars, &time, &trips);
    int ok = (time == 30 && trips == 2);
    printf("%s: UVa 10440 - Ferry Loading II\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
