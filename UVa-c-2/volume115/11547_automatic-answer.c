/*
 * ==========================================================================
 * UVa 11547 - Automatic Answer
 * Title-CN: 自動解答十位數數字提取
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/115/11547.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Follow arithmetic steps on n: (((n*567/9 + 7492)*235/47 - 498)/10) % 10. Output absolute value of tens digit.
 *
 * [中文] 題目說明:
 *     依照算術題順序計算：將 n 乘以 567，除以 9，加上 7492，乘以 235，除以 47，減去 498，求十位數數字的絕對值。
 *
 * [EN] Approach:
 *     Algebraic simplification: ((n * 63 + 7492) * 5 - 498). Divide by 10 and take abs(res % 10).
 * [中文] 思路:
 *     簡化運算：計算 ans = (n * 63 + 7492) * 5 - 498，除以 10 後對 10 取餘數並取絕對值得到十位數數字。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stdlib.h>

int solve_uva11547(long long n) {
    long long ans = (n * 63 + 7492) * 5 - 498;
    if (ans < 0) ans = -ans;
    return (int)((ans / 10) % 10);
}

int main(void) {

    int ok = (solve_uva11547(637) == 1) && (solve_uva11547(-234) == 4);
    printf("%s: UVa 11547 - Automatic Answer\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
