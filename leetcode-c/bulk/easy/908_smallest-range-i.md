# 0908. Smallest Range I《最小範圍 I》

- **Difficulty**: Easy
- **Tags**: array, math
- **題目連結**: https://leetcode.com/problems/smallest-range-i/
- **程式碼**: [`908_smallest-range-i.c`](./908_smallest-range-i.c) — 社群解答（repo ourhouchmohamed97_LeetCode_in_C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

對 nums 的每個元素最多可操作一次，將其加上一個介於 −k 與 k 的整數。分數定義為最大值與最小值之差，回傳操作後可得到的最小分數。

**思路**：程式掃描取得原陣列最小值與最大值，分別向內調整 k。若調整後區間交疊則答案為 0，否則回傳 max−min−2k。

## Problem Statement (English)

You are given an integer array nums and an integer k.
In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.
The score of nums is the difference between the maximum and minimum elements in nums.
Return the minimum score of nums after applying the mentioned operation at most once for each index in it.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.

Input: nums = [0,10], k = 2
Output: 6
Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.

Input: nums = [1,3,6], k = 3
Output: 0
Explanation: Change nums to be [4, 4, 4]. The score is max(nums) - min(nums) = 4 - 4 = 0.
```

## 限制 Constraints

1 <= nums.length <= 104
0 <= nums[i] <= 104
0 <= k <= 104

## 官方 C 函式簽名 Signature

```c
int smallestRangeI(int* nums, int numsSize, int k) {
    
}
```
