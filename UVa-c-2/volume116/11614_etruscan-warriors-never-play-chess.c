/*
 * ==========================================================================
 * UVa 11614 - Etruscan Warriors Never Play Chess
 * Title-CN: 伊特魯里亞勇士三角隊形行數計算
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/116/11614.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given N warriors standing in triangular formation (1 in row 1, 2 in row 2, etc.), find maximum completed rows k such that k*(k+1)/2 <= N.
 *
 * [中文] 題目說明:
 *     給定 N 名戰士排成三角形隊形 (第 1 排 1 人、第 2 排 2 人……)，計算最多可排滿幾行使得 k*(k+1)/2 <= N。
 *
 * [EN] Approach:
 *     Solve quadratic inequality k^2 + k - 2N <= 0 -> k = floor((-1 + sqrt(1 + 8N)) / 2).
 * [中文] 思路:
 *     解二次不等式 k(k+1)/2 <= N，利用公式解求得 k = floor((-1 + sqrt(1 + 8N)) / 2)。
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

long long solve_uva11614(long long n) {
    long long k = (long long)((sqrt(1.0 + 8.0 * n) - 1.0) / 2.0);
    return k;
}

int main(void) {

    int ok = (solve_uva11614(3) == 2 && solve_uva11614(6) == 3 && solve_uva11614(7) == 3);
    printf("%s: UVa 11614 - Etruscan Warriors Never Play Chess\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
