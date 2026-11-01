/*
 * ==========================================================================
 * UVa 11934 - Magic Formula
 * Title-CN: 神奇二次多項式整除次數統計
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/119/11934.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a, b, c, d, L, count how many x in [0, L] satisfy f(x) = ax^2 + bx + c is divisible by d.
 *
 * [中文] 題目說明:
 *     給定常數 a, b, c, d 與上限 L，計算在 0 <= x <= L 區間內滿足 f(x) = ax^2 + bx + c 能被 d 整除之 x 的個數。
 *
 * [EN] Approach:
 *     Iterate x from 0 to L; evaluate f(x) and check if f(x) % d == 0.
 * [中文] 思路:
 *     循序走訪 x 自 0 至 L，計算二次多項式 f(x) 並檢驗其對 d 取模是否為 0，累加滿足條件之數量。
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

int solve_uva11934(long long a, long long b, long long c, long long d, int l) {
    int cnt = 0;
    for (int x = 0; x <= l; x++) {
        long long f = a * x * x + b * x + c;
        if (f % d == 0) cnt++;
    }
    return cnt;
}

int main(void) {

    int ans = solve_uva11934(1, 0, 0, 4, 10); // x^2 % 4 == 0 for even x: 0, 2, 4, 6, 8, 10 -> 6
    int ok = (ans == 6);
    printf("%s: UVa 11934 - Magic Formula\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
