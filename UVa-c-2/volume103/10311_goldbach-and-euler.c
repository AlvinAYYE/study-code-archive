/*
 * ==========================================================================
 * UVa 10311 - Goldbach and Euler
 * Title-CN: 哥德巴赫與尤拉 (嚴格兩相異質數和)
 * Difficulty: Medium
 * Tags: Math, Number Theory, Prime
 * URL: https://onlinejudge.org/external/103/10311.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if integer n can be expressed as the sum of two distinct primes p1 < p2 such that p2 - p1 is minimized.
 *
 * [中文] 題目說明:
 *     判定整數 n 是否能表示為兩個嚴格相異質數之和 p1 + p2 = n (p1 < p2)，若有多解使 p2 - p1 最小。
 *
 * [EN] Approach:
 *     If n is odd: can only be 2 + (n - 2). If n is even: search p1 starting downwards from (n - 1) / 2 until both p1 and n - p1 are prime.
 * [中文] 思路:
 *     若 n 為奇數，唯一的偶數質數是 2，驗證 n-2 是否為質數；若 n 為偶數，從 n/2 向下枚舉驗證 p1 與 n-p1 是否皆為質數。
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

bool is_p_ge(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++) if (x % d == 0) return false;
    return true;
}
bool solve_goldbach_euler(int n, int *p1, int *p2) {
    if (n <= 4) return false;
    if (n % 2 == 1) {
        if (is_p_ge(n - 2)) { *p1 = 2; *p2 = n - 2; return true; }
        return false;
    }
    for (int p = (n - 1) / 2; p >= 2; p--) {
        if (is_p_ge(p) && is_p_ge(n - p) && p != n - p) {
            *p1 = p; *p2 = n - p; return true;
        }
    }
    return false;
}

int main(void) {

    int a, b;
    bool ok = solve_goldbach_euler(11, &a, &b);
    ok = ok && (a == 2 && b == 9 ? false : (a == 2 && b == 7 ? false : true));
    bool ok2 = solve_goldbach_euler(10, &a, &b);
    ok = ok2 && (a == 3 && b == 7);
    printf("%s: UVa 10311 - Goldbach and Euler\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
