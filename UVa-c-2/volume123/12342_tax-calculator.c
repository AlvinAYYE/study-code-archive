/*
 * ==========================================================================
 * UVa 12342 - Tax Calculator
 * Title-CN: 所得稅試算
 * Difficulty: Easy
 * Tags: Simulation, Math
 * URL: https://onlinejudge.org/external/123/12342.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate income tax using progressive brackets with a minimum tax rule (if tax > 0, tax = max(ceil(tax), 2000)).
 *
 * [中文] 題目說明:
 *     依據累進稅率計算個人所得稅，若需繳稅則最低稅額為 2000 元（不滿 2000 算 2000，取無條件進位）。
 *
 * [EN] Approach:
 *     Apply tax brackets (first 180k exempt, next 300k at 10%, next 400k at 15%, next 300k at 20%, remainder at 25%). If tax > 0 and tax < 2000, tax = 2000.
 * [中文] 思路:
 *     依各級距累進課稅，計算總稅額並無條件進位；若有稅額且小於 2000 則一律以 2000 計。
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

long long calculate_tax(long long income) {
    if (income <= 180000) return 0;
    income -= 180000;
    double tax = 0.0;
    // bracket 1: 300,000 at 10%
    long long b1 = (income < 300000 ? income : 300000);
    tax += b1 * 0.10;
    income -= b1;
    // bracket 2: 400,000 at 15%
    if (income > 0) {
        long long b2 = (income < 400000 ? income : 400000);
        tax += b2 * 0.15;
        income -= b2;
    }
    // bracket 3: 300,000 at 20%
    if (income > 0) {
        long long b3 = (income < 300000 ? income : 300000);
        tax += b3 * 0.20;
        income -= b3;
    }
    // bracket 4: remainder at 25%
    if (income > 0) {
        tax += income * 0.25;
    }
    long long final_tax = (long long)ceil(tax);
    if (final_tax > 0 && final_tax < 2000) final_tax = 2000;
    return final_tax;
}

int main(void) {

    int ok = (calculate_tax(180000) == 0) && (calculate_tax(200000) == 2000);
    printf("%s: UVa 12342 - Tax Calculator\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
