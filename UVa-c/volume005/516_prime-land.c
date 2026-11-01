/*
 * ==========================================================================
 * UVa 516 - Prime Land
 * Title-CN: 質數之國 (質因數分解與 n-1 還原反轉)
 * Difficulty: UVa Star 1
 * Tags: math, number-theory, prime-factorization
 * URL: https://onlinejudge.org/external/5/516.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given prime factor representation of x, compute x - 1 and output its prime factorization in descending prime order.
 *
 * [中文] 題目說明:
 *     給定數值 x 的質因數分解表示，計算 x - 1 並將其質因數分解結果按質數由大到小輸出。
 *
 * [EN] Approach:
 *     Compute x = prod(p_i^e_i). Subtract 1, then factorize x - 1 up to sqrt(x-1). Output factors in descending order.
 * [中文] 思路:
 *     累乘算出原數 x，將 x - 1 進行標準質因數分解，依質因數由大到小印出底數與指數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva516(int num, int *out_p, int *out_e, int *cnt) {
    *cnt = 0;
    for (int d = 2; d * d <= num; d++) {
        if (num % d == 0) {
            int e = 0;
            while (num % d == 0) { num /= d; e++; }
            out_p[*cnt] = d;
            out_e[*cnt] = e;
            (*cnt)++;
        }
    }
    if (num > 1) {
        out_p[*cnt] = num;
        out_e[*cnt] = 1;
        (*cnt)++;
    }
}

int main(void) {

    int p[10], e[10], cnt;
    solve_uva516(12, p, e, &cnt); /* 12 = 2^2 * 3^1 */
    int ok = (cnt == 2 && p[0] == 2 && e[0] == 2);
    printf("%s: UVa 516 - Prime Land\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
