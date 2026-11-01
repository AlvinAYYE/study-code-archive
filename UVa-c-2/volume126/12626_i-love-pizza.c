/*
 * ==========================================================================
 * UVa 12626 - I Love Pizza
 * Title-CN: MARGARITA 披薩字母配料製作上限
 * Difficulty: UVa Star 1
 * Tags: string, greedy
 * URL: https://onlinejudge.org/external/126/12626.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count maximum 'MARGARITA' pizzas that can be made from letters in string (M:1, A:3, R:2, G:1, I:1, T:1).
 *
 * [中文] 題目說明:
 *     製作一個 MARGARITA 披薩需要字母：M:1, A:3, R:2, G:1, I:1, T:1。給定字母庫，求最多可製作多少個完整披薩。
 *
 * [EN] Approach:
 *     Tally letter counts. Max pizzas = min(M/1, A/3, R/2, G/1, I/1, T/1).
 * [中文] 思路:
 *     統計字串中各字母數量，依配方除以所需份數取瓶頸最小值：min(M, A/3, R/2, G, I, T)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva12626(const char *s) {
    int c[128] = {0};
    for (int i = 0; s[i]; i++) c[(unsigned char)s[i]]++;
    int ans = c['M'];
    if (c['A'] / 3 < ans) ans = c['A'] / 3;
    if (c['R'] / 2 < ans) ans = c['R'] / 2;
    if (c['G'] < ans) ans = c['G'];
    if (c['I'] < ans) ans = c['I'];
    if (c['T'] < ans) ans = c['T'];
    return ans;
}

int main(void) {

    int ok = (solve_uva12626("MARGARITA") == 1) && (solve_uva12626("MMMAAARRRGGGIITTT") == 1);
    printf("%s: UVa 12626 - I Love Pizza\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
