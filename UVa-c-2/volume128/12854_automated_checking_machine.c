/*
 * ==========================================================================
 * UVa 12854 - Automated Checking Machine
 * Title-CN: 自動接頭匹配檢驗
 * Difficulty: Easy
 * Tags: Implementation, Bitwise
 * URL: https://onlinejudge.org/external/128/12854.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if two 5-pin connectors are complementary (every position has exactly one pin and one hole).
 *
 * [中文] 題目描述:
 *     判斷兩組 5 插針連接器是否互補匹配（每個位置剛好一個是凸針 1，另一個是凹孔 0）。
 *
 * [EN] Approach:
 *     Check if a[i] ^ b[i] == 1 for all i from 0 to 4.
 *
 * [中文] 解題思維:
 *     檢查五個插腳位置是否滿足 a[i] ^ b[i] == 1 (即 a[i] + b[i] == 1)。
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

int check_connector_compatible(const int a[5], const int b[5]) {
    for (int i = 0; i < 5; i++) {
        if ((a[i] ^ b[i]) != 1) return 0;
    }
    return 1;
}

int main(void) {

    int c1[5] = {1, 0, 1, 1, 0};
    int c2[5] = {0, 1, 0, 0, 1};
    int c3[5] = {0, 1, 1, 0, 1};
    int ok = check_connector_compatible(c1, c2) && !check_connector_compatible(c1, c3);
    printf("%s: UVa 12854 - Automated Checking Machine\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
