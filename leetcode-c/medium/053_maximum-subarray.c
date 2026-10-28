/*
 * ==========================================================================
 * LeetCode 053. Maximum Subarray
 * Title-CN: 最大子陣列和
 * Difficulty: Medium
 * Tags: array, divide-and-conquer, dynamic-programming
 * URL: https://leetcode.com/problems/maximum-subarray/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an integer array nums, find the subarray with the largest sum, and
 *     return its sum.
 *
 * [中文] 題目說明
 *     給定整數陣列 nums，找出總和最大的非空連續子陣列，並回傳其總和。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 *     輸出：6
 *     說明：連續子陣列 [4,-1,2,1] 的總和最大，為 6。
 *   範例 2：
 *     輸入：nums = [1]
 *     輸出：1
 *     說明：唯一的非空子陣列是 [1]。
 *   範例 3：
 *     輸入：nums = [5,4,-1,7,8]
 *     輸出：23
 *     說明：整個陣列的總和 23 最大。
 *
 * [中文] 限制
 *   - 1 <= nums.length <= 10^5。
 *   - -10^4 <= nums[i] <= 10^4。
 *
 * LeetCode official C stub (函式簽名):
 *   int maxSubArray(int* nums, int numsSize) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. cur 表示「一定以目前元素結尾」的最大子陣列總和。
 *   2. 到 nums[i] 時，可選擇延續前一段 cur + nums[i]，或丟掉前一段、從 nums[i] 重開。
 *   3. 每一步用 cur 更新全域最大值 best。
 *   初值取 nums[0]，因此即使全部是負數也能選出最大的單一元素。
 *   時間複雜度 O(n)，空間複雜度 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int maxSubArray(int *nums, int numsSize) {
    int best = nums[0], cur = nums[0], i;
    for (i = 1; i < numsSize; ++i) {
        /* 前一段若只會拖低總和，就從目前元素重新開始。 */
        cur = (cur + nums[i] > nums[i]) ? cur + nums[i] : nums[i];
        if (cur > best) best = cur;
    }
    return best;
}
/* ---------- end submission ---------- */

static int check(int *a, int n, int expect) {
    int got = maxSubArray(a, n);
    if (got != expect) { printf("  fail: got %d want %d\n", got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    int a1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    ok = ok && check(a1, 9, 6);
    int a2[] = {1};
    ok = ok && check(a2, 1, 1);
    int a3[] = {-5, -2, -9, -1, -7};
    ok = ok && check(a3, 5, -1);
    printf("%s: 053 maximum-subarray\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
