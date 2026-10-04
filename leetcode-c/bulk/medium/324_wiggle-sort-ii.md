# 0324. Wiggle Sort II《擺動排序 II》

- **Difficulty**: Medium
- **Tags**: array, divide-and-conquer, greedy, sorting, quickselect
- **題目連結**: https://leetcode.com/problems/wiggle-sort-ii/
- **程式碼**: [`324_wiggle-sort-ii.c`](./324_wiggle-sort-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，請重新排列為 nums[0] < nums[1] > nums[2] < nums[3] 的交錯關係。輸入保證至少存在一種有效排列，請原地更新 nums。

**思路**：程式先將陣列排序，再用暫存陣列交錯填入兩半：偶數索引從較小半部由後往前取，奇數索引從較大半部由後往前取。最後把暫存結果複製回 nums。

## Problem Statement (English)

Given an integer array nums, reorder it such that nums[0]  nums[2] < nums[3]....
You may assume the input array always has a valid answer.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
```

## 限制 Constraints

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
It is guaranteed that there will be an answer for the given input nums.

## 官方 C 函式簽名 Signature

```c
void wiggleSort(int* nums, int numsSize) {
    
}
```
