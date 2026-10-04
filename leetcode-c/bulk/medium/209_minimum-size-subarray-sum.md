# 0209. Minimum Size Subarray Sum《長度最小的子陣列》

- **Difficulty**: Medium
- **Tags**: array, binary-search, sliding-window, prefix-sum
- **題目連結**: https://leetcode.com/problems/minimum-size-subarray-sum/
- **程式碼**: [`209_minimum-size-subarray-sum.c`](./209_minimum-size-subarray-sum.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數陣列 nums 與正整數 target，找出總和大於或等於 target 的連續子陣列最小長度。若不存在符合條件的子陣列，回傳 0。

**思路**：使用滑動視窗擴張右端累加總和；一旦總和達標，持續左移並扣除左值以縮短視窗，同時更新最小長度。

## Problem Statement (English)

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Input: target = 4, nums = [1,4,4]
Output: 1

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

## 限制 Constraints

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

## 官方 C 函式簽名 Signature

```c
int minSubArrayLen(int target, int* nums, int numsSize) {
    
}
```
