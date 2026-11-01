/*
 * ==========================================================================
 * UVa 10365 - Blocks
 * Title-CN: 積木長方體最小表面積
 * Difficulty: Easy
 * Tags: Math, Brute Force
 * URL: https://onlinejudge.org/external/103/10365.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum surface area of a box containing N unit cubes (A * B * C = N, minimize 2*(A*B + B*C + C*A)).
 *
 * [中文] 題目說明:
 *     求用 N 塊單位立方體拼成的長方體（A * B * C = N）的最小表面積 2*(AB + BC + CA)。
 *
 * [EN] Approach:
 *     Brute force search A <= cbrt(N) and B <= sqrt(N/A). Let C = N / (A*B). Find min(2*(A*B + B*C + C*A)).
 * [中文] 思路:
 *     三重因數枚舉：A 跑至 cbrt(N)，B 跑至 sqrt(N/A)，令 C = N / (A*B)，取表面積最小值。
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

int min_block_surface(int n) {
    int min_sa = 10000000;
    for (int a = 1; a * a * a <= n; a++) {
        if (n % a == 0) {
            int rem = n / a;
            for (int b = a; b * b <= rem; b++) {
                if (rem % b == 0) {
                    int c = rem / b;
                    int sa = 2 * (a * b + b * c + c * a);
                    if (sa < min_sa) min_sa = sa;
                }
            }
        }
    }
    return min_sa;
}

int main(void) {

    int ok = (min_block_surface(9) == 30) && (min_block_surface(10) == 34); // 9: 1x3x3 -> 2*(3+9+3)=30
    printf("%s: UVa 10365 - Blocks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
