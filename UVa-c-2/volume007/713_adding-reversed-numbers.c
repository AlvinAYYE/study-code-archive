/*
 * ==========================================================================
 * UVa 713 - Adding Reversed Numbers
 * Title-CN: 反向數字大數相加
 * Difficulty: UVa Star 1
 * Tags: math, big-integer, string
 * URL: https://onlinejudge.org/external/7/713.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Reverse digits of two numbers, sum them up, and output the reversed sum (ignoring leading zeros).
 *
 * [中文] 題目說明:
 *     將兩個大數反向翻轉後相加，再將相加結果翻轉輸出 (忽略結果的前導 0)。
 *
 * [EN] Approach:
 *     Because input is already reversed from least significant digit, standard big-integer addition from index 0 directly computes the reversed sum.
 * [中文] 思路:
 *     由於輸入的數字已是反轉格式，剛好可直接從下標 0 (最低位) 進行大數相加並去除前導零。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva713(const char *s1, const char *s2, char *res) {
    int l1 = (int)strlen(s1), l2 = (int)strlen(s2);
    int max_l = (l1 > l2) ? l1 : l2;
    int carry = 0, idx = 0;
    for (int i = 0; i < max_l || carry; i++) {
        int d1 = (i < l1) ? (s1[i] - '0') : 0;
        int d2 = (i < l2) ? (s2[i] - '0') : 0;
        int sum = d1 + d2 + carry;
        res[idx++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    res[idx] = '\0';
    /* Remove leading zeros in reversed output */
    int start = 0;
    while (res[start] == '0' && start < idx - 1) start++;
    if (start > 0) memmove(res, res + start, idx - start + 1);
}

int main(void) {

    char res[50];
    solve_uva713("24", "1", res); /* 42 + 1 = 43 -> reversed is 34 */
    int ok = (strcmp(res, "34") == 0);
    printf("%s: UVa 713 - Adding Reversed Numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
