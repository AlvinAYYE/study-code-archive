/*
 * ==========================================================================
 * UVa 11900 - Boiled Eggs
 * Title-CN: 水煮蛋鍋具容量與重量貪婪計數
 * Difficulty: UVa Star 1
 * Tags: greedy
 * URL: https://onlinejudge.org/external/119/11900.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given sorted weights of N eggs, find the maximum number of eggs (up to P eggs and up to Q grams total) that can be boiled in the bowl.
 *
 * [中文] 題目說明:
 *     給定 N 顆已按重量排序的水煮蛋，鍋子最多容納 P 顆蛋且總重不超過 Q 克，求最多可同時煮幾顆蛋。
 *
 * [EN] Approach:
 *     Greedy choice: pick lightest eggs in order while count < P and total_weight + weight[i] <= Q.
 * [中文] 思路:
 *     貪婪策略：由最輕的蛋依序選取，在顆數不超過 P 且累計重量不超過 Q 的條件下盡可能多取。
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

int solve_uva11900(int n, int p, int q, int *weights) {
    int count = 0, current_weight = 0;
    for (int i = 0; i < n; i++) {
        if (count < p && current_weight + weights[i] <= q) {
            count++;
            current_weight += weights[i];
        } else {
            break;
        }
    }
    return count;
}

int main(void) {

    int w[] = {1, 2, 3};
    int ans = solve_uva11900(3, 2, 5, w); // 1 + 2 = 3 <= 5, count 2 <= 2
    int ok = (ans == 2);
    printf("%s: UVa 11900 - Boiled Eggs\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
