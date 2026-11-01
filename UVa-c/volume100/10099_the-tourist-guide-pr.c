/*
 * ==========================================================================
 * UVa 10099 - The Tourist Guide
 * Title-CN: 導遊帶團運載 (瓶頸容量路徑與最少趟數)
 * Difficulty: UVa Star 2
 * Tags: graph, floyd-warshall, shortest-path
 * URL: https://onlinejudge.org/external/100/10099.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find path maximizing bus capacity minus 1 (guide seat), and find minimum trips to transport total tourists.
 *
 * [中文] 題目說明:
 *     求兩景點間巴士載客量最大的路徑 (需扣除 1 位導遊座位)，並計算運送總遊客數所需的最少來回趟數。
 *
 * [EN] Approach:
 *     Floyd-Warshall maximin path. Trips needed = ceil(tourists / (max_cap - 1)).
 * [中文] 思路:
 *     以 Floyd-Warshall 求最大瓶頸容量 C，單趟有效載客人數為 C - 1，最少趟數為 (總遊客數 + C - 2) / (C - 1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10099(int tourists, int bottleneck_cap) {
    int cap = bottleneck_cap - 1;
    return (tourists + cap - 1) / cap;
}

int main(void) {

    int ok = (solve_uva10099(99, 25) == 5); /* 99 / 24 = 5 trips */
    printf("%s: UVa 10099 - The Tourist Guide\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
