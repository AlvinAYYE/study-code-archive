/*
 * ==========================================================================
 * UVa 11219 - How old are you?
 * Title-CN: 精確年齡計算與異常檢測
 * Difficulty: UVa Star 1
 * Tags: simulation, date
 * URL: https://onlinejudge.org/external/112/11219.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given current date and birth date (DD/MM/YYYY), calculate age in years. Output 'Invalid birth date' or 'Check birth date' (> 130).
 *
 * [中文] 題目說明:
 *     給定當前日期與出生日期，計算實歲年齡。若尚未出生輸出 Invalid birth date，若年齡大於 130 歲輸出 Check birth date。
 *
 * [EN] Approach:
 *     Compare dates: years diff = cur_y - birth_y. If cur_month < birth_month or (same month and cur_day < birth_day), decrement age.
 * [中文] 思路:
 *     實歲計算邏輯：年份相減，若當前月份未到生日月或同月但日期未達生日當天，則實歲減 1。檢測小於 0 與大於 130 歲邊界。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11219(int cd, int cm, int cy, int bd, int bm, int by, int *age) {
    int a = cy - by;
    if (cm < bm || (cm == bm && cd < bd)) a--;
    if (a < 0) return -1; /* Invalid */
    if (a > 130) return 1; /* Check */
    *age = a;
    return 0; /* OK */
}

int main(void) {

    int a;
    int st = solve_uva11219(1, 1, 2026, 1, 1, 2000, &a);
    int ok = (st == 0 && a == 26);
    printf("%s: UVa 11219 - How old are you?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
