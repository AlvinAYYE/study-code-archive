/*
 * ==========================================================================
 * UVa 11235 - Frequent values
 * Title-CN: 區間最高頻率連續值統計
 * Difficulty: UVa Star 2
 * Tags: data-structures, rmq
 * URL: https://onlinejudge.org/external/112/11235.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a non-decreasing sorted array, find the maximum frequency of any value in query range [L, R].
 *
 * [中文] 題目說明:
 *     給定一個非遞減排序整數陣列，求指定區間 [L, R] 內出現頻率最高之數值的出現次數。
 *
 * [EN] Approach:
 *     Count frequencies of elements within the range [L, R] and return the maximum frequency.
 * [中文] 思路:
 *     在非遞減陣列中統計區間 [L, R] 內連續相同數值的最大連續長度並回傳。
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

int solve_uva11235(int n, int *arr, int l, int r) {
    int max_freq = 0, cur_freq = 0;
    for (int i = l; i <= r; i++) {
        if (i == l || arr[i] == arr[i - 1]) cur_freq++;
        else cur_freq = 1;
        if (cur_freq > max_freq) max_freq = cur_freq;
    }
    return max_freq;
}

int main(void) {

    int a[] = {-1, -1, 1, 1, 1, 1, 3, 10, 10, 10};
    int ans = solve_uva11235(10, a, 5, 9);
    int ok = (ans == 3);
    printf("%s: UVa 11235 - Frequent values\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
