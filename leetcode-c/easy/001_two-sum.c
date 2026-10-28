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
 *     給定整數陣列 nums 與整數 target，請找出陣列中兩個相加等於
 *     target 的元素，並回傳它們的索引。每筆輸入恰好有一組答案，
 *     同一個元素不能重複使用；兩個索引的回傳順序不限。
 *
 * [中文] 範例
 *     1. nums = [2,7,11,15]、target = 9，輸出 [0,1]，因為 2 + 7 = 9。
 *     2. nums = [3,2,4]、target = 6，輸出 [1,2]。
 *     3. nums = [3,3]、target = 6，輸出 [0,1]。
 *
 * [中文] 限制
 *     - 2 <= nums.length <= 10^4
 *     - -10^9 <= nums[i], target <= 10^9
 *     - 恰好存在一組有效答案。
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
 * [中文] 直觀解題思路
 *     1. 走到 nums[i] 時，需要的另一個數是 target - nums[i]。
 *     2. 先到雜湊表查這個數。若已出現，表中索引與 i 就是答案。
 *     3. 若尚未出現，再把 nums[i] 與索引 i 存入表中；先查再存可避免
 *        同一元素被使用兩次，也能正確處理 [3,3] 這類重複值。
 *     4. 雜湊表使用線性探測處理碰撞，平均時間 O(n)，額外空間 O(n)。
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
    int *keys, *pos;
    *returnSize = 0;

    /* 容量維持為 2 的次方且至少是元素數的兩倍，降低碰撞機率。 */
    while (cap < numsSize * 2) cap <<= 1;
    keys = (int *)malloc((size_t)cap * sizeof(int));
    pos  = (int *)calloc((size_t)cap, sizeof(int));   /* 0 = empty, else idx+1 */
    for (i = 0; i < numsSize; ++i) {
        int need = target - nums[i];

        /* 先尋找互補值，確保目前元素不會與自己配對。 */
        h = (int)(hashu(need) & (unsigned)(cap - 1));
        while (pos[h] && keys[h] != need) h = (h + 1) & (cap - 1);
        if (pos[h]) {
            int *ans = (int *)malloc(2 * sizeof(int));
            ans[0] = pos[h] - 1;
            ans[1] = i;
            *returnSize = 2;
            free(keys);
            free(pos);
            return ans;
        }

        /* pos 存 index + 1，讓 0 可以代表此槽尚未使用。 */
        h = (int)(hashu(nums[i]) & (unsigned)(cap - 1));
        while (pos[h] && keys[h] != nums[i]) h = (h + 1) & (cap - 1);
        if (!pos[h]) { keys[h] = nums[i]; pos[h] = i + 1; }
    }
    free(keys);
    free(pos);
    return NULL;  /* 題目保證有解，此分支只是讓函式行為完整。 */
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
