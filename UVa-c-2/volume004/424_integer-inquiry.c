/*
 * ==========================================================================
 * UVa 424 - Integer Inquiry
 * Title-CN: 超長大數整數連加
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * URL: https://onlinejudge.org/external/4/424.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sum a sequence of positive integers up to 100 digits each, terminated by '0'.
 *
 * [中文] 題目說明:
 *     計算一系列長達 100 位數的正整數總和，直到輸入為 '0' 結束 (大數高精度加法)。
 *
 * [EN] Approach:
 *     Simulate column-addition from least significant digit with carry propagation.
 * [中文] 思路:
 *     以整數陣列儲存大數的每一位，由低位到高位逐位相加並處理進位運算。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void add_bigint_424(int *sum, const char *s) {
    int len = (int)strlen(s);
    int carry = 0;
    for (int i = 0; i < len || carry; i++) {
        int d = (i < len) ? (s[len - 1 - i] - '0') : 0;
        int tot = sum[i] + d + carry;
        sum[i] = tot % 10;
        carry = tot / 10;
    }
}

int main(void) {

    int sum[150] = {0};
    add_bigint_424(sum, "12345");
    add_bigint_424(sum, "54321");
    int ok = (sum[0] == 6 && sum[1] == 6 && sum[4] == 6);
    printf("%s: UVa 424 - Integer Inquiry\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
