/*
 * ==========================================================================
 * UVa 11629 - Ballot evaluation
 * Title-CN: 選票百分比不等式驗證
 * Difficulty: Easy
 * Tags: Parsing, Math, Precision
 * URL: https://onlinejudge.org/external/116/11629.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Verify whether a sum of vote percentages satisfies a given comparison operator against an integer.
 *
 * [中文] 題目描述:
 *     檢驗候選人得票百分比之和是否滿足給定的比較運算子與目標數值（利用乘以 10 避免浮點誤差）。
 *
 * [EN] Approach:
 *     Scale all percentages by 10 to operate strictly on integers, preventing floating-point precision issues.
 *
 * [中文] 解題思維:
 *     將所有百分比數值乘以 10 轉為純整數運算，根據運算子 (<, >, <=, >=, =) 進行準確判斷。
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

int evaluate_ballot(int sum_tenths, const char *op, int target_tenths) {
    if (strcmp(op, "<") == 0) return sum_tenths < target_tenths;
    if (strcmp(op, ">") == 0) return sum_tenths > target_tenths;
    if (strcmp(op, "<=") == 0) return sum_tenths <= target_tenths;
    if (strcmp(op, ">=") == 0) return sum_tenths >= target_tenths;
    if (strcmp(op, "=") == 0) return sum_tenths == target_tenths;
    return 0;
}

int main(void) {

    // 50.5% + 49.5% = 100.0% -> sum_tenths = 1000
    int ok = evaluate_ballot(1000, "=", 1000) &&
             evaluate_ballot(505, ">", 500) &&
             !evaluate_ballot(500, "<", 500);
    printf("%s: UVa 11629 - Ballot evaluation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
