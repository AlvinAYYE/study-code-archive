/*
 * ==========================================================================
 * UVa 12650 - Dangerous Dive
 * Title-CN: 危險潛水失蹤名單比對
 * Difficulty: UVa Star 1
 * Tags: simulation, array
 * URL: https://onlinejudge.org/external/126/12650.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N volunteers went diving, R returned with listed IDs. Output IDs of missing divers in ascending order or '*' if all returned.
 *
 * [中文] 題目說明:
 *     N 名潛水員出任務，R 名志工安全返回。輸出未生還者 (未在返回名單中) 的編號由小到大排列；全員生還輸出 '*'。
 *
 * [EN] Approach:
 *     Boolean array of size N+1. Mark returned IDs. Output all unmarked IDs.
 * [中文] 思路:
 *     布林陣列標記返回者編號。若 R == N 輸出 '*'；否則由 1 到 N 巡訪輸出所有未標記的失蹤者編號。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva12650(int n, int r, const int *returned, int *missing) {
    if (n == r) return 0; /* All returned */
    int ret[10005] = {0};
    for (int i = 0; i < r; i++) ret[returned[i]] = 1;
    int m_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!ret[i]) missing[m_cnt++] = i;
    }
    return m_cnt;
}

int main(void) {

    int ret[3] = {1, 3, 5};
    int miss[5];
    int cnt = solve_uva12650(5, 3, ret, miss);
    int ok = (cnt == 2 && miss[0] == 2 && miss[1] == 4);
    printf("%s: UVa 12650 - Dangerous Dive\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
