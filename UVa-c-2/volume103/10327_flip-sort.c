/*
 * ==========================================================================
 * UVa 10327 - Flip Sort
 * Title-CN: 相鄰交換排序最少步數 (逆序對計數)
 * Difficulty: UVa Star 1
 * Tags: sorting, inversion-number
 * URL: https://onlinejudge.org/external/103/10327.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum number of adjacent swaps required to sort an array.
 *
 * [中文] 題目說明:
 *     求透過相鄰兩元素交換 (Bubble Sort 操作) 將陣列排成升序所需的最少交換次數 (即求陣列逆序數)。
 *
 * [EN] Approach:
 *     O(N^2) pairwise inversion count: count pairs (i, j) with i < j and a[i] > a[j].
 * [中文] 思路:
 *     相鄰交換最少次數定理：最少操作步數嚴格等於陣列中的逆序對數量，雙層迴圈 O(N^2) 統計即可。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10327(int n, const int *a) {
    int inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) inv++;
        }
    }
    return inv;
}

int main(void) {

    int a[3] = {1, 2, 3};
    int b[3] = {2, 3, 1};
    int ok = (solve_uva10327(3, a) == 0) && (solve_uva10327(3, b) == 2);
    printf("%s: UVa 10327 - Flip Sort\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
