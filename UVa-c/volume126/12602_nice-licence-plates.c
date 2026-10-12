/*
 * ==========================================================================
 * UVa 12602 - Nice Licence Plates
 * Title-CN: 車牌優美度檢驗
 * Difficulty: UVa Star 1
 * Tags: math, string
 * ==========================================================================
 * [EN] Problem: Plate format LLL-DDDD. Compute |base26(LLL) - DDDD| <= 100 -> "nice", else "not nice".
 * [中文] 題目說明: 車牌為 LLL-DDDD，將前三英文字母視為 26 進位數，若與後四位數字差值絕對值 <= 100 則為 nice。
 * [EN] Approach: val1 = (L1*'26^2' + L2*'26' + L3), abs(val1 - DDDD) <= 100.
 * [中文] 思路: 計算三位 26 進位值與後四位十進位值的差值絕對值是否 <= 100。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int is_nice_plate(const char *plate) {
    int v1 = (plate[0] - 'A') * 26 * 26 + (plate[1] - 'A') * 26 + (plate[2] - 'A');
    int v2 = atoi(plate + 4);
    return abs(v1 - v2) <= 100;
}

int main(void) {
    int ok = is_nice_plate("ABC-0123") && !is_nice_plate("AAA-9999");
    printf("%s: UVa 12602 - Nice Licence Plates\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
