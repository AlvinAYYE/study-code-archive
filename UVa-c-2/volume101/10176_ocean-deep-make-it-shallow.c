/*
 * ==========================================================================
 * UVa 10176 - Ocean Deep! - Make it shallow!!
 * Title-CN: 大洋深處！讓它變淺！
 * Difficulty: Medium
 * Tags: Math, Modulo Arithmetic
 * URL: https://onlinejudge.org/external/101/10176.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a large binary number terminated by '#', determine if it is divisible by the prime 131071.
 *
 * [中文] 題目概述:
 *     給定一個以 '#' 結尾的長二進位數，判斷其是否能被質數 131071 整除。
 *
 * [EN] Approach:
 *     Process the binary digits one by one using Horner's rule: rem = (rem * 2 + digit) % 131071. Check if rem == 0.
 * [中文] 解題思路:
 *     使用秦九韶算法 (Horner's rule) 逐位累計餘數：rem = (rem * 2 + digit) % 131071，最後檢查 rem 是否為 0。
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

bool is_divisible_131071(const char *binary_str) {
    long long rem = 0;
    const long long MOD = 131071;
    for (int i = 0; binary_str[i] && binary_str[i] != '#'; i++) {
        if (binary_str[i] == '0' || binary_str[i] == '1') {
            rem = (rem * 2 + (binary_str[i] - '0')) % MOD;
        }
    }
    return rem == 0;
}

int main(void) {

    int ok = is_divisible_131071("0#") && !is_divisible_131071("10111#");
    printf("%s: UVa 10176 - Ocean Deep! - Make it shallow!!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
