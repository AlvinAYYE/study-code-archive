/*
 * ==========================================================================
 * UVa 694 - The Collatz Sequence
 * Title-CN: 考拉茲數列上限項數統計
 * Difficulty: UVa Star 1
 * Tags: simulation, math
 * ==========================================================================
 * [EN] Problem: Count steps in Collatz 3n+1 sequence before exceeding limit L or reaching 1.
 * [中文] 題目說明: 計算考拉茲 3n+1 序列在到達 1 或超過上限 L 之前產生的項數。
 * [EN] Approach: Loop while n != 1 and n <= L.
 * [中文] 思路: 模擬迴圈走訪，注意使用 long long 防溢位。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva694(long long n, long long limit) {
    int count = 0;
    while (n <= limit) {
        count++;
        if (n == 1) break;
        if (n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
    }
    return count;
}

int main(void) {
    int terms = solve_uva694(3, 100);
    int ok = (terms == 8);
    printf("%s: UVa 694 - The Collatz Sequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
