/*
 * ==========================================================================
 * UVa 10487 - Closest Sums
 * Title-CN: 最接近目標之兩數之和
 * Difficulty: UVa Star 1
 * Tags: brute-force, two-pointers
 * URL: https://onlinejudge.org/external/104/10487.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given set of integers, find the pair sum closest to query value.
 *
 * [中文] 題目說明:
 *     給定一組相異整數，尋找任選兩數相加之和，使其與詢問值之絕對差最小。
 *
 * [EN] Approach:
 *     Since n <= 1000, compute pairwise sums in O(N^2) or sort and use two pointers to find closest sum.
 * [中文] 思路:
 *     因 n <= 1000，可雙重迴圈枚舉所有數對和，維護與詢問值的最小絕對差，輸出最接近的和。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stdlib.h>

int solve_uva10487(int n, const int *a, int query) {
    int best_sum = a[0] + a[1];
    int min_diff = abs(best_sum - query);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = a[i] + a[j];
            int d = abs(s - query);
            if (d < min_diff) {
                min_diff = d;
                best_sum = s;
            }
        }
    }
    return best_sum;
}

int main(void) {

    int a[5] = {1, 2, 3, 4, 5};
    int ok = (solve_uva10487(5, a, 8) == 8); /* 3+5 */
    printf("%s: UVa 10487 - Closest Sums\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
