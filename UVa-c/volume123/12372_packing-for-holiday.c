/*
 * ==========================================================================
 * UVa 12372 - Packing for Holiday
 * Title-CN: 假日行李箱尺寸檢驗
 * Difficulty: UVa Star 1
 * Tags: basics, simulation
 * URL: https://onlinejudge.org/external/123/12372.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Check if a suitcase with dimensions L, W, H fits within the maximum airline luggage limits of 20 x 20 x 20.
 *
 * [中文] 題目說明:
 *     給定行李箱長寬高 L, W, H，檢驗其是否各維度均不超過航空公司隨身行李限制 20 x 20 x 20。
 *
 * [EN] Approach:
 *     Return 1 (good) if L <= 20 and W <= 20 and H <= 20, else 0 (bad).
 * [中文] 思路:
 *     單純比較 L <= 20 且 W <= 20 且 H <= 20 即可判定是否符合規格。
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

int solve_uva12372(int l, int w, int h) {
    return (l <= 20 && w <= 20 && h <= 20);
}

int main(void) {

    int ok = solve_uva12372(20, 20, 20) && !solve_uva12372(21, 10, 10);
    printf("%s: UVa 12372 - Packing for Holiday\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
