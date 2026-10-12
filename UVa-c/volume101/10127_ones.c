/*
 * ==========================================================================
 * UVa 10127 - Ones
 * Title-CN: 全 1 數整除問題
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * ==========================================================================
 * [EN] Problem: Smallest all-ones number divisible by n.
 * [中文] 題目說明: 求能被 n 整除的全 1 數之最短長度。
 * [EN] Approach: rem = (rem * 10 + 1) % n until rem == 0.
 * [中文] 思路: 餘數模擬：rem = (rem * 10 + 1) % n，計數直到餘數為 0。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10127(int n) {
    int rem = 0, count = 0;
    do {
        rem = (rem * 10 + 1) % n;
        count++;
    } while (rem != 0);
    return count;
}

int main(void) {
    int ok = (solve_uva10127(3) == 3) && (solve_uva10127(7) == 6);
    printf("%s: UVa 10127 - Ones\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
