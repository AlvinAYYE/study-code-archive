# 0283. Move Zeroes《移動零》

- **Difficulty**: Easy
- **Tags**: array, two-pointers
- **題目連結**: https://leetcode.com/problems/move-zeroes/
- **程式碼**: [`283_move-zeroes.c`](./283_move-zeroes.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，請把所有 0 移到陣列尾端，同時維持所有非零元素原本的相對順序。必須原地完成，不能建立陣列副本。

**思路**：以寫入指標由左至右覆寫所有非零元素，讓它們緊密排在前方。掃描結束後，將剩餘位置全部設為 0。

## Problem Statement (English)

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Input: nums = [0]
Output: [0]
```

## 限制 Constraints

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
void moveZeroes(int* nums, int numsSize) {
    
}
```
