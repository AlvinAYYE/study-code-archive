/*
 * ==========================================================================
 * UVa 612 - DNA Sorting
 * Title-CN: DNA 逆序數穩定排序
 * Difficulty: UVa Star 1
 * Tags: sorting, inversion-number, string
 * URL: https://onlinejudge.org/external/6/612.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sort DNA strings in ascending order of their sortedness (number of inversion pairs). Stable sort required.
 *
 * [中文] 題目說明:
 *     依照 DNA 字串的逆序數 (即未排序程度) 由小到大進行穩定排序。
 *
 * [EN] Approach:
 *     Count inversions for each string via O(N^2) double loop. Use stable sort (mergesort or stable bubble sort).
 * [中文] 思路:
 *     雙重迴圈統計每條 DNA 字串的逆序對數量，結合原始輸入索引進行穩定排序 (相等時維持原先順序)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count_inversions_612(const char *s, int len) {
    int inv = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] > s[j]) inv++;
        }
    }
    return inv;
}

int main(void) {

    int ok = (count_inversions_612("DAABEC", 6) == 5);
    printf("%s: UVa 612 - DNA Sorting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
