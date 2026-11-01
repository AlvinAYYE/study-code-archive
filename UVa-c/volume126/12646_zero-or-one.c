/*
 * ==========================================================================
 * UVa 12646 - Zero or One
 * Title-CN: 零與一抓獨特者 (三人猜拳獨贏)
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/126/12646.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Three players output 0 or 1. Output winner 'A', 'B', 'C' if one player chose differently, or '*' if draw.
 *
 * [中文] 題目說明:
 *     三人各自出 0 或 1。若恰有一人出的數字與另外兩人不同，則該人獲勝；若三人皆同則為平局 '*'。
 *
 * [EN] Approach:
 *     Conditional check: if A != B and A != C output A; if B != A and B != C output B; if C != A and C != B output C; else *.
 * [中文] 思路:
 *     判斷分支：若某人的數字與另外兩人皆不同則該人獲勝，若三人出相同數字則輸出 '*'。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char solve_uva12646(int a, int b, int c) {
    if (a != b && a != c) return 'A';
    if (b != a && b != c) return 'B';
    if (c != a && c != b) return 'C';
    return '*';
}

int main(void) {

    int ok = (solve_uva12646(1, 0, 0) == 'A') && (solve_uva12646(1, 1, 1) == '*');
    printf("%s: UVa 12646 - Zero or One\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
