# 0041. First Missing Positive《缺失的第一個正數》

- **Difficulty**: Hard
- **Tags**: array, hash-table
- **題目連結**: https://leetcode.com/problems/first-missing-positive/
- **程式碼**: [`041_first-missing-positive.c`](./041_first-missing-positive.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定未排序整數陣列 nums，回傳其中未出現的最小正整數。必須在 O(n) 時間與 O(1) 額外空間內完成。

**思路**：逐一把可用的正數交換到值減一所對應的位置，讓數字 x 盡量放在索引 x - 1。接著掃描第一個 nums[i] 不等於 i + 1 的位置，即可得答案。

## Problem Statement (English)

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
```

## 限制 Constraints

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int firstMissingPositive(int* nums, int numsSize) {
    
}
```
