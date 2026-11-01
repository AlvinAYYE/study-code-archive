/*
 * ==========================================================================
 * UVa 10509 - R U Kidding Mr. Feynman?
 * Title-CN: 費曼先生，你在開玩笑嗎？ (立方根一階泰勒展開)
 * Difficulty: Easy
 * Tags: Math, Approximation
 * URL: https://onlinejudge.org/external/105/10509.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Approximate cbrt(n) using Feynman's method: find integer a such that a^3 <= n, then cbrt(n) ~ a + (n - a^3) / (3 * a^2).
 *
 * [中文] 題目說明:
 *     利用費曼近似法估算立方根：找出使 a^3 <= n 的最大整數 a，則 cbrt(n) ~ a + (n - a^3) / (3 * a^2)。
 *
 * [EN] Approach:
 *     Direct calculation of formula: a = floor(cbrt(n)), dx = (n - a*a*a) / (3.0 * a * a). Ans = a + dx.
 * [中文] 思路:
 *     代入費曼一階泰勒展開公式：a = floor(cbrt(n))，dx = (n - a^3) / (3 * a^2)，回傳 a + dx。
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

double feynman_cbrt(double n) {
    int a = 1;
    while ((a + 1) * (a + 1) * (a + 1) <= n + 1e-9) a++;
    double dx = (n - a * a * a) / (3.0 * a * a);
    return a + dx;
}

int main(void) {

    double res = feynman_cbrt(65.0); // a=4, 65-64=1, 1 / (3*16) = 1/48 ~ 0.0208 -> 4.0208
    int ok = (fabs(res - 4.0208) < 0.001);
    printf("%s: UVa 10509 - R U Kidding Mr. Feynman?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
