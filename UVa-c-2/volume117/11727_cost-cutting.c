/*
 * ==========================================================================
 * UVa 11727 - Cost Cutting
 * Title-CN: 削減成本保留中等薪資 (三數取中位數)
 * Difficulty: UVa Star 1
 * Tags: sorting, math
 * URL: https://onlinejudge.org/external/117/11727.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given 3 employee salaries, find the middle salary (neither highest nor lowest).
 *
 * [中文] 題目說明:
 *     三位員工薪資互不相同，公司為精簡開銷，決定資遣最高薪與最低薪員工，求留任的中等薪資值 (三數中位數)。
 *
 * [EN] Approach:
 *     Sort 3 numbers or compute (a + b + c) - min(a, b, c) - max(a, b, c).
 * [中文] 思路:
 *     三數取中位數：三數總和減去最大值與最小值，即為留任的中等薪資。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11727(int a, int b, int c) {
    int min_val = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
    int max_val = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    return a + b + c - min_val - max_val;
}

int main(void) {

    int ok = (solve_uva11727(1000, 2000, 3000) == 2000) && (solve_uva11727(3000, 2500, 1500) == 2500);
    printf("%s: UVa 11727 - Cost Cutting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
