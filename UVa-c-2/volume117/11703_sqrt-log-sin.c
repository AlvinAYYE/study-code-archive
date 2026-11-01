/*
 * ==========================================================================
 * UVa 11703 - sqrt log sin
 * Title-CN: 平方根對數正弦遞推數列
 * Difficulty: Easy
 * Tags: DP, Math
 * URL: https://onlinejudge.org/external/117/11703.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute x_i = (x_{i - sqrt(i)} + x_{ln(i)} + x_{i*sin^2(i)}) mod 1,000,000 with x_0 = 1.
 *
 * [中文] 題目說明:
 *     計算遞推數列 x_i = (x_{i - sqrt(i)} + x_{ln(i)} + x_{i*sin^2(i)}) mod 1,000,000，初值 x_0 = 1。
 *
 * [EN] Approach:
 *     Precompute array up to 1,000,000 in O(N) using floor and double math functions.
 * [中文] 思路:
 *     利用動態規劃陣列由 1 遞推至 1,000,000，下標使用 floor(i - sqrt(i))、floor(log(i))、floor(i * sin(i)^2)。
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

int eval_sqrt_log_sin(int n) {
    static int x[1005] = {0};
    x[0] = 1;
    for (int i = 1; i <= n && i <= 1000; i++) {
        int a = (int)floor(i - sqrt(i));
        int b = (int)floor(log((double)i));
        int c = (int)floor(i * sin((double)i) * sin((double)i));
        x[i] = (x[a] + x[b] + x[c]) % 1000000;
    }
    return x[n];
}

int main(void) {

    int res = eval_sqrt_log_sin(1); // a=0, b=0, c=0 -> 1+1+1 = 3
    int ok = (res == 3);
    printf("%s: UVa 11703 - sqrt log sin\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
