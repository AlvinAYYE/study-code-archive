/*
 * ==========================================================================
 * UVa 10018 - Reverse and Add
 * Title-CN: 反轉相加與回文數
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: math, simulation, palindrome
 * URL: https://onlinejudge.org/external/100/10018.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Choose a number, reverse its digits and add to the original. Repeat
 *     until the sum becomes a palindrome. Print iterations and the palindrome.
 *
 * [中文] 題目說明:
 *     選定一個整數，將其反轉後與原數相加，若非回文數則重複此操作，直到形成回文數。
 *     輸出所需次數與該回文數。
 *
 * [EN] Approach: Loop reverse and add using unsigned long long.
 * [中文] 思路: 寫一個 reverse 函式，每次迭代將原數加上反轉數，直到 reverse(n) == n。
 * ==========================================================================
 */
#include <stdio.h>

static unsigned long long rev_num(unsigned long long n) {
    unsigned long long r = 0;
    while (n > 0) {
        r = r * 10 + (n % 10);
        n /= 10;
    }
    return r;
}

void solve_uva10018(unsigned long long n, int *iterations, unsigned long long *palindrome) {
    int it = 0;
    while (1) {
        unsigned long long r = rev_num(n);
        if (it > 0 && r == n) break;
        n += r;
        it++;
    }
    *iterations = it;
    *palindrome = n;
}

int main(void) {
    int it;
    unsigned long long pal;
    solve_uva10018(195, &it, &pal);
    int ok = (it == 4 && pal == 9339);
    printf("%s: UVa 10018 - Reverse and Add\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
