/*
 * ==========================================================================
 * UVa 1260 - Sales
 * Title-CN: 每日銷售額歷史小於等於計數總和
 * Difficulty: UVa Star 1
 * Tags: basics, simulation
 * URL: https://onlinejudge.org/external/12/1260.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given daily sales array A of n days, for each day i from 2 to n, count how many earlier days j < i had sales A[j] <= A[i]. Sum all counts.
 *
 * [中文] 題目說明:
 *     給定 n 天的每日銷售額陣列 A，對於第 2 到 n 天中的每一天 i，統計先前有多少天 j < i 的銷售額 A[j] <= A[i]，求所有計數的總和。
 *
 * [EN] Approach:
 *     Double loop: for i from 1 to n-1, count elements in A[0..i-1] that are <= A[i]. Sum and return total.
 * [中文] 思路:
 *     雙重迴圈走訪：外層走訪第 i 天，內層統計前 i-1 天中小於等於當日銷售額的天數並予以累加。
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

int solve_uva1260(int n, int *a) {
    int total_sum = 0;
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i]) cnt++;
        }
        total_sum += cnt;
    }
    return total_sum;
}

int main(void) {

    int a[] = {38, 111, 102, 111, 177};
    int sum = solve_uva1260(5, a);
    int ok = (sum == 9); // 0 + 1 + 1 + 3 + 4 = 9
    printf("%s: UVa 1260 - Sales\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
