/*
 * ==========================================================================
 * UVa 307 - Sticks
 * Title-CN: 小木棍拼接
 * Difficulty: Hard
 * Tags: Backtracking, DFS, Pruning
 * URL: https://onlinejudge.org/external/3/307.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given several cut stick segments, find the minimum possible original length of the uncut sticks such that all sticks were initially of equal length.
 *
 * [中文] 題目概述:
 *     給定若干被切斷的小木棍長度，求原始小木棍在長度均相等的情況下的最小可能原長度。
 *
 * [EN] Approach:
 *     Sort descending. Candidate original length L must divide total length and L >= max_len. Backtrack with aggressive pruning.
 * [中文] 解題思路:
 *     降序排序，原始長度 L 必為總和的因數且 L >= 最大長度。進行強力剪枝的回溯搜尋。
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

static int cmp307(const void *a, const void *b) { return (*(int*)b - *(int*)a); }

int dfs_sticks(int *sticks, int n, int *used, int target, int cur, int idx, int left_len) {
    if (left_len == 0) return 1;
    if (cur == target) return dfs_sticks(sticks, n, used, target, 0, 0, left_len);
    for (int i = idx; i < n; i++) {
        if (!used[i] && cur + sticks[i] <= target) {
            used[i] = 1;
            if (dfs_sticks(sticks, n, used, target, cur + sticks[i], i + 1, left_len - sticks[i])) return 1;
            used[i] = 0;
            if (cur == 0 || cur + sticks[i] == target) return 0;
            while (i + 1 < n && sticks[i] == sticks[i + 1]) i++;
        }
    }
    return 0;
}

int min_stick_len(int n, int *sticks) {
    int sum = 0, mx = 0;
    qsort(sticks, n, sizeof(int), cmp307);
    for (int i = 0; i < n; i++) { sum += sticks[i]; if (sticks[i] > mx) mx = sticks[i]; }
    int used[64] = {0};
    for (int l = mx; l <= sum; l++) {
        if (sum % l == 0) {
            memset(used, 0, sizeof(used));
            if (dfs_sticks(sticks, n, used, l, 0, 0, sum)) return l;
        }
    }
    return sum;
}

int main(void) {
    int s[] = {5, 2, 1, 5, 2, 1, 5, 2, 1}; // sum=24, mx=5, length 6
    int res = min_stick_len(9, s);
    int ok = (res == 6);
    printf("%s: UVa 307 - Sticks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
