/*
 * ==========================================================================
 * LeetCode 239. Sliding Window Maximum
 * Title-CN: 滑動視窗最大值
 * Difficulty: Hard
 * Tags: array, queue, sliding-window, heap-priority-queue, monotonic-queue
 * URL: https://leetcode.com/problems/sliding-window-maximum/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     You are given an array of integers nums, there is a sliding window of
 *     size k which is moving from the very left of the array to the very
 *     right. You can only see the k numbers in the window. Each time the
 *     sliding window moves right by one position.
 *     Return the max sliding window.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定陣列與窗口大小 k，回傳窗口從左滑到右每個位置的最大值。
 *
 * Examples:
 *   Example 1:
 *     Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 *     Output: [3,3,5,5,6,7]
 *     Explanation:
 *     Window position Max
 *     --------------- -----
 *     [1 3 -1] -3 5 3 6 7 3
 *     1 [3 -1 -3] 5 3 6 7 3
 *     1 3 [-1 -3 5] 3 6 7 5
 *     1 3 -1 [-3 5 3] 6 7 5
 *     1 3 -1 -3 [5 3 6] 7 6
 *     1 3 -1 -3 5 [3 6 7] 7
 *   Example 2:
 *     Input: nums = [1], k = 1
 *     Output: [1]
 *
 * Constraints:
 *   - 1 <= nums.length <= 10^5
 *   - -10^4 <= nums[i] <= 10^4
 *   - 1 <= k <= nums.length
 *
 * LeetCode official C stub (函式簽名):
 *   int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
 *   }
 *
 * [EN] Approach: Monotonic decreasing deque of indices: drop out-of-window and dominated entries from the back/front; front is the max. Time O(n).
 * [中文] 思路: 單調遞減雙端隊列存下標：過舊的與比新元素小的直接丟掉，隊首即視窗最大值。時間 O(n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize) {
    int *out, *dq, head = 0, tail = 0, i;
    *returnSize = numsSize - k + 1;
    out = (int *)malloc((size_t)*returnSize * sizeof(int));
    dq  = (int *)malloc((size_t)numsSize * sizeof(int));   /* stores indices */
    for (i = 0; i < numsSize; ++i) {
        if (head < tail && dq[head] <= i - k) head++;               /* drop expired */
        while (head < tail && nums[dq[tail - 1]] <= nums[i]) tail--; /* drop dominated */
        dq[tail++] = i;
        if (i >= k - 1) out[i - k + 1] = nums[dq[head]];             /* front = max */
    }
    free(dq);
    return out;
}
/* ---------- end submission ---------- */

static int check(int *a, int n, int k, const int *expect, int en) {
    int rs = 0, i, *got = maxSlidingWindow(a, n, k, &rs);
    int ok = (rs == en);
    for (i = 0; ok && i < en; ++i) if (got[i] != expect[i]) ok = 0;
    if (!ok) printf("  fail: k=%d got %d rows\n", k, rs);
    free(got);
    return ok;
}

int main(void) {
    int ok = 1;
    int a1[] = {1, 3, -1, -3, 5, 3, 6, 7};
    const int e1[] = {3, 3, 5, 5, 6, 7};
    ok = ok && check(a1, 8, 3, e1, 6);
    int a2[] = {1};
    ok = ok && check(a2, 1, 1, (const int *)a2, 1);
    int a3[] = {1, -1};
    ok = ok && check(a3, 2, 1, a3, 2);
    int a4[] = {9, 11, 9, 7, 4, 6, 8, 4, 6, 5, 4, 9, 0, 1};
    const int e4[] = {11, 11, 9, 7, 8, 8, 8, 6, 6, 9, 9, 9};
    ok = ok && check(a4, 14, 3, e4, 12);
    printf("%s: 239 sliding-window-maximum\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
