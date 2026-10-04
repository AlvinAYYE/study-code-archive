# 0053. Maximum Subarray《最大子陣列和》

- **Difficulty**: Medium
- **Tags**: array, divide-and-conquer, dynamic-programming
- **題目連結**: https://leetcode.com/problems/maximum-subarray/
- **程式碼**: [`053_maximum-subarray.c`](./053_maximum-subarray.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，找出總和最大的非空連續子陣列並回傳其總和。題目另提出進階挑戰：在 O(n) 解法之外，也可嘗試使用分治法。

**思路**：程式採 Kadane 演算法，維護以目前位置結尾的最佳和。若先前累積和不為正就從目前元素重新開始，並同步更新全域最大值。

## Problem Statement (English)

Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

## 範例 Examples

```text
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

## 限制 Constraints

1 <= nums.length <= 105
-104 <= nums[i] <= 104

## 官方 C 函式簽名 Signature

```c
int maxSubArray(int* nums, int numsSize) {
    
}
```
