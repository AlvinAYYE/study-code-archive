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
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     在整數陣列中找出連續子陣列（至少含一個元素）的最大總和。
 *
 * Examples:
 *   Example 1:
 *     Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 *     Output: 6
 *     Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 *   Example 2:
 *     Input: nums = [1]
 *     Output: 1
 *     Explanation: The subarray [1] has the largest sum 1.
 *   Example 3:
 *     Input: nums = [5,4,-1,7,8]
 *     Output: 23
 *     Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 *
 * Constraints:
 *   - 1 <= nums.length <= 10^5
 *   - -10^4 <= nums[i] <= 10^4
 *
 * LeetCode official C stub (函式簽名):
 *   int maxSubArray(int* nums, int numsSize) {
 *   }
 *
 * [EN] Approach: Kadane: keep the best sum ending here; reset to nums[i] when the running sum goes negative. Time O(n), space O(1).
 * [中文] 思路: Kadane 演算法：維護「以當前元素結尾的最大和」，累計值變負就重置。時間 O(n)、空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int maxSubArray(int *nums, int numsSize) {
    int best = nums[0], cur = nums[0], i;
    for (i = 1; i < numsSize; ++i) {
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
