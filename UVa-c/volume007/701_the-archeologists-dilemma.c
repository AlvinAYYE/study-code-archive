/*
 * ==========================================================================
 * UVa 701 - The Archeologists' Dilemma
 * Title-CN: 考古學家的難題
 * Difficulty: Medium
 * Tags: Math, Logarithms
 * URL: https://onlinejudge.org/external/7/701.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the smallest power of 2 whose decimal representation starts with N, and has more than double the number of digits of N.
 *
 * [中文] 題目概述:
 *     求最小的 2 的冪次方，其十進位表示以 N 開頭，且總位數嚴格大於 N 的位數的兩倍。
 *
 * [EN] Approach:
 *     Let k be total digits (k >= 2*len(N)+1). Check if range [log2(N) + k*log2(10), log2(N+1) + k*log2(10)] contains an integer E.
 * [中文] 解題思路:
 *     設總位數為 k（k >= 2*len(N)+1），利用對數區間 [log2(N) + k*log2(10), log2(N+1) + k*log2(10)] 判斷是否有整數指數 E。
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

long long find_archeologist_power(long long n) {
    int digits = 0;
    for (long long t = n; t > 0; t /= 10) digits++;
    double log2_10 = log2(10.0);
    double log2_n = log2((double)n);
    double log2_n1 = log2((double)(n + 1));
    for (int k = digits + 1; ; k++) {
        long long low = (long long)ceil(log2_n + k * log2_10);
        long long high = (long long)floor(log2_n1 + k * log2_10);
        if (low <= high && k >= digits * 2 + 1) return low;
        if (k > 100000) break;
    }
    return -1;
}

int main(void) {

    long long p = find_archeologist_power(1);
    int ok = (p == 10);
    printf("%s: UVa 701 - The Archeologists' Dilemma\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
