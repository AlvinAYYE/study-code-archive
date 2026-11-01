/*
 * ==========================================================================
 * UVa 13109 - Elephants
 * Title-CN: 大象過橋最多數量 (貪婪重量排序)
 * Difficulty: UVa Star 1
 * Tags: greedy, sorting
 * URL: https://onlinejudge.org/external/131/13109.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find maximum number of elephants that can stand on a bridge of total capacity W.
 *
 * [中文] 題目說明:
 *     木橋最大載重為 W，求在不超出橋樑負載限制下，最多能讓多少隻大象同時上橋 (貪婪重量由小到大排序)。
 *
 * [EN] Approach:
 *     Greedy choice: sort elephant weights in ascending order. Greedily pick lightest elephants while cumulative sum <= W.
 * [中文] 思路:
 *     貪婪策略：大象重量升序排序，優先選最輕的大象累加重量，直到超出承重限制為止。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva13109(int m, int w, int *weights) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (weights[i] > weights[j]) { int t = weights[i]; weights[i] = weights[j]; weights[j] = t; }
        }
    }
    int cnt = 0, sum = 0;
    for (int i = 0; i < m; i++) {
        if (sum + weights[i] <= w) {
            sum += weights[i];
            cnt++;
        } else break;
    }
    return cnt;
}

int main(void) {

    int wt[3] = {300, 200, 100};
    int ok = (solve_uva13109(3, 350, wt) == 2); /* 100 + 200 = 300 <= 350 */
    printf("%s: UVa 13109 - Elephants\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
