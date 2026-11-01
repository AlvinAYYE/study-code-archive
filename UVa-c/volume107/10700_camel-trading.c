/*
 * ==========================================================================
 * UVa 10700 - Camel trading
 * Title-CN: 駱駝交易
 * Difficulty: Easy
 * Tags: Greedy, Math, Expression Parsing
 * URL: https://onlinejudge.org/external/107/10700.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given an arithmetic expression with additions and multiplications, evaluate maximum possible value (addition first) and minimum possible value (multiplication first).
 *
 * [中文] 題目概述:
 *     給定包含加法與乘法的算式，求可能的最大值（加法優先）與最小值（乘法優先）。
 *
 * [EN] Approach:
 *     For max, perform all '+' before '*'. For min, perform all '*' before '+'.
 * [中文] 解題思路:
 *     最大值：先做所有加法再做乘法；最小值：先做所有乘法再做加法。
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

void camel_trade(const char *expr, long long *max_v, long long *min_v) {
    long long nums[20];
    char ops[20];
    int n_cnt = 0, o_cnt = 0;
    const char *p = expr;
    while (*p) {
        long long val = 0;
        while (*p >= '0' && *p <= '9') { val = val * 10 + (*p - '0'); p++; }
        nums[n_cnt++] = val;
        if (*p == '+' || *p == '*') { ops[o_cnt++] = *p; p++; }
    }
    long long t_nums[20];
    int t_cnt = 0;
    long long cur = nums[0];
    for (int i = 0; i < o_cnt; i++) {
        if (ops[i] == '+') cur += nums[i+1];
        else { t_nums[t_cnt++] = cur; cur = nums[i+1]; }
    }
    t_nums[t_cnt++] = cur;
    long long mx = 1;
    for (int i = 0; i < t_cnt; i++) mx *= t_nums[i];

    t_cnt = 0; cur = nums[0];
    for (int i = 0; i < o_cnt; i++) {
        if (ops[i] == '*') cur *= nums[i+1];
        else { t_nums[t_cnt++] = cur; cur = nums[i+1]; }
    }
    t_nums[t_cnt++] = cur;
    long long mn = 0;
    for (int i = 0; i < t_cnt; i++) mn += t_nums[i];

    *max_v = mx; *min_v = mn;
}

int main(void) {

    long long mx, mn;
    camel_trade("1+2*3+4", &mx, &mn);
    int ok = (mx == 21 && mn == 11);
    printf("%s: UVa 10700 - Camel trading\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
