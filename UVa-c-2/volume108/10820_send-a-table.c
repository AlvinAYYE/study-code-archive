/*
 * ==========================================================================
 * UVa 10820 - Send a Table
 * Title-CN: 傳送乘法表 (歐拉函數前綴和)
 * Difficulty: Easy
 * Tags: Math, Number Theory, Euler Totient
 * URL: https://onlinejudge.org/external/108/10820.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of pairs (x, y) with 1 <= x, y <= N such that gcd(x, y) = 1.
 *
 * [中文] 題目說明:
 *     求滿足 1 <= x, y <= N 且 gcd(x, y) = 1 的互質數對 (x, y) 總數。
 *
 * [EN] Approach:
 *     Count = 1 + 2 * sum_{i=2}^N phi(i) where phi is Euler's totient function.
 * [中文] 思路:
 *     互質對總數由尤拉函數給出：除了 (1,1) 外對稱分佈，公式為 1 + 2 * sum_{i=2}^N phi(i)。
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

int euler_phi(int n) {
    int ans = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            ans -= ans / p;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}
int send_a_table_pairs(int n) {
    if (n == 1) return 1;
    int sum = 1;
    for (int i = 2; i <= n; i++) sum += 2 * euler_phi(i);
    return sum;
}

int main(void) {

    int ok = (send_a_table_pairs(1) == 1) && (send_a_table_pairs(2) == 3) && (send_a_table_pairs(5) == 19);
    printf("%s: UVa 10820 - Send a Table\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
