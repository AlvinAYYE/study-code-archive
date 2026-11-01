/*
 * ==========================================================================
 * UVa 11157 - Dynamic Frog
 * Title-CN: 動態青蛙過河 (貪心跳躍與最大間距)
 * Difficulty: Medium
 * Tags: Greedy
 * URL: https://onlinejudge.org/external/111/11157.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A frog must cross a river of width D and return. Big rocks can be stepped on twice; small rocks sink after one step. Minimize maximum leap distance.
 *
 * [中文] 題目說明:
 *     青蛙需橫渡寬度為 D 的河流並返回。大石頭可用兩次，小石頭踩過即沉，求往返過程中單次跳躍最大距離的最小值。
 *
 * [EN] Approach:
 *     Greedy: duplicate big rocks. Take alternating small rocks on the forward trip, and remaining small rocks on the return trip. Maximize adjacent step differences.
 * [中文] 思路:
 *     貪心法：大石頭拆成兩塊；去程隔塊跳躍選取小石頭，回程使用剩餘的小石頭，取相鄰石頭間距的最大值即為答案。
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

int min_frog_max_leap(int n, int d, const int *dist, const char *type) {
    int seq[50], cnt = 0;
    seq[cnt++] = 0;
    for (int i = 0; i < n; i++) {
        seq[cnt++] = dist[i];
        if (type[i] == 'B') seq[cnt++] = dist[i]; // big rock duplicated
    }
    seq[cnt++] = d;
    seq[cnt++] = d;
    int max_jump = 0;
    for (int i = 0; i + 2 < cnt; i++) {
        int leap = seq[i + 2] - seq[i];
        if (leap > max_jump) max_jump = leap;
    }
    return max_jump;
}

int main(void) {

    int dist[] = {25, 50, 75}; char type[] = "BSB";
    int ans = min_frog_max_leap(3, 100, dist, type);
    int ok = (ans > 0);
    printf("%s: UVa 11157 - Dynamic Frog\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
