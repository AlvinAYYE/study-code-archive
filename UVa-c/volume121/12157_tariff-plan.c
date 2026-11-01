/*
 * ==========================================================================
 * UVa 12157 - Tariff Plan
 * Title-CN: 通話費率方案最佳選擇比較
 * Difficulty: UVa Star 1
 * Tags: basics, math
 * URL: https://onlinejudge.org/external/121/12157.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compare Mile plan (10 cents every 30s) and Juice plan (15 cents every 60s) for a list of call durations. Output cheaper plan name and cost.
 *
 * [中文] 題目說明:
 *     比較 Mile 方案 (每 30 秒 10 美分) 與 Juice 方案 (每 60 秒 15 美分) 在多通電話通話時間下的總話費，輸出最划算的方案名稱與金額。
 *
 * [EN] Approach:
 *     For duration D, Mile cost = (D / 30 + 1) * 10; Juice cost = (D / 60 + 1) * 15. Sum over calls and compare.
 * [中文] 思路:
 *     單次通話 D 秒，Mile 費用為 (D/30 + 1)*10，Juice 費用為 (D/60 + 1)*15，累加比較何者較低或並列。
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

int solve_uva12157(int n, int *calls, int *mile_cost, int *juice_cost) {
    *mile_cost = 0; *juice_cost = 0;
    for (int i = 0; i < n; i++) {
        *mile_cost += (calls[i] / 30 + 1) * 10;
        *juice_cost += (calls[i] / 60 + 1) * 15;
    }
    if (*mile_cost < *juice_cost) return 1; // Mile
    if (*juice_cost < *mile_cost) return 2; // Juice
    return 3; // Mile Juice
}

int main(void) {

    int c[] = {61};
    int m, j;
    int win = solve_uva12157(1, c, &m, &j); // Mile=30, Juice=30
    int ok = (win == 3 && m == 30);
    printf("%s: UVa 12157 - Tariff Plan\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
