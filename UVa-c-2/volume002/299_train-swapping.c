/*
 * ==========================================================================
 * UVa 299 - Train Swapping
 * Title-CN: 火車車廂調度
 * Difficulty: UVa Star 1
 * Tags: sorting, inversion-number
 * ==========================================================================
 * [EN] Problem: Count minimum adjacent swaps to sort train carriages.
 * [中文] 題目說明: 計算將火車車廂排序所需的最小相鄰交換次數。
 * [EN] Approach: Inversion count via O(L^2) bubble sort.
 * [中文] 思路: 統計逆序對數量（氣泡排序交換次數）。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva299(int l, const int *train) {
    int swaps = 0;
    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l; j++) {
            if (train[i] > train[j]) swaps++;
        }
    }
    return swaps;
}

int main(void) {
    int t[3] = {1, 3, 2};
    int ok = (solve_uva299(3, t) == 1);
    printf("%s: UVa 299 - Train Swapping\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
