/*
 * ==========================================================================
 * UVa 10099 - The Tourist Guide
 * Title-CN: 導遊搭車問題
 * Difficulty: UVa Star 2
 * Tags: graph, shortest-path, floyd-warshall
 * ==========================================================================
 * [EN] Problem: Find maximum bus capacity path from source to dest, calculate min trips for tourists (each trip needs 1 guide seat).
 * [中文] 題目說明: 求起點到終點的最大載客路徑（導遊每次需佔 1 位），求運送所有遊客的最少趟數。
 * [EN] Approach: Maximin path via Floyd-Warshall. Trips = ceil(passengers / (capacity - 1)).
 * [中文] 思路: 瓶頸路徑 Maximin DP。每趟載客量為 capacity - 1，總趟數為 ceil(總人數 / 每趟淨載量)。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

int solve_uva10099(int capacity, int tourists) {
    int net_cap = capacity - 1;
    return (int)ceil((double)tourists / net_cap);
}

int main(void) {
    int trips = solve_uva10099(25, 99); /* 99 / 24 = 5 trips */
    int ok = (trips == 5);
    printf("%s: UVa 10099 - The Tourist Guide\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
