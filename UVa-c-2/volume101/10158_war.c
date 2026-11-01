/*
 * ==========================================================================
 * UVa 10158 - War
 * Title-CN: 戰爭
 * Difficulty: Medium
 * Tags: Disjoint Set Union
 * URL: https://onlinejudge.org/external/101/10158.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Maintain relationships between friends and enemies using DSU with negation / 2N representation.
 *
 * [中文] 題目概述:
 *     使用擴展並查集 (2N 節點) 維護人與人之間的朋友與敵人關係。
 *
 * [EN] Approach:
 *     Use 2N union-find where node x represents x, and x+N represents enemy(x). Friends: union(x, y) & union(x+N, y+N). Enemies: union(x, y+N) & union(x+N, y).
 * [中文] 解題思路:
 *     使用 2N 大小的並查集，x 為本體，x+N 為敵人。朋友則合併 x 與 y、x+N 與 y+N；敵人則合併 x 與 y+N、x+N 與 y。
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

int war_find(int *parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = war_find(parent, parent[x]);
}
void war_union(int *parent, int a, int b) {
    parent[war_find(parent, a)] = war_find(parent, b);
}
int set_friends(int *parent, int n, int x, int y) {
    if (war_find(parent, x) == war_find(parent, y + n)) return -1;
    war_union(parent, x, y);
    war_union(parent, x + n, y + n);
    return 0;
}

int main(void) {

    int parent[20];
    for (int i = 0; i < 20; i++) parent[i] = i;
    int res = set_friends(parent, 10, 0, 1);
    int ok = (res == 0 && war_find(parent, 0) == war_find(parent, 1));
    printf("%s: UVa 10158 - War\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
