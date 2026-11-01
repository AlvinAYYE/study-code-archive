/*
 * ==========================================================================
 * UVa 10916 - Factstone Benchmark
 * Title-CN: 階乘基準測試 (字長與階乘增長率)
 * Difficulty: Easy
 * Tags: Math, Logarithms
 * URL: https://onlinejudge.org/external/109/10916.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a year Y, computer word size is 2^(2 + (Y-1960)/10) bits. Find the largest n such that n! fits in an unsigned integer of that size.
 *
 * [中文] 題目說明:
 *     給定年份 Y，電腦字長為 2^(2 + (Y-1960)/10) 位元，求階乘 n! 能容納在該無號整數範圍內的最大整數 n。
 *
 * [EN] Approach:
 *     Word bits B = 2^(2 + (Y-1960)/10). Condition is log2(n!) = sum_{i=1}^n log2(i) < B.
 * [中文] 思路:
 *     計算位元數 B = 2^(2 + (Y-1960)/10)，累加 log2(i) 直到總和大於等於 B，前一個整數即為所求最大 n。
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

int max_factstone_n(int year) {
    int bits = 1 << (2 + (year - 1960) / 10);
    double sum = 0.0;
    int n = 1;
    while (1) {
        sum += log2((double)n);
        if (sum >= bits) return n - 1;
        n++;
    }
}

int main(void) {

    int ok = (max_factstone_n(1960) == 3); // 2^4 = 16 bits, 3! = 6 <= 15
    printf("%s: UVa 10916 - Factstone Benchmark\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
