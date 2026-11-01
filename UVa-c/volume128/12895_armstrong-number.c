/*
 * ==========================================================================
 * UVa 12895 - Armstrong Number
 * Title-CN: 阿姆斯壯數判定 (各數位 N 次方和)
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/128/12895.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if integer is Armstrong number (sum of each digit raised to power of number of digits equals original number).
 *
 * [中文] 題目說明:
 *     判定整數是否為阿姆斯壯數 (即每位數字的 d 次方之和等於原數，其中 d 為總位數)。
 *
 * [EN] Approach:
 *     Extract digits. Let d be number of digits. Compute sum_{i} digit_i^d and compare with original number.
 * [中文] 思路:
 *     解析數位得到總位數 d，計算每個數位的 d 次方累加和，若總和等於原數則判定為 Armstrong 數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

int solve_uva12895(long long n) {
    long long t = n;
    int digits[20], d = 0;
    while (t) { digits[d++] = t % 10; t /= 10; }
    long long sum = 0;
    for (int i = 0; i < d; i++) {
        long long p = 1;
        for (int k = 0; k < d; k++) p *= digits[i];
        sum += p;
    }
    return sum == n;
}

int main(void) {

    int ok = solve_uva12895(153) && solve_uva12895(370) && !solve_uva12895(123);
    printf("%s: UVa 12895 - Armstrong Number\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
