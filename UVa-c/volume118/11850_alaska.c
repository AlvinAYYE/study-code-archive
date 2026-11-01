/*
 * ==========================================================================
 * UVa 11850 - Alaska
 * Title-CN: 阿拉斯加公路
 * Difficulty: Easy
 * Tags: Greedy, Sorting
 * URL: https://onlinejudge.org/external/118/11850.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a car with a 200-mile tank can make a round trip of 1422 miles visiting given charging stations along the route.
 *
 * [中文] 題目概述:
 *     判斷滿油能跑 200 英里的車能否利用沿途加油站完成全長 1422 英里的阿拉斯加公路來回旅程。
 *
 * [EN] Approach:
 *     Sort stations. Check distance between consecutive stations <= 200, and last station to end and back <= 200: 2 * (1422 - stations[n-1]) <= 200.
 * [中文] 解題思路:
 *     將加油站座標排序，檢查相鄰加油站距離不超過 200，且最後一個加油站到終點折返距離 2 * (1422 - stations[n-1]) <= 200。
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

int cmp_int_asc(const void *a, const void *b) { return (*(int*)a - *(int*)b); }
bool can_traverse_alaska(int n, int *stations) {
    qsort(stations, n, sizeof(int), cmp_int_asc);
    for (int i = 0; i < n - 1; i++) {
        if (stations[i + 1] - stations[i] > 200) return false;
    }
    if (2 * (1422 - stations[n - 1]) > 200) return false;
    return true;
}

int main(void) {

    int st1[] = {0, 200, 400, 600, 800, 1000, 1200, 1400};
    int ok = can_traverse_alaska(8, st1);
    printf("%s: UVa 11850 - Alaska\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
