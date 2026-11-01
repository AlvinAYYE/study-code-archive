/*
 * ==========================================================================
 * UVa 10375 - Choose and divide
 * Title-CN: 組合數相除 C(p,q) / C(r,s)
 * Difficulty: Easy
 * Tags: Math, Combinatorics, Logarithms
 * URL: https://onlinejudge.org/external/103/10375.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute the ratio of two binomial coefficients C(p, q) / C(r, s) accurately without overflow.
 *
 * [中文] 題目說明:
 *     精確計算兩個二項式組合數的商 C(p, q) / C(r, s) 避免大數溢位。
 *
 * [EN] Approach:
 *     Interleave multiplications and divisions, or factorize into primes, or sum logs and exponentiate.
 * [中文] 思路:
 *     交替進行乘法與除法保持數值在合理浮點數範圍內，或對兩側質因數分解後計算最終乘積。
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

double choose_and_divide(int p, int q, int r, int s) {
    if (q > p - q) q = p - q;
    if (s > r - s) s = r - s;
    double ans = 1.0;
    int max_terms = (q > s ? q : s);
    for (int i = 1; i <= max_terms; i++) {
        if (i <= q) ans = ans * (p - q + i) / i;
        if (i <= s) ans = ans / (r - s + i) * i;
    }
    return ans;
}

int main(void) {

    double res = choose_and_divide(5, 2, 4, 2); // C(5,2)=10, C(4,2)=6 -> 10/6 = 1.66667
    int ok = (fabs(res - 1.666667) < 1e-4);
    printf("%s: UVa 10375 - Choose and divide\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
