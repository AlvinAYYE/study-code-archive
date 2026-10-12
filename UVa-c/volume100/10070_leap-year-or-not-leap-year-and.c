/*
 * ==========================================================================
 * UVa 10070 - Leap Year or Not Leap Year and...
 * Title-CN: 閏年、節慶年與哈庫魯年
 * Difficulty: UVa Star 1
 * Tags: math, big-integer, divisibility
 * ==========================================================================
 * [EN] Problem: Determine leap year, huluculu (div 15), and bulukulu (leap and div 55).
 * [中文] 題目說明: 大整數判斷閏年、15的倍數與55的倍數。
 * [EN] Approach: Big-integer modulo 4, 100, 400, 15, 55.
 * [中文] 思路: 依序對各被除數做同餘運算。
 * ==========================================================================
 */
#include <stdio.h>

static int mod(const char *s, int m) {
    int r = 0;
    for (int i = 0; s[i]; i++) r = (r * 10 + (s[i] - '0')) % m;
    return r;
}

void solve_uva10070(const char *s, int *leap, int *hulu, int *bulu) {
    int mod4 = mod(s, 4);
    int mod100 = mod(s, 100);
    int mod400 = mod(s, 400);
    int mod15 = mod(s, 15);
    int mod55 = mod(s, 55);

    *leap = (mod400 == 0 || (mod4 == 0 && mod100 != 0));
    *hulu = (mod15 == 0);
    *bulu = (*leap && mod55 == 0);
}

int main(void) {
    int l, h, b;
    solve_uva10070("2000", &l, &h, &b);
    int ok = (l == 1);
    printf("%s: UVa 10070 - Leap Year or Not Leap Year and\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
