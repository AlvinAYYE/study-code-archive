/*
 * ==========================================================================
 * UVa 11292 - Dragon of Loowater
 * Title-CN: 羅特瓦爾的巨龍與英勇騎士
 * Difficulty: UVa Star 1
 * Tags: greedy, sorting
 * URL: https://onlinejudge.org/external/112/11292.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Each knight of height H can cut off a dragon head of diameter <= H and costs H gold. Find minimum gold to slay all heads or report doomed.
 *
 * [中文] 題目說明:
 *     身高為 H 的騎士能砍下直徑 <= H 的龍頭並索取 H 枚金幣。求砍下所有龍頭所需的最少金幣總額，若無法斬殺則輸出失敗。
 *
 * [EN] Approach:
 *     Sort dragon heads and knight heights ascending. Greedily match each dragon head to the smallest knight whose height >= head diameter.
 * [中文] 思路:
 *     將龍頭直徑與騎士身高由小到大排序，貪婪地以可斬下龍頭之最小騎士依序迎戰，騎士用完仍有龍頭殘存則判為失敗。
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

static int cmp_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int solve_uva11292(int n, int m, int *heads, int *knights) {
    qsort(heads, n, sizeof(int), cmp_int);
    qsort(knights, m, sizeof(int), cmp_int);
    int h_idx = 0, k_idx = 0, total_cost = 0;
    while (h_idx < n && k_idx < m) {
        if (knights[k_idx] >= heads[h_idx]) {
            total_cost += knights[k_idx];
            h_idx++;
        }
        k_idx++;
    }
    return (h_idx == n) ? total_cost : -1;
}

int main(void) {

    int h[] = {5, 4}, k[] = {7, 8, 4};
    int ans = solve_uva11292(2, 3, h, k);
    int ok = (ans == 11); // 4->4, 5->7: 4+7 = 11
    printf("%s: UVa 11292 - Dragon of Loowater\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
