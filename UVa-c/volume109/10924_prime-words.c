/*
 * ==========================================================================
 * UVa 10924 - Prime Words
 * Title-CN: 質數單字
 * Difficulty: UVa Star 1
 * Tags: math, string, prime
 * ==========================================================================
 * [EN] Problem: Check if sum of letter values is prime (1 is treated as prime).
 * [中文] 題目說明: 字母轉數值求和並判定質數（1 算質數）。
 * [EN] Approach: Sum values, check primality.
 * [中文] 思路: 累加字母對應數值後質數檢驗。
 * ==========================================================================
 */
#include <stdio.h>
#include <ctype.h>

static int is_prime_word(int n) {
    if (n <= 2) return 1; /* Note: 1 is prime by problem definition */
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int solve_uva10924(const char *word) {
    int sum = 0;
    for (int i = 0; word[i]; i++) {
        char c = word[i];
        if (islower((unsigned char)c)) sum += c - 'a' + 1;
        else if (isupper((unsigned char)c)) sum += c - 'A' + 27;
    }
    return is_prime_word(sum);
}

int main(void) {
    int ok = solve_uva10924("UFRN") && !solve_uva10924("contest");
    printf("%s: UVa 10924 - Prime Words\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
