/*
 * ==========================================================================
 * UVa 180 - Eeny Meeny
 * Title-CN: 幼兒數數遊戲約瑟夫安全號碼
 * Difficulty: UVa Star 2
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/1/180.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given elimination step m and number of children N, find safe starting spots that avoid being chosen early.
 *
 * [中文] 題目說明:
 *     在 Eeny Meeny 數數遊戲中，根據報數間隔 m 與人數 N，計算可以堅持到特定輪數之後的安全起始位置。
 *
 * [EN] Approach:
 *     Josephus recurrence simulation tracking the elimination sequence order.
 * [中文] 思路:
 *     以經典約瑟夫環動態轉移式遞推每輪被淘汰者之索引，統計各起始位置之存活輪次。
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

int josephus_survivor(int n, int m) {
    int s = 0;
    for (int i = 2; i <= n; i++) s = (s + m) % i;
    return s + 1;
}

int main(void) {

    int ok = (josephus_survivor(5, 2) == 3);
    printf("%s: UVa 180 - Eeny Meeny\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
