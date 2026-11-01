/*
 * ==========================================================================
 * UVa 10465 - Homer Simpson
 * Title-CN: 辛普森吃漢堡完全背包最優化
 * Difficulty: UVa Star 1
 * Tags: dynamic-programming, greedy
 * URL: https://onlinejudge.org/external/104/10465.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Two types of burgers take m and n minutes to eat. Homer has t minutes. Maximize burgers eaten; minimize wasted beer time.
 *
 * [中文] 題目說明:
 *     兩種漢堡吃一個分別耗時 m 與 n 分鐘，在總時間 t 分鐘內盡可能多吃漢堡，使剩餘喝啤酒的時間最小化。
 *
 * [EN] Approach:
 *     Enumerate number of m-burgers: find non-negative integers i, j such that i*m + j*n <= t minimizing remainder t - (i*m + j*n), maximizing i + j.
 * [中文] 思路:
 *     枚舉吃 m 漢堡的個數 i，計算最多可吃 n 漢堡個數 j，先使剩餘時間最小，剩餘時間相同時使漢堡總個數最大。
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

void solve_uva10465(int m, int n, int t, int *burgers, int *beer_time) {
    int min_rem = 1e9, max_b = 0;
    for (int i = 0; i * m <= t; i++) {
        int rem = (t - i * m) % n;
        int j = (t - i * m) / n;
        if (rem < min_rem || (rem == min_rem && (i + j) > max_b)) {
            min_rem = rem;
            max_b = i + j;
        }
    }
    *burgers = max_b;
    *beer_time = min_rem;
}

int main(void) {

    int b, bt;
    solve_uva10465(4, 9, 22, &b, &bt); // 4*1 + 9*2 = 22 -> 3 burgers, 0 beer
    int ok = (b == 3 && bt == 0);
    printf("%s: UVa 10465 - Homer Simpson\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
