# 0697. Degree of an Array《陣列的度》

- **Difficulty**: Easy
- **Tags**: array, hash-table
- **題目連結**: https://leetcode.com/problems/degree-of-an-array/
- **程式碼**: [`697_degree-of-an-array.c`](./697_degree-of-an-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

非空非負整數陣列的度，定義為其中任一元素的最高出現次數。請找出度數與原陣列相同的最短連續子陣列長度。

**思路**：用雜湊表記錄每個值對應資料的位置，並保存其首次索引、最後索引與出現次數。最後在所有達到最大頻率的值中，取首尾跨度最短者。

## Problem Statement (English)

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
```

## 限制 Constraints

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

## 官方 C 函式簽名 Signature

```c
int findShortestSubArray(int* nums, int numsSize) {
    
}
```
