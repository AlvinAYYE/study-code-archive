# 0611. Valid Triangle Number《有效三角形的個數》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, binary-search, greedy, sorting
- **題目連結**: https://leetcode.com/problems/valid-triangle-number/
- **程式碼**: [`611_valid-triangle-number.c`](./611_valid-triangle-number.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列，計算可從中選出多少個三元組作為三角形三邊長。三個數必須滿足三角形不等式，陣列中的不同位置即使數值相同也應分別計算。

**思路**：先遞增排序，固定最大的邊後以左右雙指針夾逼。若兩端和大於最大邊，左到右端前一格的所有選擇都有效；否則右移左指針。

## Problem Statement (English)

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Input: nums = [4,2,3,4]
Output: 4
```

## 限制 Constraints

1 <= nums.length <= 1000
0 <= nums[i] <= 1000

## 官方 C 函式簽名 Signature

```c
int triangleNumber(int* nums, int numsSize) {
    
}
```
