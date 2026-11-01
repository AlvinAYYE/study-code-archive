/*
 * ==========================================================================
 * UVa 10551 - Basic Remains
 * Title-CN: 進位制大數求模
 * Difficulty: Easy
 * Tags: Math, Horner's Rule, Base Conversion
 * URL: https://onlinejudge.org/external/105/10551.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given big integer p and integer m in base b, compute (p mod m) in base b.
 *
 * [中文] 題目說明:
 *     給定以 b 進位表示的大整數 p 與模數 m，求 (p mod m) 的結果並以 b 進位輸出。
 *
 * [EN] Approach:
 *     Convert m to decimal. Evaluate (p mod m_dec) using Horner's rule digit by digit. Convert remainder back to base b.
 * [中文] 思路:
 *     將模數 m 轉為十進位，對大數 p 使用秦九韶演算法逐位求模，最後將餘數轉回 b 進位字串。
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

void base_remains(int b, const char *p_str, const char *m_str, char *out) {
    long long m = 0;
    for (int i = 0; m_str[i]; i++) m = m * b + (m_str[i] - '0');
    long long rem = 0;
    for (int i = 0; p_str[i]; i++) rem = (rem * b + (p_str[i] - '0')) % m;
    if (rem == 0) { strcpy(out, "0"); return; }
    char buf[50];
    int len = 0;
    while (rem > 0) {
        buf[len++] = (rem % b) + '0';
        rem /= b;
    }
    for (int i = 0; i < len; i++) out[i] = buf[len - 1 - i];
    out[len] = '\0';
}

int main(void) {

    char out[50];
    base_remains(2, "1100", "101", out); // 12 % 5 = 2 -> base 2 is "10"
    int ok = (strcmp(out, "10") == 0);
    printf("%s: UVa 10551 - Basic Remains\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
