/*
 * ==========================================================================
 * UVa 11369 - Shopaholic
 * Title-CN: 購物狂買三送一折扣金額最大化
 * Difficulty: UVa Star 1
 * Tags: greedy, sorting
 * URL: https://onlinejudge.org/external/113/11369.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Buy 3 items, get the cheapest free. Maximize total discount by grouping items greedily.
 *
 * [中文] 題目說明:
 *     商場優惠買三件免一件 (免費贈送三件中最便宜者)，求將所購物品適當分組下能獲得之最大折扣總金額。
 *
 * [EN] Approach:
 *     Sort item prices in descending order. Take every 3rd item (index 2, 5, 8...) into discount sum.
 * [中文] 思路:
 *     將物品價格由大到小排序，每三件一組，選取每組中最便宜的第 3 件 (索引 2, 5, 8...) 累計折扣金額。
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

static int cmp_desc11369(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int solve_uva11369(int n, int *prices) {
    qsort(prices, n, sizeof(int), cmp_desc11369);
    int total_discount = 0;
    for (int i = 2; i < n; i += 3) {
        total_discount += prices[i];
    }
    return total_discount;
}

int main(void) {

    int p[] = {400, 100, 200, 350, 300, 250};
    int d = solve_uva11369(6, p); // (400, 350, 300->300) + (250, 200, 100->100) = 400
    int ok = (d == 400);
    printf("%s: UVa 11369 - Shopaholic\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
