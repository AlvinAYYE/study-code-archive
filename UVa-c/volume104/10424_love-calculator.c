/*
 * ==========================================================================
 * UVa 10424 - Love Calculator
 * Title-CN: 愛情契合度計算機 (數位和單數位化比例)
 * Difficulty: UVa Star 1
 * Tags: math, string, simulation
 * URL: https://onlinejudge.org/external/104/10424.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute love percentage: sum letter values a=1..z=26, repeatedly sum digits to 1 digit, ratio = min/max * 100%.
 *
 * [中文] 題目說明:
 *     計算名字契合度：英文字母對應 1-26 加總，反覆計算數位和縮減為個位數，契合度為 (小數 / 大數) * 100%。
 *
 * [EN] Approach:
 *     Sum letter values. Digits reduction function: while(s >= 10) sum digits. Ratio = (v1 < v2 ? v1/v2 : v2/v1) * 100.
 * [中文] 思路:
 *     計算姓名英文字母權重和，反覆累加數位縮至個位數，兩者取較小值除以較大值乘 100 得到百分比。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <ctype.h>

int reduce_digits_10424(int n) {
    while (n >= 10) {
        int s = 0;
        while (n) { s += n % 10; n /= 10; }
        n = s;
    }
    return n;
}

double solve_uva10424(const char *n1, const char *n2) {
    int s1 = 0, s2 = 0;
    for (int i = 0; n1[i]; i++) {
        if (isalpha((unsigned char)n1[i])) s1 += tolower((unsigned char)n1[i]) - 'a' + 1;
    }
    for (int i = 0; n2[i]; i++) {
        if (isalpha((unsigned char)n2[i])) s2 += tolower((unsigned char)n2[i]) - 'a' + 1;
    }
    int v1 = reduce_digits_10424(s1);
    int v2 = reduce_digits_10424(s2);
    if (v1 == 0 && v2 == 0) return 0.0;
    return (v1 < v2) ? ((double)v1 / v2 * 100.0) : ((double)v2 / v1 * 100.0);
}

int main(void) {

    double res = solve_uva10424("sring", "sring");
    int ok = (fabs(res - 100.0) < 1e-4);
    printf("%s: UVa 10424 - Love Calculator\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
