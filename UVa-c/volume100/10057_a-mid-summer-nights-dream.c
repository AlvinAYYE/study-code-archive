/*
 * ==========================================================================
 * UVa 10057 - A mid-summer night's dream
 * Title-CN: 仲夏夜之夢
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, sorting, median
 * URL: https://onlinejudge.org/external/100/10057.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find integer A that minimizes sum |X_i - A|. Output min A, count of X_i
 *     equal to valid optimal A, and total number of possible integer values for A.
 *
 * [中文] 題目說明:
 *     給定 N 個整數，求整數 A 使得總絕對距離和最小。輸出：最小的可能 A、
 *     輸入中有幾個數可作為最佳解 A、以及共有幾種整數可做為最佳解 A。
 *
 * [EN] Approach:
 *     Sort array. For odd N, A = arr[N/2]. For even N, any integer in [arr[N/2-1], arr[N/2]]
 *     minimizes the distance.
 * [中文] 思路:
 *     排序後找中位數。偶數個數時區間 [mid1, mid2] 內的整數皆為最佳解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void solve_uva10057(int n, int *arr, int *minA, int *count_in_input, int *possibleA) {
    qsort(arr, (size_t)n, sizeof(int), cmp);
    int mid1 = arr[(n - 1) / 2];
    int mid2 = arr[n / 2];
    *minA = mid1;
    *possibleA = mid2 - mid1 + 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == mid1 || arr[i] == mid2) cnt++;
    }
    *count_in_input = cnt;
}

int main(void) {
    int arr[] = {10, 10};
    int a, c, p;
    solve_uva10057(2, arr, &a, &c, &p);
    int ok = (a == 10 && c == 2 && p == 1);
    printf("%s: UVa 10057 - A mid-summer nights dream\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
