/*
 * ==========================================================================
 * UVa 11933 - Splitting Numbers
 * Title-CN: 二進位有效位元交錯拆分
 * Difficulty: UVa Star 1
 * Tags: bit-manipulation
 * URL: https://onlinejudge.org/external/119/11933.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given integer N, split its set bits (1s) into integers a and b by alternating bits: 1st bit to a, 2nd to b, 3rd to a, etc.
 *
 * [中文] 題目說明:
 *     給定整數 N，將其二進位中所有為 1 的位元交替分配給 a 與 b：第奇數個 1 歸入 a，第偶數個 1 歸入 b。
 *
 * [EN] Approach:
 *     Iterate bit positions 0 to 30. Track count of set bits; if bit is set and count is odd, add to a, else add to b.
 * [中文] 思路:
 *     走訪 0 到 30 位元，若該位元為 1 且為第奇數次遇到則 OR 入 a，若為偶數次遇到則 OR 入 b。
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

void solve_uva11933(int n, int *a, int *b) {
    *a = 0; *b = 0;
    int bit_idx = 0;
    for (int i = 0; i < 31; i++) {
        if (n & (1 << i)) {
            bit_idx++;
            if (bit_idx % 2 == 1) *a |= (1 << i);
            else *b |= (1 << i);
        }
    }
}

int main(void) {

    int a, b;
    solve_uva11933(13, &a, &b); // 13 = 1101_2 -> bits 0, 2, 3 -> a has 0,3 (9), b has 2 (4)
    int ok = (a == 9 && b == 4);
    printf("%s: UVa 11933 - Splitting Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
