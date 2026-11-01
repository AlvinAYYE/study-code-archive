/*
 * ==========================================================================
 * UVa 11456 - Trainsorting
 * Title-CN: 火車車廂雙向掛載最長有序序列
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, lis
 * URL: https://onlinejudge.org/external/114/11456.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Train cars arrive sequentially. Each car can be attached to front or back of train. Cars must remain strictly decreasing from front to back. Maximize cars.
 *
 * [中文] 題目概述:
 *     車廂依序到達，每節車廂可掛在列車頭部或尾部，整列火車重量必須由頭至尾嚴格遞減。求最多可掛載的車廂節數。
 *
 * [EN] Approach:
 *     Compute LIS and LDS starting from each index i to the right. Max length is max_i(lis[i] + lds[i] - 1).
 * [中文] 解題思路:
 *     從後往前計算各位置向右的 LIS 與 LDS：車廂 i 作為列車首發車廂時，可形成之最大車長為 lis[i] + lds[i] - 1。
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

int solve_uva11456(int n, int *w) {
    if (n == 0) return 0;
    int lis[50], lds[50];
    for (int i = n - 1; i >= 0; i--) {
        lis[i] = 1; lds[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (w[j] > w[i] && lis[j] + 1 > lis[i]) lis[i] = lis[j] + 1;
            if (w[j] < w[i] && lds[j] + 1 > lds[i]) lds[i] = lds[j] + 1;
        }
    }
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        if (lis[i] + lds[i] - 1 > max_len) max_len = lis[i] + lds[i] - 1;
    }
    return max_len;
}

int main(void) {

    int w[] = {1, 2, 3};
    int ans = solve_uva11456(3, w);
    int ok = (ans == 3);
    printf("%s: UVa 11456 - Trainsorting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
