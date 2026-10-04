# 0031. Next Permutation《下一個排列》

- **Difficulty**: Medium
- **Tags**: array, two-pointers
- **題目連結**: https://leetcode.com/problems/next-permutation/
- **程式碼**: [`031_next-permutation.c`](./031_next-permutation.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，將其原地改為字典序中的下一個排列。若不存在更大的排列，則改為最小的遞增排列；只能使用常數額外空間。

**思路**：程式從尾端找出第一個小於其右側元素的樞紐，再在尾段找出最右側且大於樞紐的元素來交換。交換後將尾段排序為遞增；若無樞紐則把整個陣列排序為遞增。

## Problem Statement (English)

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3]
Output: [1,3,2]

Input: nums = [3,2,1]
Output: [1,2,3]

Input: nums = [1,1,5]
Output: [1,5,1]
```

## 限制 Constraints

1 <= nums.length <= 100
0 <= nums[i] <= 100

## 官方 C 函式簽名 Signature

```c
void nextPermutation(int* nums, int numsSize) {
    
}
```
