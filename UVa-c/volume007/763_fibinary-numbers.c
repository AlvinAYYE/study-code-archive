/*
 * ==========================================================================
 * UVa 763 - Fibinary Numbers
 * Title-CN: 斐波那契進位制 (齊肯多夫加法運算)
 * Difficulty: Medium
 * Tags: Math, Zeckendorf Theorem, Big Integer
 * URL: https://onlinejudge.org/external/7/763.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Add two Zeckendorf binary numbers (fibinary numbers where no two consecutive 1s occur) and output the sum in standard fibinary form.
 *
 * [中文] 題目說明:
 *     計算兩個齊肯多夫進位制數（以費氏數為基底且無相鄰的 1）之和，並規範化為標準齊肯多夫表示法。
 *
 * [EN] Approach:
 *     Convert to big integer and greedily extract Zeckendorf representation from largest Fibonacci number downwards, or use carry rules F(n-1)+F(n)=F(n+1).
 * [中文] 思路:
 *     將兩數轉為數值相加，再自最大的費氏數向下貪心減去以求得標準齊肯多夫（無連續 1）表示法。
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

long long fibinary_to_int(const char *s) {
    long long f[50];
    f[0] = 1; f[1] = 2;
    for (int i = 2; i < 40; i++) f[i] = f[i-1] + f[i-2];
    int len = strlen(s);
    long long val = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') val += f[len - 1 - i];
    }
    return val;
}
void int_to_fibinary(long long val, char *out) {
    if (val == 0) { strcpy(out, "0"); return; }
    long long f[50];
    f[0] = 1; f[1] = 2;
    int k = 1;
    while (f[k] <= val) { k++; f[k] = f[k-1] + f[k-2]; }
    k--;
    int o_idx = 0;
    for (int i = k; i >= 0; i--) {
        if (val >= f[i]) {
            out[o_idx++] = '1';
            val -= f[i];
        } else {
            out[o_idx++] = '0';
        }
    }
    out[o_idx] = '\0';
}

int main(void) {

    long long v1 = fibinary_to_int("100"); // f[2] = 3
    long long v2 = fibinary_to_int("1");   // f[0] = 1
    char out[20];
    int_to_fibinary(v1 + v2, out); // 4 = 3 + 1 -> "101"
    int ok = (strcmp(out, "101") == 0);
    printf("%s: UVa 763 - Fibinary Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
