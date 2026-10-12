/*
 * ==========================================================================
 * UVa 10038 - Jolly Jumpers
 * Title-CN: 快樂的跳躍者
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: array, simulation
 * URL: https://onlinejudge.org/external/100/10038.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     A sequence of n numbers (n > 0) is called a jolly jumper if the absolute
 *     values of the differences between successive elements take on all the
 *     values 1 through n - 1.
 *     Determine whether each input sequence is a jolly jumper.
 *
 * [中文] 題目說明:
 *     一個長度為 n 的數列，如果相鄰兩數之差的絕對值，恰好包含了從 1 到 n - 1
 *     的所有整數（每個剛好出現一次），則稱之為 Jolly Jumper（快樂的跳躍者）。
 *     若滿足條件輸出 "Jolly"，否則輸出 "Not jolly"。
 *
 * Examples:
 *   Input:
 *     4 1 4 2 3  -> diffs: |1-4|=3, |4-2|=2, |2-3|=1 -> contains 1, 2, 3 -> Jolly
 *     5 1 4 2 -1 6 -> Not jolly
 *
 * [EN] Approach:
 *     Use a boolean/visited array of size n to track differences between 1 and n-1.
 * [中文] 思路:
 *     計算相鄰差值絕對值 d = |a[i] - a[i-1]|。若 d < 1 或 d >= n 或已出現過，
 *     則非 Jolly Jumper。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve_uva10038(int n, const int *arr) {
    if (n <= 1) return 1;
    int visited[3005] = {0};

    for (int i = 0; i < n - 1; i++) {
        int diff = abs(arr[i] - arr[i + 1]);
        if (diff < 1 || diff >= n || visited[diff]) {
            return 0;
        }
        visited[diff] = 1;
    }
    return 1;
}

int main(void) {
    int seq1[] = {1, 4, 2, 3};
    int r1 = solve_uva10038(4, seq1);

    int seq2[] = {1, 4, 2, -1, 6};
    int r2 = solve_uva10038(5, seq2);

    int ok = (r1 == 1) && (r2 == 0);
    printf("%s: UVa 10038 - Jolly Jumpers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
