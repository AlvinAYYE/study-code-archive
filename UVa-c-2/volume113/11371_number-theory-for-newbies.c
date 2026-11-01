/*
 * ==========================================================================
 * UVa 11371 - Number Theory for Newbies
 * Title-CN: 新手數論 (最大排列與最小排列之差)
 * Difficulty: Easy
 * Tags: Math, Sorting, String
 * URL: https://onlinejudge.org/external/113/11371.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given an integer n, form the largest number by permuting its digits, and the smallest number (no leading zero). Subtract them and check divisibility by 9.
 *
 * [中文] 題目說明:
 *     將整數 n 的數位重新排列組成最大整數與最小整數（不可有前導 0），求兩者之差及其除以 9 的商數。
 *
 * [EN] Approach:
 *     Sort digits descending for max, ascending for min (swap first non-zero to front if leading zero). Result is always divisible by 9.
 * [中文] 思路:
 *     數位降序排序得最大數；數位升序（若有前導 0 則與首個非 0 交換）得最小數，相減並除以 9。
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

long long newbie_diff(long long n) {
    char s[20];
    sprintf(s, "%lld", n);
    int len = strlen(s);
    // Sort descending
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (s[i] < s[j]) { char t = s[i]; s[i] = s[j]; s[j] = t; }
    long long max_val = atoll(s);
    // Sort ascending for min
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (s[i] > s[j]) { char t = s[i]; s[i] = s[j]; s[j] = t; }
    if (s[0] == '0') {
        for (int i = 1; i < len; i++) {
            if (s[i] != '0') { s[0] = s[i]; s[i] = '0'; break; }
        }
    }
    long long min_val = atoll(s);
    return max_val - min_val;
}

int main(void) {

    long long diff = newbie_diff(314); // 431 - 134 = 297
    int ok = (diff == 297);
    printf("%s: UVa 11371 - Number Theory for Newbies\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
