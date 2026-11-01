/*
 * ==========================================================================
 * UVa 1316 - Supermarket
 * Title-CN: 超市促銷排程 (貪心並查集時間槽)
 * Difficulty: Medium
 * Tags: Greedy, Disjoint Set Union, Priority Queue
 * URL: https://onlinejudge.org/external/13/1316.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Schedule products with profits and deadlines (each takes 1 unit of time) to maximize total profit.
 *
 * [中文] 題目說明:
 *     每件商品有銷售利潤與截止期限（每單位時間只能售出一件商品），求最大獲利總額。
 *
 * [EN] Approach:
 *     Sort products by profit descending. Use DSU to find the latest available free time slot <= deadline for each product.
 * [中文] 思路:
 *     貪心法：商品依利潤降序排序，用並查集維護小於等於截止期限的最晚可用時間槽，成功佔位則獲取利潤。
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

int dsu_find_slot(int *p, int x) { return p[x] == x ? x : (p[x] = dsu_find_slot(p, p[x])); }
int max_supermarket_profit(int n, int items[][2]) {
    // Sort descending by profit
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (items[i][0] < items[j][0]) {
                int t0 = items[i][0], t1 = items[i][1];
                items[i][0] = items[j][0]; items[i][1] = items[j][1];
                items[j][0] = t0; items[j][1] = t1;
            }
    int p[10005];
    for (int i = 0; i <= 10000; i++) p[i] = i;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int profit = items[i][0], deadline = items[i][1];
        int slot = dsu_find_slot(p, deadline);
        if (slot > 0) {
            total += profit;
            p[slot] = slot - 1;
        }
    }
    return total;
}

int main(void) {

    int it[3][2] = {{50, 2}, {10, 1}, {20, 2}};
    int prof = max_supermarket_profit(3, it); // take 50 at t=2, 20 at t=1 -> 70
    int ok = (prof == 70);
    printf("%s: UVa 1316 - Supermarket\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
