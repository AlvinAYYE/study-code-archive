/*
 * ==========================================================================
 * UVa 11121 - Base -2
 * Title-CN: 負二進位轉換
 * Difficulty: Easy
 * Tags: Math, Number Base Conversion
 * URL: https://onlinejudge.org/external/111/11121.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert a given integer into its base -2 (negative base) representation.
 *
 * [中文] 題目說明:
 *     將給定的十進位整數轉換為負二進位（base -2）表示法。
 *
 * [EN] Approach:
 *     Divide by -2 repeatedly with non-negative remainder: if rem < 0, rem += 2 and quotient += 1.
 * [中文] 思路:
 *     對 -2 取餘數並向下整除：若餘數為負則餘數加 2 且商數加 1，倒序輸出餘數序列。
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

void to_base_neg2(int n, char *out) {
    if (n == 0) { strcpy(out, "0"); return; }
    char buf[50];
    int len = 0;
    while (n != 0) {
        int rem = n % (-2);
        n /= -2;
        if (rem < 0) { rem += 2; n += 1; }
        buf[len++] = rem + '0';
    }
    for (int i = 0; i < len; i++) out[i] = buf[len - 1 - i];
    out[len] = '\0';
}

int main(void) {

    char s[50];
    to_base_neg2(1, s);
    int ok = (strcmp(s, "1") == 0);
    to_base_neg2(-2, s);
    ok = ok && (strcmp(s, "10") == 0);
    printf("%s: UVa 11121 - Base -2\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
