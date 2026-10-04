# 0189. Rotate Array《旋轉陣列》

- **Difficulty**: Medium
- **Tags**: array, math, two-pointers
- **題目連結**: https://leetcode.com/problems/rotate-array/
- **程式碼**: [`189_rotate-array.c`](./189_rotate-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與非負整數 k，請將陣列向右旋轉 k 步。k 可能大於陣列長度，元素值可為負數。

**思路**：依 (目前索引 + k) mod n 進行循環置換，沿著一個環搬移元素；每當回到該環起點時，改由下一個尚未處理的起點繼續。

## Problem Statement (English)

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Example 1:
Example 2:
Constraints:
Follow up:

## 範例 Examples

```text
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

## 限制 Constraints

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105

## 官方 C 函式簽名 Signature

```c
void rotate(int* nums, int numsSize, int k) {
    
}
```
