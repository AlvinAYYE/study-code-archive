# 0215. Kth Largest Element in an Array《陣列中的第 K 大元素》

- **Difficulty**: Medium
- **Tags**: array, divide-and-conquer, sorting, heap-(priority-queue, quickselect
- **題目連結**: https://leetcode.com/problems/kth-largest-element-in-an-array/
- **程式碼**: [`215_kth-largest-element-in-an-array.c`](./215_kth-largest-element-in-an-array.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與整數 k，找出陣列排序後的第 k 大元素，而非第 k 個相異元素。題目進一步要求嘗試在不完整排序陣列的情況下完成。

**思路**：以首元素為樞紐進行由大到小的快速選擇分割，讓樞紐歸位。遞迴只進入包含目標索引 k - 1 的那一側。

## Problem Statement (English)

Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

## 限制 Constraints

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

## 官方 C 函式簽名 Signature

```c
int findKthLargest(int* nums, int numsSize, int k) {
    
}
```
