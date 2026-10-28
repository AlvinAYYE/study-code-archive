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
 *     給定整數陣列 heights，heights[i] 代表柱狀圖第 i 根柱子的高度，
 *     每根柱子的寬度皆為 1。請回傳柱狀圖中可形成的最大矩形面積。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入：heights = [2,1,5,6,2,3]
 *     輸出：10
 *     說明：高度 5、6 的兩根相鄰柱子可形成高 5、寬 2、面積 10 的矩形。
 *   範例 2：
 *     輸入：heights = [2,4]
 *     輸出：4
 *
 * [中文] 限制：
 *   - 1 <= heights.length <= 10^5
 *   - 0 <= heights[i] <= 10^4
 *
 * LeetCode official C stub (函式簽名):
 *   int largestRectangleArea(int* heights, int heightsSize) {
 *   }
 *
 * [EN] Approach: Monotonic increasing stack of indices: when a bar ends a taller run, pop and compute height*(right-left-1); sentinel zeros at both ends. Time O(n).
 * [中文] 直觀解題思路：
 *   1. 對每根柱子，若能找到左右第一根比它矮的柱子，就知道以它為高度
 *      的矩形能延伸多寬。但逐根向左右找會退化為 O(n^2)。
 *   2. 用堆疊保存高度非遞減的柱子下標。遇到更矮的新柱時，代表堆疊頂端
 *      那根柱子的右界已確定，可以彈出並立即計算面積。
 *   3. 彈出後，新堆疊頂端是它左邊第一根更矮的柱子；目前下標 i 是右邊
 *      第一根更矮的柱子，所以寬度為 i - 左界下標 - 1。若堆疊已空，
 *      表示可一路延伸至下標 0，寬度就是 i。
 *   4. 在陣列尾端視為補上一根高度 0 的哨兵，強制結算堆疊內所有柱子。
 *
 * 複雜度：每個下標最多進出堆疊各一次，時間 O(n)，額外空間 O(n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int largestRectangleArea(int *heights, int heightsSize) {
    int *st = (int *)malloc((size_t)(heightsSize + 1) * sizeof(int));
    int top = 0, i, best = 0;
    for (i = 0; i <= heightsSize; ++i) {
        int h = (i == heightsSize) ? 0 : heights[i];   /* 尾端 0 哨兵清空堆疊 */
        while (top > 0 && h < heights[st[top - 1]]) {
            int hh = heights[st[--top]];
            /* 彈出後的堆疊頂是左界，i 是右界；兩個邊界本身都不納入。 */
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
