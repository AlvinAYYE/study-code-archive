/*
 * ==========================================================================
 * UVa 12502 - Three Families
 * Title-CN: 三戶人家花園打掃補貼工資分攤
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/125/12502.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Family A works x hours and Family B works y hours for common garden. Family C pays z dollars. Calculate Family A's fair share of money.
 *
 * [中文] 題目說明:
 *     三家合用花園由 A 家工作 x 小時、B 家工作 y 小時，C 家因未出力補貼 z 元，求 A 家應分得之合理報酬金額。
 *
 * [EN] Approach:
 *     Total hours is x + y. Each family owes (x+y)/3 hours. A's extra hours: x - (x+y)/3 = (2x - y)/3. Share = z * (2x - y) / (x + y).
 * [中文] 思路:
 *     平均每家應負擔 (x+y)/3 小時，A 戶超額付出 x - (x+y)/3 = (2x - y)/3，故 A 戶應得金額為 z * (2x - y) / (x + y)。
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

int solve_uva12502(int x, int y, int z) {
    int ans = z * (2 * x - y) / (x + y);
    return ans > 0 ? ans : 0;
}

int main(void) {

    int ans = solve_uva12502(5, 3, 80); // 80 * (10 - 3) / 8 = 70
    int ok = (ans == 70);
    printf("%s: UVa 12502 - Three Families\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
