# 0456. 132 Pattern《132 模式》

- **Difficulty**: Medium
- **Tags**: array, binary-search, stack, monotonic-stack, ordered-set
- **題目連結**: https://leetcode.com/problems/132-pattern/
- **程式碼**: [`456_132-pattern.c`](./456_132-pattern.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，132 模式是存在 i < j < k，使 nums[i] < nums[k] < nums[j] 的三個元素所構成的子序列。若存在此模式回傳 true，否則回傳 false。

**思路**：程式枚舉中間位置 k 作為模式中的較大值，掃描其左側找出小於 nums[k] 的最小值。若右側存在介於該最小值與 nums[k] 之間的數，便找到 132 模式。

## Problem Statement (English)

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
Return true if there is a 132 pattern in nums, otherwise, return false.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
```

## 限制 Constraints

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
bool find132pattern(int* nums, int numsSize) {
    
}
```
