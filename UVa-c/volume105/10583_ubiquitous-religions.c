/*
 * ==========================================================================
 * UVa 10583 - Ubiquitous Religions
 * Title-CN: 普遍的宗教信仰 (並查集連通分支計數)
 * Difficulty: UVa Star 1
 * Tags: data-structures, dsu
 * URL: https://onlinejudge.org/external/105/10583.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given pairs of students sharing the same religion, find maximum number of distinct religions across n students.
 *
 * [中文] 題目說明:
 *     給定信仰相同宗教的學生配對，求 n 個學生中最多可能信奉多少種相異宗教 (並查集計算連通分支數)。
 *
 * [EN] Approach:
 *     Disjoint Set Union (DSU). Start with n religions. Each successful union of two different sets decrements total by 1.
 * [中文] 思路:
 *     初始化宗教數為 n。以並查集處理信仰相同關係，每次合併不同集合時宗教總數減 1，最終剩餘集合數即為答案。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int p_10583[50005];

int find_10583(int x) { return (p_10583[x] == x) ? x : (p_10583[x] = find_10583(p_10583[x])); }

int solve_uva10583(int n, int m, int edges[][2]) {
    for (int i = 1; i <= n; i++) p_10583[i] = i;
    int sets = n;
    for (int i = 0; i < m; i++) {
        int u = find_10583(edges[i][0]);
        int v = find_10583(edges[i][1]);
        if (u != v) {
            p_10583[u] = v;
            sets--;
        }
    }
    return sets;
}

int main(void) {

    int e[2][2] = {{1, 2}, {2, 3}};
    int ok = (solve_uva10583(10, 2, e) == 8);
    printf("%s: UVa 10583 - Ubiquitous Religions\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
