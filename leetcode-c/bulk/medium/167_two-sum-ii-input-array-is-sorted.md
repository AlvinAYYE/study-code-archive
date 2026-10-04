# 0167. Two Sum II - Input Array Is Sorted《兩數之和 II：輸入陣列已排序》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, binary-search
- **題目連結**: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
- **程式碼**: [`167_two-sum-ii-input-array-is-sorted.c`](./167_two-sum-ii-input-array-is-sorted.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個已非遞減排序的 1 索引整數陣列與 target，找出兩個不同元素使其和等於 target。測試資料保證剛好有一組解，且不可重複使用同一元素。請回傳兩個 1 索引位置，並僅使用常數額外空間。

**思路**：使用左右雙指針：和過大時右指針左移，和過小時左指針右移，找到目標後回傳兩個索引加一。

## Problem Statement (English)

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
```

## 限制 Constraints

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
}
```
