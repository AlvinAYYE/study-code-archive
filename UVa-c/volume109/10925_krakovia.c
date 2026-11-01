/*
 * ==========================================================================
 * UVa 10925 - Krakovia
 * Title-CN: 克拉科夫平攤帳單 (大數加法與除法)
 * Difficulty: Easy
 * Tags: Big Integer, Math
 * URL: https://onlinejudge.org/external/109/10925.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sum up the costs of N items (large integers) and divide equally among F friends.
 *
 * [中文] 題目說明:
 *     計算 N 個物品的大整數費用總和，並平均分攤給 F 位朋友。
 *
 * [EN] Approach:
 *     Big integer addition to accumulate total cost, followed by big integer division by single-precision integer F.
 * [中文] 思路:
 *     高精度大數加法累計總開銷，再進行高精度除以低精度整數 F 求得每人應付金額。
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

void divide_bill(long long total, int friends, long long *each) {
    *each = total / friends;
}

int main(void) {

    long long each;
    divide_bill(10000000000LL, 5, &each);
    int ok = (each == 2000000000LL);
    printf("%s: UVa 10925 - Krakovia\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
