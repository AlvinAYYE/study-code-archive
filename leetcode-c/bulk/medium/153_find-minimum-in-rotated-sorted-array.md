# 0153. Find Minimum in Rotated Sorted Array《尋找旋轉排序陣列中的最小值》

- **Difficulty**: Medium
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
- **程式碼**: [`153_find-minimum-in-rotated-sorted-array.c`](./153_find-minimum-in-rotated-sorted-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個原本遞增排序、經過 1 到 n 次旋轉的整數陣列，且其中所有元素皆不重複。請回傳陣列中的最小元素。演算法必須在 O(log n) 時間內完成。

**思路**：以首尾索引做二分搜尋，利用中點與兩端值的大小關係判斷旋轉點落在哪一側，持續縮小區間至相鄰元素後取較小者。

## Problem Statement (English)

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
```

## 限制 Constraints

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

## 官方 C 函式簽名 Signature

```c
int findMin(int* nums, int numsSize) {
    
}
```
