# 0561. Array Partition《陣列分割》

- **Difficulty**: Easy
- **Tags**: array, greedy, sorting, counting-sort
- **題目連結**: https://leetcode.com/problems/array-partition/
- **程式碼**: [`561_array-partition.c`](./561_array-partition.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定含 2n 個整數的陣列，將所有數分成 n 對，使每對較小值的總和最大。請回傳可達到的最大總和。

**思路**：先將陣列排序，再以頭尾指標每次各跨兩格加總；此做法等價於取排序後位於偶數索引的元素。

## Problem Statement (English)

Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
```

## 限制 Constraints

1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104

## 官方 C 函式簽名 Signature

```c
int arrayPairSum(int* nums, int numsSize) {
    
}
```
