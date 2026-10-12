/*
 * ==========================================================================
 * UVa 10327 - Flip Sort
 * Title-CN: 翻轉排序
 * Difficulty: UVa Star 1
 * Tags: sorting, inversion-number
 * ==========================================================================
 * [EN] Problem: Minimum adjacent swaps to sort array.
 * [中文] 題目說明: 計算相鄰兩元素交換排序的最小次數（逆序數對）。
 * [EN] Approach: Count pairs (i < j) where arr[i] > arr[j] in O(N^2).
 * [中文] 思路: 雙重迴圈統計所有逆序數對數量。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10327(int n, const int *arr) {
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) swaps++;
        }
    }
    return swaps;
}

int main(void) {
    int arr[] = {3, 2, 1};
    int ok = (solve_uva10327(3, arr) == 3);
    printf("%s: UVa 10327 - Flip Sort\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
