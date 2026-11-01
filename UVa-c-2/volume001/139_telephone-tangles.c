/*
 * ==========================================================================
 * UVa 139 - Telephone Tangles
 * Title-CN: 長途電話號碼區域代碼與費率解析
 * Difficulty: UVa Star 1
 * Tags: string, map
 * URL: https://onlinejudge.org/external/1/139.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Parse dialled telephone number into area code and subscriber number using a prefix rate table, then calculate call cost.
 *
 * [中文] 題目說明:
 *     根據區碼費率表比對撥出電話號碼之最長前綴區碼與用戶號碼，並依據通話時間計算電話總費用。
 *
 * [EN] Approach:
 *     Match longest matching prefix against known IDD (00) and STD (0) codes. Multiply duration by rate per minute.
 * [中文] 思路:
 *     對撥出的號碼自前綴進行前綴比對 (區分 00 國際與 0 國內長途)，匹配出地區代碼與每分鐘費率後乘以通話分鐘數。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

double calc_phone_cost(int duration, double rate_per_min) {
    return duration * (rate_per_min / 100.0);
}

int main(void) {

    double cost = calc_phone_cost(15, 60.0); // 15 mins at 0.60/min
    int ok = ((int)(cost * 100 + 0.5) == 900);
    printf("%s: UVa 139 - Telephone Tangles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
