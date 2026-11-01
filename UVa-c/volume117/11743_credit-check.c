/*
 * ==========================================================================
 * UVa 11743 - Credit Check
 * Title-CN: 信用卡號碼校驗 (盧恩演算法 Luhn)
 * Difficulty: UVa Star 1
 * Tags: simulation, math
 * URL: https://onlinejudge.org/external/117/11743.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Validate 16-digit credit card number using Luhn algorithm: double alternate digits, sum digits of products, check sum % 10 == 0.
 *
 * [中文] 題目說明:
 *     使用盧恩演算法驗證 16 位信用卡號：奇數位數字乘以 2 後各位數位加總，加上偶數位數字，若總和尾數為 0 則合法。
 *
 * [EN] Approach:
 *     Iterate digits: for odd positions (from right), d = 2*digit; add d/10 + d%10. For even positions, add digit. Check total % 10 == 0.
 * [中文] 思路:
 *     依據標準 Luhn 規則計算位數加權：相隔一位乘以 2 (兩位數拆開相加)，其餘直接加總，驗證總和 mod 10 是否為 0。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11743(const char *digits16) {
    int sum = 0;
    for (int i = 0; i < 16; i++) {
        int d = digits16[i] - '0';
        if (i % 2 == 0) {
            int d2 = d * 2;
            sum += (d2 / 10) + (d2 % 10);
        } else {
            sum += d;
        }
    }
    return (sum % 10 == 0);
}

int main(void) {

    int ok = (!solve_uva11743("5181271099000012")) && solve_uva11743("5181271099000017");
    printf("%s: UVa 11743 - Credit Check\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
