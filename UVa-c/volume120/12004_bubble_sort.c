/*
 * ==========================================================================
 * UVa 12004 - Bubble Sort
 * Title-CN: 氣泡排序期望交換次數
 * Difficulty: Easy
 * Tags: Math, Probability, Combinatorics
 * URL: https://onlinejudge.org/external/120/12004.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the expected number of swap operations in bubble sort on a random permutation of length n.
 *
 * [中文] 題目描述:
 *     求長度為 n 的隨機排列在氣泡排序下的期望交換次數（以最簡分數表示）。
 *
 * [EN] Approach:
 *     Expected swaps = n * (n - 1) / 4. Simplify fraction: if divisible by 4 output integer, if divisible by 2 output P/2, else P/4.
 *
 * [中文] 解題思維:
 *     隨機排列逆序對期望值為 n*(n-1)/4。化簡為最簡分數：能被 4 整除則為整數，能被 2 整除則為 P/2，否則為 P/4。
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

void expected_bubble_swaps(long long n, long long *num, long long *den) {
    long long total = n * (n - 1);
    if (total % 4 == 0) {
        *num = total / 4;
        *den = 1;
    } else if (total % 2 == 0) {
        *num = total / 2;
        *den = 2;
    } else {
        *num = total;
        *den = 4;
    }
}

int main(void) {

    long long p, q;
    expected_bubble_swaps(1, &p, &q); // n=1 -> 0
    int ok1 = (p == 0 && q == 1);
    expected_bubble_swaps(2, &p, &q); // n=2 -> 1/2
    int ok2 = (p == 1 && q == 2);
    expected_bubble_swaps(4, &p, &q); // n=4 -> 12/4 = 3
    int ok3 = (p == 3 && q == 1);
    int ok = ok1 && ok2 && ok3;
    printf("%s: UVa 12004 - Bubble Sort\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
