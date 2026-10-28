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
 *     給定整數陣列 nums，以及一個大小為 k、起初位於陣列最左端的滑動
 *     視窗。每次將視窗向右移動一格，期間只能看到視窗內的 k 個數字。
 *     請回傳視窗位於每個位置時的最大值。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 *     輸出：[3,3,5,5,6,7]
 *     說明：六個視窗依序為 [1,3,-1]、[3,-1,-3]、[-1,-3,5]、
 *           [-3,5,3]、[5,3,6]、[3,6,7]，最大值如輸出所示。
 *   範例 2：
 *     輸入：nums = [1], k = 1
 *     輸出：[1]
 *
 * [中文] 限制：
 *   - 1 <= nums.length <= 10^5
 *   - -10^4 <= nums[i] <= 10^4
 *   - 1 <= k <= nums.length
 *
 * LeetCode official C stub (函式簽名):
 *   int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
 *   }
 *
 * [EN] Approach: Monotonic decreasing deque of indices: drop out-of-window and dominated entries from the back/front; front is the max. Time O(n).
 * [中文] 直觀解題思路：
 *   1. 雙端佇列 dq 存「下標」，並讓對應數值由隊首到隊尾維持非遞增；
 *      因此隊首永遠是目前視窗最大值的下標。
 *   2. 處理 nums[i] 前，若隊首下標 <= i-k，表示它已離開視窗，將它移除。
 *   3. 從隊尾移除所有小於或等於 nums[i] 的元素。新元素更大、離開視窗
 *      的時間也更晚，這些舊元素不可能再成為任何後續視窗的最大值。
 *   4. 將 i 加入隊尾；當第一個完整視窗形成後，把隊首數值寫入答案。
 *
 * 複雜度：每個下標最多進出佇列各一次，時間 O(n)，額外空間 O(n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize) {
    int *out, *dq, head = 0, tail = 0, i;
    *returnSize = numsSize - k + 1;
    out = (int *)malloc((size_t)*returnSize * sizeof(int));
    dq  = (int *)malloc((size_t)numsSize * sizeof(int));   /* 存下標而非數值 */
    for (i = 0; i < numsSize; ++i) {
        if (head < tail && dq[head] <= i - k) head++;               /* 移除過期下標 */
        /* 較小或相等的舊值已不可能成為之後的最大值。 */
        while (head < tail && nums[dq[tail - 1]] <= nums[i]) tail--;
        dq[tail++] = i;
        if (i >= k - 1) out[i - k + 1] = nums[dq[head]];             /* 隊首即最大值 */
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
