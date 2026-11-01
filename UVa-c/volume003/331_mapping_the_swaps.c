/*
 * ==========================================================================
 * UVa 331 - Mapping the Swaps
 * Title-CN: 氣泡排序最小相鄰交換序列數
 * Difficulty: Medium
 * Tags: Backtracking, Bubble Sort, Permutation
 * URL: https://onlinejudge.org/external/3/331.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of distinct minimal sequences of adjacent swaps that sort a given array.
 *
 * [中文] 題目描述:
 *     計算將給定數列透過最小次數的相鄰元素交換（如同氣泡排序）排成升序的不同交換序列總數。若原數列已有序則為 0。
 *
 * [EN] Approach:
 *     Use backtracking to find all sequences of adjacent inversions. If array already sorted, output 0. Otherwise, branch on any adjacent inverted pair.
 *
 * [中文] 解題思維:
 *     回溯搜尋相鄰逆序對進行交換。若初始即有序輸出 0；否則每次枚舉相鄰逆序位置 a[i] > a[i+1] 交換並遞歸。
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

static int swap_maps_count;

static int is_sorted_arr(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) return 0;
    }
    return 1;
}

static void dfs_swaps(int *a, int n) {
    if (is_sorted_arr(a, n)) {
        swap_maps_count++;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            int tmp = a[i]; a[i] = a[i + 1]; a[i + 1] = tmp;
            dfs_swaps(a, n);
            tmp = a[i]; a[i] = a[i + 1]; a[i + 1] = tmp;
        }
    }
}

int count_swap_maps(int *a, int n) {
    if (is_sorted_arr(a, n)) return 0;
    swap_maps_count = 0;
    dfs_swaps(a, n);
    return swap_maps_count;
}

int main(void) {

    int a1[] = {2, 1};
    int a2[] = {3, 2, 1};
    int a3[] = {1, 2, 3};
    int ok = (count_swap_maps(a1, 2) == 1) &&
             (count_swap_maps(a2, 3) == 2) &&
             (count_swap_maps(a3, 3) == 0);
    printf("%s: UVa 331 - Mapping the Swaps\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
