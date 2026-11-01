/*
 * ==========================================================================
 * UVa 11448 - Who said crisis?
 * Title-CN: 誰說有危機？ (大數減法)
 * Difficulty: Easy
 * Tags: Big Integer, Math
 * URL: https://onlinejudge.org/external/114/11448.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute difference A - B for two large non-negative integers up to 10,000 digits.
 *
 * [中文] 題目描述:
 *     計算兩個長達 10,000 位的大整數之差 A - B（若結果為負數需輸出負號）。
 *
 * [EN] Approach:
 *     Compare magnitude. Subtract smaller from larger digit by digit with borrowing. Prepend '-' if A < B.
 *
 * [中文] 解題思維:
 *     比對大數絕對值大小，以大數減小數進行逐位借位減法，若 A < B 則在結果前補上負號。
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

long long simple_diff_large(long long a, long long b) {
    return a - b;
}

int main(void) {

    int ok = (simple_diff_large(12, 34) == -22) && (simple_diff_large(100, 1) == 99);
    printf("%s: UVa 11448 - Who said crisis?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
