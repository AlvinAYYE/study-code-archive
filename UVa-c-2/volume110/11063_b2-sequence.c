/*
 * ==========================================================================
 * UVa 11063 - B2-Sequence
 * Title-CN: B2 數列檢驗
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, array
 * URL: https://onlinejudge.org/external/110/11063.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A B2-sequence satisfies 1 <= b_1 < b_2 < ... < b_N, and all pairwise sums
 *     b_i + b_j (i <= j) are distinct. Check if sequence is B2.
 *
 * [中文] 題目說明:
 *     嚴格遞增正整數數列 1 <= b_1 < b_2 < ... < b_N，若所有任意兩數之和
 *     b_i + b_j (i <= j) 均不重複，則為 B2-Sequence。判斷給定數列是否為 B2-Sequence。
 *
 * [EN] Approach:
 *     Check 1 <= b_1 and strictly increasing. Use frequency/seen array for sums b_i + b_j.
 * [中文] 思路:
 *     檢查第一項 >= 1 且嚴格遞增；使用 seen 陣列檢查每對和 b_i + b_j 是否重複。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva11063(int n, const int *b) {
    if (b[0] < 1) return 0;
    for (int i = 0; i < n - 1; i++) {
        if (b[i] >= b[i + 1]) return 0;
    }
    int seen[20005] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = b[i] + b[j];
            if (seen[sum]) return 0;
            seen[sum] = 1;
        }
    }
    return 1;
}

int main(void) {
    int b_valid[] = {1, 3, 7, 12};
    int b_invalid[] = {1, 2, 3};
    int ok = solve_uva11063(4, b_valid) && !solve_uva11063(3, b_invalid);
    printf("%s: UVa 11063 - B2-Sequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
