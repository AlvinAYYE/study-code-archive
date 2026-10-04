/*
 * ==========================================================================
 * LeetCode 042. Trapping Rain Water
 * Title-CN: 接雨水
 * Difficulty: Hard
 * Tags: array, two-pointers, dynamic-programming, stack, monotonic-stack
 * URL: https://leetcode.com/problems/trapping-rain-water/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given n non-negative integers representing an elevation map where the
 *     width of each bar is 1, compute how much water it can trap after
 *     raining.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給高度陣列，計算降雨後能滯留的總水量。
 *
 * Examples:
 *   Example 1:
 *     Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 *     Output: 6
 *     Explanation: The above elevation map (black section) is
 *     represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6
 *     units of rain water (blue section) are being trapped.
 *   Example 2:
 *     Input: height = [4,2,0,3,2,5]
 *     Output: 9
 *
 * Constraints:
 *   - n == height.length
 *   - 1 <= n <= 2 * 10^4
 *   - 0 <= height[i] <= 10^5
 *
 * LeetCode official C stub (函式簽名):
 *   int trap(int* height, int heightSize) {
 *   }
 *
 * [EN] Approach: Two pointers with running leftMax/rightMax: water at i = min(leftMax,rightMax)-h[i], decided by the lower side. Time O(n), space O(1).
 * [中文] 思路: 雙指針+兩側最高柱：每列積水 = min(左最大, 右最大)-當前高，由較矮的一側決定。時間 O(n)、空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int trap(int *height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int leftMax = 0, rightMax = 0, water = 0;
    while (l < r) {
        if (height[l] < height[r]) {
            if (height[l] >= leftMax) leftMax = height[l];
            else water += leftMax - height[l];
            ++l;
        } else {
            if (height[r] >= rightMax) rightMax = height[r];
            else water += rightMax - height[r];
            --r;
        }
    }
    return water;
}
/* ---------- end submission ---------- */

static int check(int *a, int n, int expect) {
    int got = trap(a, n);
    if (got != expect) { printf("  fail: got %d want %d\n", got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    int a1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    ok = ok && check(a1, 12, 6);
    int a2[] = {4, 2, 0, 3, 2, 5};
    ok = ok && check(a2, 6, 9);
    int a3[] = {1, 2, 3};
    ok = ok && check(a3, 3, 0);
    printf("%s: 042 trapping-rain-water\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
