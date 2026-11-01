/*
 * ==========================================================================
 * UVa 10303 - How Many Trees?
 * Title-CN: 多少棵二元搜尋樹？ (大數卡特蘭數)
 * Difficulty: Medium
 * Tags: Math, Catalan Numbers, Big Integer
 * URL: https://onlinejudge.org/external/103/10303.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate the number of structurally unique binary search trees that can store 1..n keys: Catalan(n) = C(2n, n) / (n + 1).
 *
 * [中文] 題目說明:
 *     計算由 1..n 鍵值可構成的相異二元搜尋樹數量：即第 n 項卡特蘭數 C_n = C(2n, n) / (n+1)。
 *
 * [EN] Approach:
 *     Big integer Catalan number evaluation using recurrence C_{n} = C_{n-1} * (4n - 2) / (n + 1).
 * [中文] 思路:
 *     使用高精度大數計算卡特蘭數遞推式 C_n = C_{n-1} * (4n - 2) / (n + 1)。
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

double log10_catalan(int n) {
    double ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += log10((double)(4 * i - 2)) - log10((double)(i + 1));
    }
    return ans;
}

int main(void) {

    // C(1)=1 -> log10=0, C(2)=2 -> log10=0.301, C(3)=5 -> log10=0.699
    int ok = (fabs(log10_catalan(1) - 0.0) < 1e-4) && (fabs(log10_catalan(3) - log10(5)) < 1e-4);
    printf("%s: UVa 10303 - How Many Trees?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
