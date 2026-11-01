/*
 * ==========================================================================
 * UVa 11690 - Money Matters
 * Title-CN: 金錢糾葛 (並查集連通塊債務平衡)
 * Difficulty: Easy
 * Tags: Disjoint Set Union, Graph
 * URL: https://onlinejudge.org/external/116/11690.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Friends owe each other money. Money can only be transferred between direct friends. Determine if all debts can be settled (sum of balances in each connected component is 0).
 *
 * [中文] 題目描述:
 *     朋友間互有債務（正值代表應收，負值代表應付），金錢只能在好友間轉移，求各連通分量內的債務是否均可平賬（各連通塊總和為 0）。
 *
 * [EN] Approach:
 *     Union-Find connecting friends. Accumulate individual money balances onto root of each component. Settled iff balance[root] == 0 for all roots.
 *
 * [中文] 解題思維:
 *     以並查集合併好友關係，並在並查集根節點累加該連通塊內所有成員的資金餘額，檢查每個連通分量餘額和是否皆為 0。
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

int dsu_find_mm(int *p, int x) { return p[x] == x ? x : (p[x] = dsu_find_mm(p, p[x])); }
bool can_settle_debts(int n, int m, int *money, const int edges[][2]) {
    int p[50];
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int ru = dsu_find_mm(p, edges[i][0]), rv = dsu_find_mm(p, edges[i][1]);
        if (ru != rv) {
            p[ru] = rv;
            money[rv] += money[ru];
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == i && money[i] != 0) return false;
    }
    return true;
}

int main(void) {

    int mon[] = {100, -100, -50, 50};
    int e[][2] = {{0, 1}, {2, 3}};
    int ok = can_settle_debts(4, 2, mon, e);
    printf("%s: UVa 11690 - Money Matters\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
