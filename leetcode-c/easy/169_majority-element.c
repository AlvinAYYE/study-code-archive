/*
 * ==========================================================================
 * LeetCode 169. Majority Element
 * Title-CN: 多數元素
 * Difficulty: Easy
 * Tags: array, hash-table, divide-and-conquer, sorting, counting
 * URL: https://leetcode.com/problems/majority-element/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an array nums of size n, return the majority element.
 *     The majority element is the element that appears more than ⌊n / 2⌋
 *     times. You may assume that the majority element always exists in the
 *     array.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定長度為 n 的整數陣列 nums，回傳其中的多數元素。多數元素是出現
 *     次數嚴格大於 floor(n / 2) 的元素，題目保證它一定存在。
 *
 * [中文] 範例
 *     1. nums = [3,2,3]，輸出 3。
 *     2. nums = [2,2,1,1,1,2,2]，輸出 2。
 *
 * [中文] 限制
 *     - n == nums.length
 *     - 1 <= n <= 5 * 10^4
 *     - -10^9 <= nums[i] <= 10^9
 *
 * Examples:
 *   Example 1:
 *     Input: nums = [3,2,3]
 *     Output: 3
 *   Example 2:
 *     Input: nums = [2,2,1,1,1,2,2]
 *     Output: 2
 *
 * Constraints:
 *   - n == nums.length
 *   - 1 <= n <= 5 * 10^4
 *   - -10^9 <= nums[i] <= 10^9
 *
 * LeetCode official C stub (函式簽名):
 *   int majorityElement(int* nums, int numsSize) {
 *   }
 *
 * [EN] Approach: Boyer-Moore voting: keep a candidate + counter; same value increments, different decrements, replace when counter hits 0. Time O(n), space O(1).
 * [中文] 直觀解題思路
 *     1. 把一個候選多數元素與一個不同元素配成一組並抵銷。真正的多數元素
 *        比所有其他元素加起來還多，所以反覆抵銷後一定仍會留下。
 *     2. count 為 0 時，以目前元素作為新候選人；遇到相同值就加 1，遇到
 *        不同值就減 1。
 *     3. 題目保證多數元素存在，因此最後的候選人就是答案，不需第二次驗證。
 *        時間 O(n)，額外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int majorityElement(int *nums, int numsSize) {
    int cand = 0, count = 0, i;
    for (i = 0; i < numsSize; ++i) {
        /* 計數歸零表示先前候選人已被其他元素完全抵銷。 */
        if (count == 0) { cand = nums[i]; count = 1; }
        else if (nums[i] == cand) count++;
        else count--;
    }
    return cand;
}
/* ---------- end submission ---------- */

static int check(int *a, int n, int expect) {
    int got = majorityElement(a, n);
    if (got != expect) { printf("  fail: got %d want %d\n", got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    int a1[] = {3, 2, 3};
    ok = ok && check(a1, 3, 3);
    int a2[] = {2, 2, 1, 1, 1, 2, 2};
    ok = ok && check(a2, 7, 2);
    int a3[] = {6, 5, 5};
    ok = ok && check(a3, 3, 5);
    printf("%s: 169 majority-element\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
