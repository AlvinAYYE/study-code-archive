/*
 * ==========================================================================
 * LeetCode 136. Single Number
 * Title-CN: 只出現一次的數字
 * Difficulty: Easy
 * Tags: array, bit-manipulation
 * URL: https://leetcode.com/problems/single-number/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given a non-empty array of integers nums, every element appears twice
 *     except for one. Find that single one.
 *     You must implement a solution with a linear runtime complexity and use
 *     only constant extra space.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     陣列中每個元素都出現兩次，唯有一個出現一次，找出它（要求 O(n)
 *     時間、O(1) 空間）。
 *
 * Examples:
 *   Example 1:
 *     Input: nums = [2,2,1]
 *     Output: 1
 *   Example 2:
 *     Input: nums = [4,1,2,1,2]
 *     Output: 4
 *   Example 3:
 *     Input: nums = [1]
 *     Output: 1
 *
 * Constraints:
 *   - 1 <= nums.length <= 3 * 10^4
 *   - -3 * 10^4 <= nums[i] <= 3 * 10^4
 *   - Each element in the array appears twice except for one element
 *   which appears only once.
 *
 * LeetCode official C stub (函式簽名):
 *   int singleNumber(int* nums, int numsSize) {
 *   }
 *
 * [EN] Approach: XOR all numbers: x^x=0 and 0^y=y, so pairs cancel and the singleton survives. Time O(n), space O(1).
 * [中文] 思路: 全部 XOR：x^x=0、0^y=y，成對元素互相抵銷，剩下的就是答案。時間 O(n)、空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int singleNumber(int *nums, int numsSize) {
    int x = 0, i;
    for (i = 0; i < numsSize; ++i) x ^= nums[i];
    return x;
}
/* ---------- end submission ---------- */

static int check(int *a, int n, int expect) {
    int got = singleNumber(a, n);
    if (got != expect) { printf("  fail: got %d want %d\n", got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    int a1[] = {2, 2, 1};
    ok = ok && check(a1, 3, 1);
    int a2[] = {4, 1, 2, 1, 2};
    ok = ok && check(a2, 5, 4);
    int a3[] = {1};
    ok = ok && check(a3, 1, 1);
    printf("%s: 136 single-number\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
