/*
 * ==========================================================================
 * LeetCode 001. Two Sum
 * Title-CN: 兩數之和
 * Difficulty: Easy
 * Tags: array, hash-table
 * URL: https://leetcode.com/problems/two-sum/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an array of integers nums and an integer target, return indices of
 *     the two numbers such that they add up to target.
 *     You may assume that each input would have exactly one solution, and you
 *     may not use the same element twice.
 *     You can return the answer in any order.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定整數陣列 nums 與整數 target，找出兩數之和等於 target
 *     的兩個下標並回傳（保證恰有一組解）。
 *
 * Examples:
 *   Example 1:
 *     Input: nums = [2,7,11,15], target = 9
 *     Output: [0,1]
 *     Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *   Example 2:
 *     Input: nums = [3,2,4], target = 6
 *     Output: [1,2]
 *   Example 3:
 *     Input: nums = [3,3], target = 6
 *     Output: [0,1]
 *
 * Constraints:
 *   - 2 <= nums.length <= 10^4
 *   - -10^9 <= nums[i] <= 10^9
 *   - -10^9 <= target <= 10^9
 *   - Only one valid answer exists.
 *
 * LeetCode official C stub (函式簽名):
 *   int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
 *   }
 *
 * [EN] Approach: One-pass hash table (open addressing): for each x look up target-x first, then insert x. Time O(n), space O(n).
 * [中文] 思路: 單遍雜湊表(開放定址)：掃描每個 x 時先查 target-x 是否已出現，再存入 x。時間 O(n)、空間 O(n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static unsigned hashu(int x) {
    unsigned u = (unsigned)x;
    u ^= u >> 16; u *= 0x7feb352dU;
    u ^= u >> 15; u *= 0x846ca68bU;
    u ^= u >> 16;
    return u;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int cap = 4, i, h;
    int *keys, *pos, *ans;
    while (cap < numsSize * 2) cap <<= 1;
    keys = (int *)malloc((size_t)cap * sizeof(int));
    pos  = (int *)calloc((size_t)cap, sizeof(int));   /* 0 = empty, else idx+1 */
    ans  = (int *)malloc(2 * sizeof(int));
    for (i = 0; i < numsSize; ++i) {
        int need = target - nums[i];
        h = (int)(hashu(need) & (unsigned)(cap - 1));
        while (pos[h] && keys[h] != need) h = (h + 1) & (cap - 1);
        if (pos[h]) {                      /* complement found */
            *returnSize = 2; ans[0] = pos[h] - 1; ans[1] = i;
            free(keys); free(pos); return ans;
        }
        h = (int)(hashu(nums[i]) & (unsigned)(cap - 1));
        while (pos[h] && keys[h] != nums[i]) h = (h + 1) & (cap - 1);
        if (!pos[h]) { keys[h] = nums[i]; pos[h] = i + 1; }
    }
    *returnSize = 0;
    free(keys); free(pos);
    return ans;
}
/* ---------- end submission ---------- */

int main(void) {
    int ok = 1, rs, *r;
    int n1[] = {2, 7, 11, 15};
    r = twoSum(n1, 4, 9, &rs); ok = ok && rs == 2 && r[0] == 0 && r[1] == 1; free(r);
    int n2[] = {3, 2, 4};
    r = twoSum(n2, 3, 6, &rs); ok = ok && rs == 2 && ((r[0]==1&&r[1]==2)||(r[0]==2&&r[1]==1)); free(r);
    int n3[] = {3, 3};
    r = twoSum(n3, 2, 6, &rs); ok = ok && rs == 2 && r[0] == 0 && r[1] == 1; free(r);
    printf("%s: 001 two-sum\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
