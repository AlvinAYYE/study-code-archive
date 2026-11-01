/*
 * ==========================================================================
 * UVa 10035 - Primary Arithmetic
 * Title-CN: 小學算術 (計算進位次數)
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, simulation, elementary-math
 * URL: https://onlinejudge.org/external/100/10035.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     Children are taught to add multi-digit numbers from right to left,
 *     one digit at a time. Many find the "carry" operation difficult.
 *     Your task is to calculate the number of carry operations for each addition.
 *
 * [中文] 題目說明:
 *     小朋友在學習多位數加法時，通常從右向左逐位相加。
 *     很多人常在「進位」步驟出錯。
 *     請寫一個程式計算兩個數相加時總共發生了幾次進位運算。
 *
 * Examples:
 *   Input:
 *     123 456
 *     555 555
 *     123 594
 *     0 0
 *   Output:
 *     No carry operation.
 *     3 carry operations.
 *     1 carry operation.
 *
 * Constraints:
 *   - The two numbers are less than 10 digits each.
 *   - End of input is marked by 0 0.
 *
 * [EN] Approach:
 *     Extract digits using modulo 10 and division 10 in a loop.
 *     Maintain a carry flag/value (0 or 1). Time O(digits), Space O(1).
 * [中文] 思路:
 *     逐位取出最低位數並加上前一次的進位值，若和 >= 10 則進位數加 1，
 *     進位標記更新為 1，直到兩數皆為 0 且無進位為止。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10035(unsigned long long a, unsigned long long b) {
    int carry = 0;
    int carry_count = 0;

    while (a > 0 || b > 0) {
        int d1 = (int)(a % 10);
        int d2 = (int)(b % 10);
        int sum = d1 + d2 + carry;
        if (sum >= 10) {
            carry = 1;
            carry_count++;
        } else {
            carry = 0;
        }
        a /= 10;
        b /= 10;
    }
    return carry_count;
}

int main(void) {
    int ok = 1;
    ok = ok && (solve_uva10035(123, 456) == 0);
    ok = ok && (solve_uva10035(555, 555) == 3);
    ok = ok && (solve_uva10035(123, 594) == 1);
    printf("%s: UVa 10035 - Primary Arithmetic\n", ok ? "PASS" : "FAIL");

    /*
     * For UVa Online Judge submission / UVa 送出模式：
     *
     * unsigned long long a, b;
     * while (scanf("%llu %llu", &a, &b) == 2 && (a != 0 || b != 0)) {
     *     int c = solve_uva10035(a, b);
     *     if (c == 0) printf("No carry operation.\n");
     *     else if (c == 1) printf("1 carry operation.\n");
     *     else printf("%d carry operations.\n", c);
     * }
     */
    return ok ? 0 : 1;
}
