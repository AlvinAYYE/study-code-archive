/*
 * ==========================================================================
 * LeetCode 084. Largest Rectangle in Histogram
 * Title-CN: 柱狀圖中最大的矩形
 * Difficulty: Hard
 * Tags: array, stack, monotonic-stack
 * URL: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an array of integers heights representing the histogram's bar
 *     height where the width of each bar is 1, return the area of the largest
 *     rectangle in the histogram.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給長寬皆為 1 的柱子高度，求柱狀圖中能框出的最大矩形面積。
 *
 * Examples:
 *   Example 1:
 *     Input: heights = [2,1,5,6,2,3]
 *     Output: 10
 *     Explanation: The above is a histogram where width of each bar is
 *     1.
 *     The largest rectangle is shown in the red area, which has an area
 *     = 10 units.
 *   Example 2:
 *     Input: heights = [2,4]
 *     Output: 4
 *
 * Constraints:
 *   - 1 <= heights.length <= 10^5
 *   - 0 <= heights[i] <= 10^4
 *
 * LeetCode official C stub (函式簽名):
 *   int largestRectangleArea(int* heights, int heightsSize) {
 *   }
 *
 * [EN] Approach: Monotonic increasing stack of indices: when a bar ends a taller run, pop and compute height*(right-left-1); sentinel zeros at both ends. Time O(n).
 * [中文] 思路: 單調遞增棧存下標：新柱較矮時弹出更高的柱，面積=高×(右界-左界-1)，兩端補 0 哨兵。時間 O(n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int largestRectangleArea(int *heights, int heightsSize) {
    int *st = (int *)malloc((size_t)(heightsSize + 1) * sizeof(int));
    int top = 0, i, best = 0;
    for (i = 0; i <= heightsSize; ++i) {
        int h = (i == heightsSize) ? 0 : heights[i];   /* 0 sentinel flushes stack */
        while (top > 0 && h < heights[st[top - 1]]) {
            int hh = heights[st[--top]];
            int w = (top > 0) ? i - st[top - 1] - 1 : i;
            if (hh * w > best) best = hh * w;
        }
        st[top++] = i;
    }
    free(st);
    return best;
}
/* ---------- end submission ---------- */

static int check(int *a, int n, int expect) {
    int got = largestRectangleArea(a, n);
    if (got != expect) { printf("  fail: got %d want %d\n", got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    int a1[] = {2, 1, 5, 6, 2, 3};
    ok = ok && check(a1, 6, 10);
    int a2[] = {1000, 1000, 1000};
    ok = ok && check(a2, 3, 3000);
    int a3[] = {2, 4};
    ok = ok && check(a3, 2, 4);
    int a4[] = {2, 1, 2};
    ok = ok && check(a4, 3, 3);
    printf("%s: 084 largest-rectangle-in-histogram\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
