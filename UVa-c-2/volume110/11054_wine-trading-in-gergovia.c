/*
 * ==========================================================================
 * UVa 11054 - Wine trading in Gergovia
 * Title-CN: 格爾戈維亞葡萄酒交易最小運輸勞動量
 * Difficulty: UVa Star 1
 * Tags: greedy
 * URL: https://onlinejudge.org/external/110/11054.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N inhabitants on a street want to buy (>0) or sell (<0) wine (sum = 0). Moving 1 unit of wine 1 house costs 1 work unit. Find minimum total work.
 *
 * [中文] 題目概述:
 *     一條街上 N 戶人家各自買進 (>0) 或賣出 (<0) 葡萄酒 (總需供平衡為 0)，每運送 1 桶酒 1 戶距離耗費 1 單位工作量，求最小總工作量。
 *
 * [EN] Approach:
 *     Prefix sum tracking: moving wine between prefixes requires sum of absolute values of running net balances abs(prefix_sum).
 * [中文] 解題思路:
 *     貪婪前綴和法：相鄰房屋間必須流動的葡萄酒量恰等於前綴供需代數和，總勞動量即為 sum(abs(prefix_sum[i]))。
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

long long solve_uva11054(int n, long long *a) {
    long long total_work = 0, cur_balance = 0;
    for (int i = 0; i < n; i++) {
        cur_balance += a[i];
        total_work += (cur_balance < 0 ? -cur_balance : cur_balance);
    }
    return total_work;
}

int main(void) {

    long long a[] = {5, -4, 1, -3, 1}; // sum = 0
    long long w = solve_uva11054(5, a); // 5 + 1 + 2 + 1 + 0 = 9
    int ok = (w == 9);
    printf("%s: UVa 11054 - Wine trading in Gergovia\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
