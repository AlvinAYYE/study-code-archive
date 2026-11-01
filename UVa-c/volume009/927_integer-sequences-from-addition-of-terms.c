/*
 * ==========================================================================
 * UVa 927 - Integer Sequences from Addition of Terms
 * Title-CN: 多項式序列數值求取
 * Difficulty: Easy
 * Tags: Math, Polynomial Evaluation
 * URL: https://onlinejudge.org/external/9/927.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A sequence repeats a_n d*n times. Find the k-th element of the expanded sequence where a_n is a polynomial.
 *
 * [中文] 題目說明:
 *     數列中 a_n 連續重複 d*n 次，求展開後的數列中第 k 個元素的值（a_n 為給定多項式）。
 *
 * [EN] Approach:
 *     Sum of counts S(n) = d * n * (n + 1) / 2. Find smallest n such that S(n) >= k, then evaluate polynomial a_n.
 * [中文] 思路:
 *     前 n 項的總展開項數為 d * n * (n + 1) / 2，求使總項數 >= k 的最小整數 n，再將 n 代入多項式計算 a_n。
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

long long eval_seq_k(int deg, const long long *coef, long long d, long long k) {
    long long n = 1;
    while (d * n * (n + 1) / 2 < k) n++;
    long long val = 0, p = 1;
    for (int i = 0; i <= deg; i++) {
        val += coef[i] * p;
        p *= n;
    }
    return val;
}

int main(void) {

    long long c[] = {0, 1}; // a_n = n
    long long ans = eval_seq_k(1, c, 1, 4); // n=1(1), n=2(2,3), n=3(4,5,6) -> n=3 -> a_3 = 3
    int ok = (ans == 3);
    printf("%s: UVa 927 - Integer Sequences from Addition of Terms\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
