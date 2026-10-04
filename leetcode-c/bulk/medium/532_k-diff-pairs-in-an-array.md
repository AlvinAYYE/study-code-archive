# 0532. K-diff Pairs in an Array《陣列中的 K 差值數對》

- **Difficulty**: Medium
- **Tags**: array, hash-table, two-pointers, binary-search, sorting
- **題目連結**: https://leetcode.com/problems/k-diff-pairs-in-an-array/
- **程式碼**: [`532_k-diff-pairs-in-an-array.c`](./532_k-diff-pairs-in-an-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與非負整數 k，回傳數值差絕對值為 k 的不重複數對數量。每個數對由不同索引組成，即使輸入含重複值也只能計算唯一數值組合。

**思路**：程式用自製雜湊表記錄已見值與次數；k 大於 0 時查詢目前值的正負 k 鄰值，k 為 0 時只在同值第二次出現時計入一次。

## Problem Statement (English)

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
Notice that |val| denotes the absolute value of val.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
```

## 限制 Constraints

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107

## 官方 C 函式簽名 Signature

```c
int findPairs(int* nums, int numsSize, int k) {
    
}
```
