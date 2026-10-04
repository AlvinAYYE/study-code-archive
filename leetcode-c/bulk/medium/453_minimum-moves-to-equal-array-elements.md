# 0453. Minimum Moves to Equal Array Elements《最少移動次數使陣列元素相等》

- **Difficulty**: Medium
- **Tags**: array, math
- **題目連結**: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
- **程式碼**: [`453_minimum-moves-to-equal-array-elements.c`](./453_minimum-moves-to-equal-array-elements.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定大小為 n 的整數陣列 nums，每次操作可將其中 n-1 個元素各加 1。請回傳使所有元素相等所需的最少操作次數，且答案保證可裝入 32 位元整數。

**思路**：程式先找出全陣列最小值，再累加每個元素與最小值的差。這等價於每次操作讓未被加一的元素相對減一，因此總差值就是最少步數。

## Problem Statement (English)

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
In one move, you can increment n - 1 elements of the array by 1.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

Input: nums = [1,1,1]
Output: 0
```

## 限制 Constraints

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109
The answer is guaranteed to fit in a 32-bit integer.

## 官方 C 函式簽名 Signature

```c
int minMoves(int* nums, int numsSize) {
    
}
```
