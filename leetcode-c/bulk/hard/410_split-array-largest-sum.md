# 0410. Split Array Largest Sum《分割陣列的最大和》

- **Difficulty**: Hard
- **Tags**: array, binary-search, dynamic-programming, greedy, prefix-sum
- **題目連結**: https://leetcode.com/problems/split-array-largest-sum/
- **程式碼**: [`410_split-array-largest-sum.c`](./410_split-array-largest-sum.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非負整數陣列 nums 與 k，將陣列切成恰好 k 個非空且連續的子陣列。請最小化各子陣列總和中的最大值，並回傳該最小值。

**思路**：預先計算各起點到結尾的後綴和，並以記憶化遞迴枚舉第一段的結尾。每種切法取第一段總和與其餘段最佳值的較大者，再取所有切法的最小值。

## Problem Statement (English)

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
```

## 限制 Constraints

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)

## 官方 C 函式簽名 Signature

```c
int splitArray(int* nums, int numsSize, int k) {
    
}
```
