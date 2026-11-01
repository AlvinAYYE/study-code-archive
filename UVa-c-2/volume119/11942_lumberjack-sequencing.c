/*
 * ==========================================================================
 * UVa 11942 - Lumberjack Sequencing
 * Title-CN: 伐木工人鬍鬚長度單調性排序判定
 * Difficulty: UVa Star 1
 * Tags: simulation, array
 * URL: https://onlinejudge.org/external/119/11942.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if sequence of 10 integers is strictly ordered (either monotonically increasing or decreasing).
 *
 * [中文] 題目說明:
 *     檢查 10 名伐木工人的鬍鬚長度數列是否呈現單調排序 (遞增排序或遞減排序)。
 *
 * [EN] Approach:
 *     Check all adjacent pairs for non-decreasing (a[i] <= a[i+1]) or non-increasing (a[i] >= a[i+1]).
 * [中文] 思路:
 *     線性遍歷比對相鄰元素，若全滿足 a[i] <= a[i+1] 或全滿足 a[i] >= a[i+1] 則為 Ordered，否則為 Unordered。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11942(const int *a) {
    int inc = 1, dec = 1;
    for (int i = 0; i < 9; i++) {
        if (a[i] > a[i + 1]) inc = 0;
        if (a[i] < a[i + 1]) dec = 0;
    }
    return inc || dec;
}

int main(void) {

    int a1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[10] = {1, 3, 2, 4, 5, 6, 7, 8, 9, 10};
    int ok = solve_uva11942(a1) && !solve_uva11942(a2);
    printf("%s: UVa 11942 - Lumberjack Sequencing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
