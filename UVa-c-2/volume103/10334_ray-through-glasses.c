/*
 * ==========================================================================
 * UVa 10334 - Ray Through Glasses
 * Title-CN: 光線穿透玻璃反射路徑數
 * Difficulty: UVa Star 2
 * Tags: math, fibonacci
 * URL: https://onlinejudge.org/external/103/10334.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of distinct reflection paths for a ray of light bouncing inside two sheets of glass n times.
 *
 * [中文] 題目說明:
 *     計算光線在兩塊緊貼的玻璃平板之間歷經 n 次反射時的所有相異可能反射路徑總數 (費氏數列 F(n+2))。
 *
 * [EN] Approach:
 *     The number of paths follows the Fibonacci sequence: paths(n) = F(n + 2).
 * [中文] 思路:
 *     光線反射路徑數精確對應費波那契數列：paths(0)=1, paths(1)=2, paths(2)=3, paths(n)=F(n+2)。
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

long long solve_uva10334(int n) {
    long long f[60];
    f[0] = 1; f[1] = 2;
    for (int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int main(void) {

    int ok = (solve_uva10334(0) == 1 && solve_uva10334(1) == 2 && solve_uva10334(2) == 3);
    printf("%s: UVa 10334 - Ray Through Glasses\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
