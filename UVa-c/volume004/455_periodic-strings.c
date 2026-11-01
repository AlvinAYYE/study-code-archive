/*
 * ==========================================================================
 * UVa 455 - Periodic Strings
 * Title-CN: 週期字串最小週期
 * Difficulty: UVa Star 1
 * Tags: string, brute-force, kmp
 * URL: https://onlinejudge.org/external/4/455.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find length of smallest repeating period substring that forms the entire string.
 *
 * [中文] 題目說明:
 *     找出能連續重複拼接構成原字串的最小週期子字串長度。
 *
 * [EN] Approach:
 *     Try period length L from 1 to N. If N % L == 0, check if s[i] == s[i % L] for all i. First valid L is answer.
 * [中文] 思路:
 *     由 1 到 N 枚舉週期長度 L。若 N 可被 L 整除，驗證每個字元是否皆滿足 s[i] == s[i % L]，首個合法者即為最小週期。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva455(const char *s) {
    int n = (int)strlen(s);
    for (int len = 1; len <= n; len++) {
        if (n % len == 0) {
            int ok = 1;
            for (int i = len; i < n; i++) {
                if (s[i] != s[i % len]) { ok = 0; break; }
            }
            if (ok) return len;
        }
    }
    return n;
}

int main(void) {

    int ok = (solve_uva455("HaHaHa") == 2) && (solve_uva455("abcde") == 5);
    printf("%s: UVa 455 - Periodic Strings\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
