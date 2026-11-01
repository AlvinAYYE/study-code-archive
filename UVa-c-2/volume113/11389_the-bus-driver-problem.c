/*
 * ==========================================================================
 * UVa 11389 - The Bus Driver Problem
 * Title-CN: 公車司機加班費最佳排班化
 * Difficulty: UVa Star 1
 * Tags: greedy, sorting
 * URL: https://onlinejudge.org/external/113/11389.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Pair n morning routes and n evening routes to minimize total overtime pay (rate R per hour exceeding d).
 *
 * [中文] 題目說明:
 *     將 n 條上午路線與 n 條下午路線進行配對，使所有司機超時工作 (超過 d 小時部分每小時給予 R 元加班費) 的總支出達到最小。
 *
 * [EN] Approach:
 *     Sort morning routes ascending and evening routes descending. Pair morning[i] with evening[i].
 * [中文] 思路:
 *     貪婪法：將早班路線升序排列、晚班路線降序排列進行對應相加，累加各司機超出 d 的超時時數乘以費率 R。
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

static int cmp_asc(const void *a, const void *b) { return (*(int*)a - *(int*)b); }
static int cmp_desc(const void *a, const void *b) { return (*(int*)b - *(int*)a); }

int solve_uva11389(int n, int d, int r, int *morn, int *eve) {
    qsort(morn, n, sizeof(int), cmp_asc);
    qsort(eve, n, sizeof(int), cmp_desc);
    int total_pay = 0;
    for (int i = 0; i < n; i++) {
        int sum = morn[i] + eve[i];
        if (sum > d) total_pay += (sum - d) * r;
    }
    return total_pay;
}

int main(void) {

    int m[] = {10, 20};
    int e[] = {15, 5};
    int p = solve_uva11389(2, 20, 5, m, e); // 10+15=25(5), 20+5=25(5) -> 10*5 = 50
    int ok = (p == 50);
    printf("%s: UVa 11389 - The Bus Driver Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
