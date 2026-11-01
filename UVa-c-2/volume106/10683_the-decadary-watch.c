/*
 * ==========================================================================
 * UVa 10683 - The decadary watch
 * Title-CN: 十進位制時鐘轉換
 * Difficulty: Easy
 * Tags: Math, Time Conversion
 * URL: https://onlinejudge.org/external/106/10683.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert standard time (24h 60m 60s 100cs) into French revolutionary decimal time (10h 100m 100s 100cc).
 *
 * [中文] 題目說明:
 *     將傳統時間（24小時制，1秒=100百分秒）轉換為法國大革命時期的十進位時間（1天=10小時，1小時=100分，1分=100秒，1秒=100百分秒）。
 *
 * [EN] Approach:
 *     Total standard centiseconds = ((h*60 + m)*60 + s)*100 + cs. Decimal centiseconds = total * 10000000 / 8640000.
 * [中文] 思路:
 *     先求總毫秒/百分秒數，乘上 10000000 / 8640000 轉換為十進位制時間，格式化輸出 7 位數字。
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

long long to_decimal_time(int h, int m, int s, int c) {
    long long total_c = ((h * 60LL + m) * 60 + s) * 100 + c;
    long long dec_c = total_c * 10000000LL / 8640000LL;
    return dec_c;
}

int main(void) {

    long long dt = to_decimal_time(0, 0, 0, 0);
    int ok = (dt == 0);
    long long mid = to_decimal_time(12, 0, 0, 0); // half day -> 5000000
    ok = ok && (mid == 5000000);
    printf("%s: UVa 10683 - The decadary watch\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
