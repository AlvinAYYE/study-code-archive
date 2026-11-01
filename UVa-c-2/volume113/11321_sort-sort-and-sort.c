/*
 * ==========================================================================
 * UVa 11321 - Sort! Sort!! and Sort!!!
 * Title-CN: 奇偶模數複合自訂排序演算法
 * Difficulty: UVa Star 2
 * Tags: sorting
 * URL: https://onlinejudge.org/external/113/11321.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sort integers by modulo M ascending. For ties: odd before even; if both odd, larger first; if both even, smaller first.
 *
 * [中文] 題目說明:
 *     按數字除以 M 的餘數升序排列；若餘數相同：奇數排在偶數前；若同為奇數則較大者在先；若同為偶數則較小者在先。
 *
 * [EN] Approach:
 *     Custom qsort comparator implementing the multi-layer modulus and parity precedence rules.
 * [中文] 思路:
 *     實作自訂排序比較器：先按 % M 比較，同餘數則按奇偶優先級、奇數降序、偶數升序細緻排序。
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

int mod_m_11321;

int cmp11321(const void *pa, const void *pb) {
    int a = *(int*)pa, b = *(int*)pb;
    int ma = a % mod_m_11321, mb = b % mod_m_11321;
    if (ma != mb) return ma - mb;
    int odd_a = (a % 2 != 0), odd_b = (b % 2 != 0);
    if (odd_a && !odd_b) return -1;
    if (!odd_a && odd_b) return 1;
    if (odd_a && odd_b) return b - a; // larger odd first
    return a - b; // smaller even first
}

int main(void) {

    mod_m_11321 = 5;
    int a[] = {2, 3}; // 3 is odd, 2 is even -> 3 should precede 2 (same mod 5 if mod 1? here 3%5=3, 2%5=2)
    int ok = (cmp11321(&a[0], &a[1]) < 0);
    printf("%s: UVa 11321 - Sort! Sort!! and Sort!!!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
