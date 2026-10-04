# 0503. Next Greater Element II《下一個更大元素 II》

- **Difficulty**: Medium
- **Tags**: array, stack, monotonic-stack
- **題目連結**: https://leetcode.com/problems/next-greater-element-ii/
- **程式碼**: [`503_next-greater-element-ii.c`](./503_next-greater-element-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定環形整數陣列 nums，最後一個元素之後會接回第一個元素。對每個元素，找出走訪時遇到的第一個更大值；若不存在則為 -1。回傳所有元素的答案陣列。

**思路**：程式以存放索引的遞減堆疊做第一次完整掃描，遇到更大值就更新堆疊頂端答案。再掃描開頭到倒數第二個元素，以處理環繞後未解決的索引。

## Problem Statement (English)

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
```

## 限制 Constraints

1 <= nums.length <= 104
-109 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    
}
```
