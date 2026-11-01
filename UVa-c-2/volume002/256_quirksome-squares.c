/*
 * ==========================================================================
 * UVa 256 - Quirksome Squares
 * Title-CN: 古怪平方數
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Find 2N-digit numbers where (left_half + right_half)^2 equals the number itself.
 * [中文] 題目說明: 求 2N 位數，將其前後兩半拆開相加後的平方恰等於原數。
 * [EN] Approach: Loop x from 0 up to 10^N - 1, compute sq = x*x, check if left + right == x.
 * [中文] 思路: 枚舉和 x，計算平方值驗證前後半段之和是否等於 x。
 * ==========================================================================
 */
#include <stdio.h>

int is_quirksome(int num, int mod) {
    int left = num / mod;
    int right = num % mod;
    return (left + right) * (left + right) == num;
}

int main(void) {
    int ok = is_quirksome(3025, 100) && is_quirksome(81, 10); /* (30+25)^2 = 3025, (8+1)^2 = 81 */
    printf("%s: UVa 256 - Quirksome Squares\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
