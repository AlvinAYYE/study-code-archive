/*
 * ==========================================================================
 * UVa 11242 - Tour de France
 * Title-CN: 環法自行車賽
 * Difficulty: Easy
 * Tags: Sorting, Simulation
 * URL: https://onlinejudge.org/external/112/11242.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given teeth count on front and rear sprockets of a bicycle, find the maximum ratio between adjacent drive ratios when sorted.
 *
 * [中文] 題目概述:
 *     給定自行車前齒輪與後齒輪的齒數，求所有齒輪比排序後，相鄰齒輪比之間的最大比值。
 *
 * [EN] Approach:
 *     Generate all drive ratios r = rear / front. Sort them, and find max(r[i+1] / r[i]).
 * [中文] 解題思路:
 *     枚舉所有齒比 r = 後齒數 / 前齒數，排序後取相鄰兩齒比商的最大值。
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

int cmp_double(const void *a, const void *b) {
    double da = *(double*)a, db = *(double*)b;
    return (da > db) - (da < db);
}

double max_spread(int f, const int *front, int r, const int *rear) {
    double ratios[100];
    int k = 0;
    for (int i = 0; i < f; i++)
        for (int j = 0; j < r; j++)
            ratios[k++] = (double)rear[j] / front[i];
    qsort(ratios, k, sizeof(double), cmp_double);
    double max_sp = 0;
    for (int i = 0; i < k - 1; i++) {
        double sp = ratios[i + 1] / ratios[i];
        if (sp > max_sp) max_sp = sp;
    }
    return max_sp;
}

int main(void) {

    int front[] = {24, 40}, rear[] = {12, 13, 14};
    double sp = max_spread(2, front, 3, rear);
    int ok = (fabs(sp - 1.428) < 0.05);
    printf("%s: UVa 11242 - Tour de France\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
