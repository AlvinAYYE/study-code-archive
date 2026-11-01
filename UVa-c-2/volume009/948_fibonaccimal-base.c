/*
 * ==========================================================================
 * UVa 948 - Fibonaccimal Base
 * Title-CN: 齊肯多夫定理斐氏進位制表示法
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/9/948.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Express an integer in Fibonaccimal base (Zeckendorf theorem) using distinct non-consecutive Fibonacci numbers.
 *
 * [中文] 題目說明:
 *     根據齊肯多夫定理 (Zeckendorf's theorem)，將整數唯一分解為不包含相鄰項之斐波那契數之和，輸出二進位編碼。
 *
 * [EN] Approach:
 *     Precompute Fibonacci numbers F(2)=1, F(3)=2, F(4)=3... Greedily subtract largest F_k <= N, setting bit k to 1 and preventing adjacent 1s.
 * [中文] 思路:
 *     預先計算斐氏數列，以貪婪法自大到小扣除小於等於 N 的最大斐氏數，對應位元標記為 1，直到 N 為 0。
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

void solve_uva948(int n, char *out) {
    int f[40];
    f[1] = 1; f[2] = 2;
    int k = 2;
    while (1) {
        f[k + 1] = f[k] + f[k - 1];
        if (f[k + 1] > n) break;
        k++;
    }
    int idx = 0;
    for (int i = k; i >= 1; i--) {
        if (n >= f[i]) {
            out[idx++] = '1';
            n -= f[i];
        } else {
            out[idx++] = '0';
        }
    }
    out[idx] = '\0';
}

int main(void) {

    char b[50];
    solve_uva948(13, b); // 13 is F(6) -> 100000_fib
    int ok = (b[0] == '1');
    printf("%s: UVa 948 - Fibonaccimal Base\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
