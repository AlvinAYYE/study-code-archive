/*
 * ==========================================================================
 * UVa 13012 - Identifying tea
 * Title-CN: 品茶盲測正確人數計數
 * Difficulty: UVa Star 1
 * Tags: simulation
 * ==========================================================================
 * [EN] Problem: Given correct tea type T and 5 contestants' answers, count how many contestants guessed correctly.
 * [中文] 題目說明: 盲測品茶：給定正確茶種編號 T 與 5 位參賽者的答案，統計猜對的人數。
 * [EN] Approach: Count answers matching T.
 * [中文] 思路: 統計與 T 相同答案的個數。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva13012(int t, const int *answers) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) if (answers[i] == t) cnt++;
    return cnt;
}

int main(void) {
    int ans[5] = {1, 2, 3, 2, 1};
    int ok = (solve_uva13012(1, ans) == 2);
    printf("%s: UVa 13012 - Identifying tea\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
