# 0643. Maximum Average Subarray I《子陣列最大平均數 I》

- **Difficulty**: Easy
- **Tags**: array, sliding-window
- **題目連結**: https://leetcode.com/problems/maximum-average-subarray-i/
- **程式碼**: [`643_maximum-average-subarray-i.c`](./643_maximum-average-subarray-i.c) — 社群解答（repo Senthil455_Leetcode-Code），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列與 k，找出長度恰為 k 的連續子陣列中，平均值最大的那一個並回傳平均值。與正確答案誤差小於 10^-5 的結果都可接受。

**思路**：先計算第一個長度 k 視窗的總和，再每次加入右端元素並扣除離開左端的元素。持續比較各視窗總和除以 k 後的平均值。

## Problem Statement (English)

You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Input: nums = [5], k = 1
Output: 5.00000
```

## 限制 Constraints

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104

## 官方 C 函式簽名 Signature

```c
double findMaxAverage(int* nums, int numsSize, int k) {
    
}
```
