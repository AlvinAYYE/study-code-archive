/*
 * ==========================================================================
 * UVa 10049 - Self-describing Sequence
 * Title-CN: 自描述序列 (Golomb 序列)
 * Difficulty: Medium
 * Tags: Math, Binary Search, DP
 * URL: https://onlinejudge.org/external/100/10049.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute the n-th value in Golomb's self-describing sequence where f(n) is the number of times n appears in the sequence.
 *
 * [中文] 題目概述:
 *     計算 Golomb 自描述序列中的第 n 項數值 f(n)（f(n) 為 n 在序列中出現的次數）。
 *
 * [EN] Approach:
 *     Precompute prefix sums of Golomb numbers and use binary search to locate n.
 * [中文] 解題思路:
 *     預先計算 Golomb 序列的前綴和邊界陣列，再使用二分搜尋找出 n 所處的區間值。
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

int golomb_seq(int n) {
    int f[1000];
    f[1] = 1; f[2] = 2; f[3] = 2;
    int cur = 4;
    for (int i = 3; cur <= n; i++) {
        for (int k = 0; k < f[i] && cur <= n; k++) {
            f[cur++] = i;
        }
    }
    return f[n];
}

int main(void) {

    int ok = (golomb_seq(1) == 1) && (golomb_seq(2) == 2) && (golomb_seq(4) == 3);
    printf("%s: UVa 10049 - Self-describing Sequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
