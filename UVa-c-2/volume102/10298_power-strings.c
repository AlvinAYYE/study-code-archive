/*
 * ==========================================================================
 * UVa 10298 - Power Strings
 * Title-CN: 字串冪次週期 (KMP 失敗函數)
 * Difficulty: UVa Star 2
 * Tags: string, kmp
 * URL: https://onlinejudge.org/external/102/10298.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find largest n such that string s can be written as a^n for some string a.
 *
 * [中文] 題目說明:
 *     求字串 s 最多可由某子字串 a 重複拼接幾次而成 (s = a^n，求最大冪次 n)。
 *
 * [EN] Approach:
 *     KMP failure function pi: length L. If L % (L - pi[L]) == 0, ans = L / (L - pi[L]), else 1.
 * [中文] 思路:
 *     利用 KMP 前綴函數 pi 數值：若 L 可被 L - pi[L] 整除，則最小週期長度為 L - pi[L]，最大冪次為 L / (L - pi[L])。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10298(const char *s) {
    int n = (int)strlen(s);
    static int pi[1000005];
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    int k = n - pi[n - 1];
    if (n % k == 0) return n / k;
    return 1;
}

int main(void) {

    int ok = (solve_uva10298("abcd") == 1) && (solve_uva10298("aaaa") == 4) && (solve_uva10298("ababab") == 3);
    printf("%s: UVa 10298 - Power Strings\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
