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
 *     給定 n 個非負整數 height，代表每根寬度皆為 1 的柱子高度。
 *     請計算下雨後，這張高度圖總共能接住多少單位的雨水。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 *     輸出：6
 *     說明：各凹槽累計可接住 6 單位的雨水。
 *   範例 2：
 *     輸入：height = [4,2,0,3,2,5]
 *     輸出：9
 *
 * [中文] 限制：
 *   - n == height.length
 *   - 1 <= n <= 2 * 10^4
 *   - 0 <= height[i] <= 10^5
 *
 * LeetCode official C stub (函式簽名):
 *   int trap(int* height, int heightSize) {
 *   }
 *
 * [EN] Approach: Two pointers with running leftMax/rightMax: water at i = min(leftMax,rightMax)-h[i], decided by the lower side. Time O(n), space O(1).
 * [中文] 直觀解題思路：
 *   1. 位置 i 能裝的水量由左右兩側最高柱中較矮者決定：
 *      min(左側最高, 右側最高) - height[i]。
 *   2. 用 l、r 從兩端往中間走，並維護已看過的 leftMax、rightMax。
 *   3. 當 height[l] < height[r] 時，右邊至少有 height[r] 這面牆，因此
 *      左端水位可由 leftMax 安全決定；更新或結算 l 後將它右移。
 *   4. 其餘情況同理從右端結算。每個位置只會被處理一次。
 *
 * 複雜度：時間 O(n)，額外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int trap(int *height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int leftMax = 0, rightMax = 0, water = 0;
    while (l < r) {
        /* 較矮的一端已有另一端作為邊界，可以立刻確定該位置的積水量。 */
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
