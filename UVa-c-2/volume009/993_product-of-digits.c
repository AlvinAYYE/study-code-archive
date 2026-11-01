/*
 * ==========================================================================
 * UVa 993 - Product of digits
 * Title-CN: 乘積為 N 之最小正整數 (貪婪單數位因數分解)
 * Difficulty: UVa Star 1
 * Tags: greedy, math, number-theory
 * URL: https://onlinejudge.org/external/9/993.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find smallest positive integer Q such that the product of its decimal digits equals N.
 *
 * [中文] 題目說明:
 *     求最小正整數 Q，使其十進位各數位之乘積恰好等於 N (若無解輸出 -1)。
 *
 * [EN] Approach:
 *     Greedy approach: divide N by largest single digits from 9 down to 2. If N > 1 remains, no solution.
 * [中文] 思路:
 *     貪婪策略：由大到小嘗試用 9, 8, ..., 2 分解 N，將取得的因數倒序組合成位數最短且字典序最小的正整數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva993(long long n) {
    if (n < 10) return n;
    int digits[50], cnt = 0;
    for (int d = 9; d >= 2; d--) {
        while (n % d == 0) {
            digits[cnt++] = d;
            n /= d;
        }
    }
    if (n > 1) return -1;
    long long q = 0;
    for (int i = cnt - 1; i >= 0; i--) {
        q = q * 10 + digits[i];
    }
    return q;
}

int main(void) {

    int ok = (solve_uva993(10) == 25) && (solve_uva993(18) == 29) && (solve_uva993(11) == -1);
    printf("%s: UVa 993 - Product of digits\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
