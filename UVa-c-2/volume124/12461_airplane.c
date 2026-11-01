/*
 * ==========================================================================
 * UVa 12461 - Airplane
 * Title-CN: 飛機乘客入座機率
 * Difficulty: Easy
 * Tags: Math, Probability
 * URL: https://onlinejudge.org/external/124/12461.pdf
 * ==========================================================================
 * [EN] Problem:
 *     First passenger loses boarding pass and picks random seat. Each subsequent passenger sits in assigned seat if free, else picks random seat. Find probability last passenger sits in own seat.
 *
 * [中文] 題目說明:
 *     第一位乘客登機證遺失隨機入座，後續乘客若自己座位空著則坐自己位置否則隨機挑位，求最後一名乘客坐到自己座位的機率。
 *
 * [EN] Approach:
 *     Classic puzzle: the answer is always 1/2 for any n >= 2.
 * [中文] 思路:
 *     經典機率問題：不論總人數 n 為多少 (n >= 2)，最後一名乘客坐到自己座位的機率恆為 1/2。
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

void airplane_prob(int n, int *num, int *den) {
    *num = 1;
    *den = 2;
}

int main(void) {

    int nu, de;
    airplane_prob(100, &nu, &de);
    int ok = (nu == 1 && de == 2);
    printf("%s: UVa 12461 - Airplane\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
