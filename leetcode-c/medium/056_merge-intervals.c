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
 * [中文] 題目說明
 *     給定多個區間 intervals[i] = [start_i, end_i]，合併所有互相重疊的區間，
 *     回傳一組互不重疊、且完整涵蓋原輸入範圍的區間。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 *     輸出：[[1,6],[8,10],[15,18]]
 *     說明：[1,3] 與 [2,6] 重疊，因此合併成 [1,6]。
 *   範例 2：
 *     輸入：intervals = [[1,4],[4,5]]
 *     輸出：[[1,5]]
 *     說明：[1,4] 與 [4,5] 共用端點 4，仍視為重疊。
 *
 * [中文] 限制
 *   - 1 <= intervals.length <= 10^4。
 *   - intervals[i].length == 2。
 *   - 0 <= start_i <= end_i <= 10^4。
 *
 * LeetCode official C stub (函式簽名):
 *   int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 先按起點由小到大排序；如此後面的區間不可能從目前區間左側開始。
 *   2. 若下一區間的起點 <= 目前結果最後一段的終點，兩者重疊，只要把終點延伸到較大值。
 *   3. 否則兩者分離，將下一區間複製成新的結果區間。
 *   排序主導時間複雜度 O(n log n)；不計輸出，額外空間取決於 qsort 的實作。
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
        /* 排序後只需和輸出中的最後一段比較。 */
        if (cnt && intervals[i][0] <= out[cnt - 1][1]) {
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
