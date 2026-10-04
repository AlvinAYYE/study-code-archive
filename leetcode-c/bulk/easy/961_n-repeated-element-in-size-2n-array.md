# 0961. N-Repeated Element in Size 2N Array《大小為 2N 的陣列中的 N 次重複元素》

- **Difficulty**: Easy
- **Tags**: array, hash-table
- **題目連結**: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
- **程式碼**: [`961_n-repeated-element-in-size-2n-array.c`](./961_n-repeated-element-in-size-2n-array.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定陣列 nums，長度為 2n，包含 n + 1 種不同元素，其中恰有一個元素剛好重複 n 次，其餘元素各出現一次。請回傳重複 n 次的元素。

**思路**：由第三個元素起檢查它是否等於前一個或前兩個元素；依題目的重複分布必能快速找到符合的值。

## Problem Statement (English)

You are given an integer array nums with the following properties:
Return the element that is repeated n times.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3,3]
Output: 3

Input: nums = [2,1,2,5,3,2]
Output: 2

Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
```

## 限制 Constraints

2 <= n <= 5000
nums.length == 2 * n
0 <= nums[i] <= 104
nums contains n + 1 unique elements and one of them is repeated exactly n times.

## 官方 C 函式簽名 Signature

```c
int repeatedNTimes(int* nums, int numsSize) {
    
}
```
