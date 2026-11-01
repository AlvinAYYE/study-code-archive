/*
 * ==========================================================================
 * UVa 12602 - Nice Licence Plates
 * Title-CN: 好車牌判定 (26進位英文字母與數字差值)
 * Difficulty: UVa Star 1
 * Tags: math, string, base-conversion
 * URL: https://onlinejudge.org/external/126/12602.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Plate 'LLL-DDDD' is nice if absolute difference between base-26 value of letters and decimal digits is <= 100.
 *
 * [中文] 題目說明:
 *     車牌格式為 3 個字母接 4 個數字。字母視為 26 進位數，若其值與 4 位數十進位值的絕對差 <= 100 則為好車牌。
 *
 * [EN] Approach:
 *     Base-26 value = (c0-'A')*676 + (c1-'A')*26 + (c2-'A'). Check abs(base26 - digits) <= 100.
 * [中文] 思路:
 *     將前 3 個大寫字母按 26 進位轉為十進位數值，與後 4 位十進位整數相減取絕對值，小於等於 100 輸出 nice，否則 not nice。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stdlib.h>

int solve_uva12602(const char *plate) {
    int v26 = (plate[0] - 'A') * 676 + (plate[1] - 'A') * 26 + (plate[2] - 'A');
    int d = atoi(plate + 4);
    return abs(v26 - d) <= 100;
}

int main(void) {

    int ok = solve_uva12602("ABC-0123") && !solve_uva12602("AAA-9999");
    printf("%s: UVa 12602 - Nice Licence Plates\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
