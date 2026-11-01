/*
 * ==========================================================================
 * UVa 11879 - Multiple of 17
 * Title-CN: 十七的倍數大數整除性判定
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/118/11879.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Check if a very large integer (up to 100 digits) is divisible by 17.
 *
 * [中文] 題目說明:
 *     判定給定超長十進位大整數 (長達 100 位) 是否為 17 的倍數。
 *
 * [EN] Approach:
 *     Modulo arithmetic on string digits: cur = (cur * 10 + digit) % 17. At end, check if cur == 0.
 * [中文] 思路:
 *     逐位掃描大數數字字串，透過霍納法則 (Horner's rule) 維護累計餘數 cur = (cur * 10 + d) % 17，最後檢驗餘數是否為 0。
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

int solve_uva11879(const char *num_str) {
    int rem = 0;
    for (int i = 0; num_str[i]; i++) {
        rem = (rem * 10 + (num_str[i] - '0')) % 17;
    }
    return (rem == 0);
}

int main(void) {

    int ok = solve_uva11879("34") && !solve_uva11879("35");
    printf("%s: UVa 11879 - Multiple of 17\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
