# 0565. Array Nesting《陣列巢狀》

- **Difficulty**: Medium
- **Tags**: array, depth-first-search
- **題目連結**: https://leetcode.com/problems/array-nesting/
- **程式碼**: [`565_array-nesting.c`](./565_array-nesting.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定長度為 n、內容為 0 到 n-1 排列的陣列 nums，從 k 開始反覆取 nums[k]、nums[nums[k]] 等值形成集合，直到重複為止。請回傳所有起點中可形成的最長集合長度。

**思路**：對每個尚未拜訪的索引沿 nums 指向的位置走訪，直到回到該循環起點，並標記經過位置及更新循環長度最大值。

## Problem Statement (English)

You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].
You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:
Return the longest length of a set s[k].
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
One of the longest sets s[k]:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}

Input: nums = [0,1,2]
Output: 1
```

## 限制 Constraints

1 <= nums.length <= 105
0 <= nums[i] < nums.length
All the values of nums are unique.

## 官方 C 函式簽名 Signature

```c
int arrayNesting(int* nums, int numsSize) {
    
}
```
