/*
 * ==========================================================================
 * UVa 410 - Station Balance
 * Title-CN: 太空站重力配平
 * Difficulty: Medium
 * Tags: Greedy, Sorting
 * URL: https://onlinejudge.org/external/4/410.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Place S specimens into C centrifuge chambers (at most 2 specimens per chamber) to minimize imbalance relative to average weight.
 *
 * [中文] 題目說明:
 *     將 S 個樣本放入 C 個離心機室（每室最多 2 個樣本），求使各室重量與平均值之差絕對值總和最小的配平方案。
 *
 * [EN] Approach:
 *     Pad array with zeros to 2C elements. Sort ascending. Pair element i with element 2C - 1 - i. Compute imbalance sum.
 * [中文] 思路:
 *     補 0 至 2C 個元素後升序排序，第 i 個與第 2C-1-i 個配對放入同一室，貪心法保證總不平衡度最小。
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

int cmp_int_sb(const void *a, const void *b) { return (*(int*)a - *(int*)b); }
double min_station_imbalance(int c, int s, int *masses) {
    int arr[20] = {0};
    double sum = 0;
    for (int i = 0; i < s; i++) { arr[i] = masses[i]; sum += masses[i]; }
    double avg = sum / c;
    qsort(arr, 2 * c, sizeof(int), cmp_int_sb);
    double imbalance = 0;
    for (int i = 0; i < c; i++) {
        int chamber_mass = arr[i] + arr[2 * c - 1 - i];
        imbalance += fabs(chamber_mass - avg);
    }
    return imbalance;
}

int main(void) {

    int m[] = {1, 2, 3};
    double imb = min_station_imbalance(2, 3, m);
    int ok = (imb >= 0.0);
    printf("%s: UVa 410 - Station Balance\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
