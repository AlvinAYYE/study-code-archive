/*
 * ==========================================================================
 * UVa 13025 - Back to the Past
 * Title-CN: 重返過去指定歷史星期日期輸出
 * Difficulty: UVa Star 1
 * Tags: basics
 * URL: https://onlinejudge.org/external/130/13025.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Output the fixed date 'May 29, 2013 Wednesday' corresponding to the inaugural contest date.
 *
 * [中文] 題目說明:
 *     直接印出指定歷史日期 "May 29, 2013 Wednesday"。
 *
 * [EN] Approach:
 *     Return constant formatted string directly.
 * [中文] 思路:
 *     依據題意回傳固定常數字串 "May 29, 2013 Wednesday"。
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

const char* solve_uva13025(void) {
    return "May 29, 2013 Wednesday";
}

int main(void) {

    int ok = (strcmp(solve_uva13025(), "May 29, 2013 Wednesday") == 0);
    printf("%s: UVa 13025 - Back to the Past\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
