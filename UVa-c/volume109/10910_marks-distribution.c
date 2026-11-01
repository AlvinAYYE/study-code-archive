/*
 * ==========================================================================
 * UVa 10910 - Marks Distribution
 * Title-CN: 分數分配 (隔板法與組合數)
 * Difficulty: Easy
 * Tags: Math, Combinatorics, DP
 * URL: https://onlinejudge.org/external/109/10910.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of ways to distribute total marks T among N subjects such that each subject gets at least P marks.
 *
 * [中文] 題目說明:
 *     求將總分 T 分配給 N 門科目且每門科目至少獲得 P 分的方案數。
 *
 * [EN] Approach:
 *     Subtract base marks: remaining T' = T - N * P. The number of ways to distribute T' among N subjects is C(T' + N - 1, N - 1).
 * [中文] 思路:
 *     先給每門課分 P 分，剩餘 T' = T - N * P 分，轉為經典隔板法非負整數解個數：C(T' + N - 1, N - 1)。
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

long long marks_dist(int n, int t, int p) {
    int rem = t - n * p;
    if (rem < 0) return 0;
    // C(rem + n - 1, n - 1)
    long long ans = 1;
    for (int i = 1; i <= n - 1; i++) {
        ans = ans * (rem + i) / i;
    }
    return ans;
}

int main(void) {

    int ok = (marks_dist(3, 10, 2) == 15); // rem = 10 - 6 = 4. C(4 + 2, 2) = 15
    printf("%s: UVa 10910 - Marks Distribution\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
