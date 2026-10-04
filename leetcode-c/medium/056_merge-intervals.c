/*
 * ==========================================================================
 * LeetCode 056. Merge Intervals
 * Title-CN: 合併區間
 * Difficulty: Medium
 * Tags: array, sorting
 * URL: https://leetcode.com/problems/merge-intervals/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an array of intervals where intervals[i] = [starti, endi], merge
 *     all overlapping intervals, and return an array of the non-overlapping
 *     intervals that cover all the intervals in the input.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     合併所有重疊區間並回傳不重疊區間集合。
 *
 * Examples:
 *   Example 1:
 *     Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 *     Output: [[1,6],[8,10],[15,18]]
 *     Explanation: Since intervals [1,3] and [2,6] overlap, merge them
 *     into [1,6].
 *   Example 2:
 *     Input: intervals = [[1,4],[4,5]]
 *     Output: [[1,5]]
 *     Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 * Constraints:
 *   - 1 <= intervals.length <= 10^4
 *   - intervals[i].length == 2
 *   - 0 <= starti <= endi <= 10^4
 *
 * LeetCode official C stub (函式簽名):
 *   int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [EN] Approach: Sort by start, then greedily extend the current interval while it overlaps. Time O(n log n), space O(1) extra.
 * [中文] 思路: 依起點排序後依序貪心：若與當前區間重疊就延伸右端點，否則新開一段。時間 O(n log n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static int cmpIv(const void *a, const void *b) {
    const int *x = *(const int * const *)a, *y = *(const int * const *)b;
    if (x[0] != y[0]) return x[0] < y[0] ? -1 : 1;
    return x[1] < y[1] ? -1 : (x[1] > y[1] ? 1 : 0);
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
            int *returnSize, int **returnColumnSizes) {
    int **out; int *cols; int cnt = 0, i;
    (void)intervalsColSize;
    qsort(intervals, (size_t)intervalsSize, sizeof(int *), cmpIv);
    out  = (int **)malloc((size_t)intervalsSize * sizeof(int *));
    cols = (int *)malloc((size_t)intervalsSize * sizeof(int));
    for (i = 0; i < intervalsSize; ++i) {
        if (cnt && intervals[i][0] <= out[cnt - 1][1]) {      /* overlaps last */
            if (intervals[i][1] > out[cnt - 1][1]) out[cnt - 1][1] = intervals[i][1];
        } else {
            out[cnt] = (int *)malloc(2 * sizeof(int));
            out[cnt][0] = intervals[i][0];
            out[cnt][1] = intervals[i][1];
            cols[cnt] = 2;
            cnt++;
        }
    }
    *returnSize = cnt;
    *returnColumnSizes = cols;
    return out;
}
/* ---------- end submission ---------- */

static int check(int pairs[][2], int n, int ef[][2], int en) {
    int **ivs; int *colsz = NULL; int rs = 0, i; int **got;
    ivs = (int **)malloc((size_t)n * sizeof(int *));
    for (i = 0; i < n; ++i) ivs[i] = pairs[i];
    got = merge(ivs, n, NULL, &rs, &colsz);
    if (rs != en) { printf("  fail: got %d rows want %d\n", rs, en); return 0; }
    for (i = 0; i < rs; ++i)
        if (colsz[i] != 2 || got[i][0] != ef[i][0] || got[i][1] != ef[i][1]) {
            printf("  fail row %d: [%d,%d]\n", i, got[i][0], got[i][1]);
            return 0;
        }
    free(ivs); free(colsz);
    return 1;
}

int main(void) {
    int ok = 1;
    int a1[4][2] = {{1,3},{2,6},{8,10},{15,18}};
    int e1[3][2] = {{1,6},{8,10},{15,18}};
    ok = ok && check(a1, 4, e1, 3);
    int a2[2][2] = {{1,4},{4,5}};
    int e2[1][2] = {{1,5}};
    ok = ok && check(a2, 2, e2, 1);
    int a3[4][2] = {{1,4},{0,4},{2,3},{5,9}};
    int e3[2][2] = {{0,4},{5,9}};
    ok = ok && check(a3, 4, e3, 2);
    printf("%s: 056 merge-intervals\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
