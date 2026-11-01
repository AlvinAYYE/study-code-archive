/*
 * ==========================================================================
 * UVa 326 - Extrapolation Using a Difference Table
 * Title-CN: 差分表外插預測
 * Difficulty: Easy
 * Tags: Math, Polynomials, Difference Table
 * URL: https://onlinejudge.org/external/3/326.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Use forward differences table to extrapolate a sequence of n values by k steps.
 *
 * [中文] 題目描述:
 *     利用階差分表（差分三角陣列）將給定的 n 項數列向前外推 k 個新數值。
 *
 * [EN] Approach:
 *     Construct table diff[i] = diff[i+1] - diff[i]. For each of the k steps, accumulate differences upwards from the last level.
 *
 * [中文] 解題思維:
 *     構建差分表直到頂層階差，外推時自下而上進行 k 次累加，更新末端元素得到外推值。
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

int extrapolate_difference_table(int *seq, int n, int k) {
    int table[15][15];
    for (int i = 0; i < n; i++) table[0][i] = seq[i];
    for (int lvl = 1; lvl < n; lvl++) {
        for (int i = 0; i < n - lvl; i++) {
            table[lvl][i] = table[lvl - 1][i + 1] - table[lvl - 1][i];
        }
    }
    int last[15];
    for (int lvl = 0; lvl < n; lvl++) {
        last[lvl] = table[lvl][n - lvl - 1];
    }
    for (int step = 0; step < k; step++) {
        for (int lvl = n - 2; lvl >= 0; lvl--) {
            last[lvl] += last[lvl + 1];
        }
    }
    return last[0];
}

int main(void) {

    int seq[] = {1, 4, 9, 16}; // squares: n=4 -> 5th square is 25
    int res = extrapolate_difference_table(seq, 4, 1);
    int ok = (res == 25);
    printf("%s: UVa 326 - Extrapolation Using a Difference Table\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
