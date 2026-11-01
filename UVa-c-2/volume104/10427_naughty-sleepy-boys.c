/*
 * ==========================================================================
 * UVa 10427 - Naughty Sleepy Boys
 * Title-CN: 調皮的瞌睡男孩 (連續數字串第N位)
 * Difficulty: Easy
 * Tags: Math, Binary Search
 * URL: https://onlinejudge.org/external/104/10427.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the N-th digit in the concatenated integer string '1234567891011121314...'.
 *
 * [中文] 題目說明:
 *     求正整數連續自然拼接字串 123456789101112... 中的第 N 位數位。
 *
 * [EN] Approach:
 *     Identify digit length: 1..9 (9*1), 10..99 (90*2), 100..999 (900*3). Locate target number and exact digit within it.
 * [中文] 思路:
 *     按位數分段（1位數有9個，2位數有90個，3位數有900個），定位第 N 位所在的具體整數及該數的具體數位。
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

int nth_digit_concatenated(int n) {
    long long len = 1, count = 9, start = 1;
    while (n > len * count) {
        n -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }
    start += (n - 1) / len;
    char s[20];
    sprintf(s, "%lld", start);
    return s[(n - 1) % len] - '0';
}

int main(void) {

    int ok = (nth_digit_concatenated(1) == 1) && (nth_digit_concatenated(10) == 1) && (nth_digit_concatenated(11) == 0);
    printf("%s: UVa 10427 - Naughty Sleepy Boys\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
