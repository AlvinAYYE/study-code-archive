# 0228. Summary Ranges《彙總區間》

- **Difficulty**: Easy
- **Tags**: array
- **題目連結**: https://leetcode.com/problems/summary-ranges/
- **程式碼**: [`228_summary-ranges.c`](./228_summary-ranges.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定已遞增排序且元素互異的整數陣列 nums，回傳最小的區間列表以剛好涵蓋所有元素。單一數字輸出為數字字串，連續區間則輸出為 "起點->終點"，不可涵蓋陣列中不存在的數字。

**思路**：每次從目前開頭向後找出最長的連續遞增段，格式化成一個區間字串。接著對剩餘後綴遞迴重複處理。

## Problem Statement (English)

You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
```

## 限制 Constraints

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    
}
```
