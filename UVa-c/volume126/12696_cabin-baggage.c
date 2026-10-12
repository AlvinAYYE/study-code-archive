/*
 * ==========================================================================
 * UVa 12696 - Cabin Baggage
 * Title-CN: 登機隨身行李規格檢驗
 * Difficulty: UVa Star 1
 * Tags: simulation
 * ==========================================================================
 * [EN] Problem: Bag allowed if weight <= 7.0 AND ((L<=56 and W<=45 and D<=25) OR (L+W+D <= 125)).
 * [中文] 題目說明: 行李允許登機條件：重量 <= 7.0 且 (長<=56且寬<=45且高<=25 或 總三邊長和<=125)。
 * [EN] Approach: Direct conditional evaluation.
 * [中文] 思路: 條件表達式檢驗。
 * ==========================================================================
 */
#include <stdio.h>

int is_baggage_allowed(double l, double w, double d, double wt) {
    if (wt > 7.0) return 0;
    int dim_ok = (l <= 56.0 && w <= 45.0 && d <= 25.0) || (l + w + d <= 125.0);
    return dim_ok;
}

int main(void) {
    int ok = is_baggage_allowed(50.0, 40.0, 20.0, 6.5) && !is_baggage_allowed(60.0, 50.0, 30.0, 8.0);
    printf("%s: UVa 12696 - Cabin Baggage\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
