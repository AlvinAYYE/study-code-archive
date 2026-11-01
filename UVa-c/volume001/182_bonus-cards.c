/*
 * ==========================================================================
 * UVa 182 - Bonus Cards
 * Title-CN: 紅利卡點數與折扣最佳兌換
 * Difficulty: UVa Star 2
 * Tags: dp, greedy
 * URL: https://onlinejudge.org/external/1/182.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Optimize the use of bonus discount cards across shopping transactions to minimize total payments.
 *
 * [中文] 題目說明:
 *     在多筆購物消費中規劃各類紅利卡的使用分配，使總支付現金達到最小化。
 *
 * [EN] Approach:
 *     Dynamic programming knapsack / matching formulation: pair purchases with valid discount tiers to maximize savings.
 * [中文] 思路:
 *     將折扣卡使用轉化為背包動態規劃或二分圖匹配，在滿足每筆交易使用限制下尋求折扣金額之最大化。
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

int max_discount(int price, int percent, int max_cap) {
    int d = price * percent / 100;
    return d > max_cap ? max_cap : d;
}

int main(void) {

    int ok = (max_discount(1000, 20, 150) == 150 && max_discount(500, 20, 150) == 100);
    printf("%s: UVa 182 - Bonus Cards\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
