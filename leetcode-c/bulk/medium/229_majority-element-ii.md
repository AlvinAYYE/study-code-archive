# 0229. Majority Element II《多數元素 II》

- **Difficulty**: Medium
- **Tags**: array, hash-table, sorting, counting
- **題目連結**: https://leetcode.com/problems/majority-element-ii/
- **程式碼**: [`229_majority-element-ii.c`](./229_majority-element-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定長度為 n 的整數陣列，找出所有出現次數超過 ⌊n/3⌋ 的元素。答案最多只有兩個，追問要求以線性時間與 O(1) 額外空間完成。

**思路**：使用兩個候選值與計數器進行 Boyer-Moore 投票：新值填補空候選，否則同時抵銷。最後再次掃描陣列，驗證候選的實際次數是否超過 n/3。

## Problem Statement (English)

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you solve the problem in linear time and in O(1) space?

## 範例 Examples

```text
Input: nums = [3,2,3]
Output: [3]

Input: nums = [1]
Output: [1]

Input: nums = [1,2]
Output: [1,2]
```

## 限制 Constraints

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    
}
```
