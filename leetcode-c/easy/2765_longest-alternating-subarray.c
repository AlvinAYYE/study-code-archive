/*
 * LeetCode 2765. Longest Alternating Subarray
 * Title-CN: 最長交替子陣列
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/longest-alternating-subarray/
 *
 * [中文] 題目說明
 *     給定 0-indexed 整數陣列 nums。連續子陣列 s 若每一步的相鄰差依序為
 *     +1、-1、+1、-1……，就稱為 alternating。例如 [3,4,3,4] 符合；
 *     子陣列至少要有兩個元素。回傳最長符合子陣列長度；若沒有，回傳 -1。
 *
 * [中文] 範例
 *     1. nums = [2,3,4,3,4]，輸出 4；[3,4,3,4] 最長。
 *     2. nums = [4,5,6]，輸出 2；[4,5] 和 [5,6] 都符合。
 *
 * [中文] 限制
 *     - 2 <= nums.length <= 100。
 *     - 1 <= nums[i] <= 10^4。
 *
 * [中文] 解題步驟
 *     1. 每個位置都可能是子陣列起點；只在下一個數比起點大 1 時開始延伸。
 *     2. 起始差為 +1 後，後續差值應依序為 -1、+1、-1；遇到不符就停止。
 *     3. 更新最長長度；遍歷所有起點後，若最長仍小於 2 回傳 -1。
 *        時間 O(n^2)，額外空間 O(1)。
 *
 * LeetCode C 函式簽名：int alternatingSubarray(int* nums, int numsSize)
 */
#include <stdio.h>

int alternatingSubarray(int *nums, int numsSize) {
    int best = 1, start;
    for (start = 0; start + 1 < numsSize; ++start) {
        int length, expectedDifference;
        if (nums[start + 1] - nums[start] != 1) continue;
        length = 2;
        expectedDifference = -1;
        while (start + length < numsSize &&
               nums[start + length] - nums[start + length - 1] == expectedDifference) {
            ++length;
            expectedDifference = -expectedDifference;
        }
        if (length > best) best = length;
    }
    return best >= 2 ? best : -1;
}

int main(void) {
    int ok = 1;
    int a[] = {2, 3, 4, 3, 4};
    int b[] = {4, 5, 6};
    int c[] = {1, 1, 1};
    int d[] = {1, 2, 1, 2, 1};
    ok = ok && alternatingSubarray(a, 5) == 4;
    ok = ok && alternatingSubarray(b, 3) == 2;
    ok = ok && alternatingSubarray(c, 3) == -1;
    ok = ok && alternatingSubarray(d, 5) == 5;
    printf("%s: 2765 longest-alternating-subarray\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
