/*
 * ==========================================================================
 * UVa 10131 - Is Bigger Smarter?
 * Title-CN: 體重越大越聰明嗎？
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, lis, sorting
 * ==========================================================================
 * [EN] Problem: Find longest sequence of elephants where weight is strictly increasing and IQ strictly decreasing.
 * [中文] 題目說明: 求最長的大象子序列，使得體重嚴格遞增且智商 IQ 嚴格遞減。
 * [EN] Approach: Sort elephants primarily by weight ascending. Run DP for Longest Decreasing Subsequence on IQ.
 * [中文] 思路: 體重升序排序後，對 IQ 求最長嚴格遞減子序列 (LDS)，並回溯路徑。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int id, w, s; } Elephant;

static int cmp_e(const void *a, const void *b) {
    const Elephant *ea = (const Elephant *)a;
    const Elephant *eb = (const Elephant *)b;
    if (ea->w != eb->w) return ea->w - eb->w;
    return eb->s - ea->s;
}

int solve_uva10131(int n, Elephant *e) {
    qsort(e, (size_t)n, sizeof(Elephant), cmp_e);
    int dp[105];
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (e[j].w < e[i].w && e[j].s > e[i].s && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max_len) max_len = dp[i];
    }
    return max_len;
}

int main(void) {
    Elephant e[3] = {{1, 600, 100}, {2, 700, 90}, {3, 800, 80}};
    int len = solve_uva10131(3, e);
    int ok = (len == 3);
    printf("%s: UVa 10131 - Is Bigger Smarter\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
