# 0075. Sort Colors《顏色分類》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, sorting
- **題目連結**: https://leetcode.com/problems/sort-colors/
- **程式碼**: [`075_sort-colors.c`](./075_sort-colors.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含 0、1、2 的陣列，分別代表紅、白、藍三種顏色，請原地將相同顏色相鄰排列為紅、白、藍的順序。不可使用函式庫排序功能。

**思路**：使用荷蘭國旗的三指針：左指針放 0、中指針掃描、右指針放 2。掃到 0 或 2 時與對應端交換，掃到 1 則只前進中指針。

## Problem Statement (English)

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
Example 1:
Example 2:
Constraints:
Follow up: Could you come up with a one-pass algorithm using only constant extra space?

## 範例 Examples

```text
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]
```

## 限制 Constraints

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

## 官方 C 函式簽名 Signature

```c
void sortColors(int* nums, int numsSize) {
    
}
```
