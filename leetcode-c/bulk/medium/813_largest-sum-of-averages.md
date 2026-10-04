# 0813. Largest Sum of Averages《最大平均值和》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, prefix-sum
- **題目連結**: https://leetcode.com/problems/largest-sum-of-averages/
- **程式碼**: [`813_largest-sum-of-averages.c`](./813_largest-sum-of-averages.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與 k，可將整個陣列切成至多 k 個非空且連續的子陣列。分割分數是各子陣列平均值之和，求可得到的最大分數；所有元素都必須被使用，誤差 10^-6 內可接受。

**思路**：dp[i] 先記錄從 i 到尾端只分一組的平均值，再逐輪枚舉下一段終點，更新為目前區段平均值加上後綴 dp 的最大和。

## Problem Statement (English)

You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.
Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [9,1,2,3,9], k = 3
Output: 20.00000
Explanation: 
The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.

Input: nums = [1,2,3,4,5,6,7], k = 4
Output: 20.50000
```

## 限制 Constraints

1 <= nums.length <= 100
1 <= nums[i] <= 104
1 <= k <= nums.length

## 官方 C 函式簽名 Signature

```c
double largestSumOfAverages(int* nums, int numsSize, int k) {
    
}
```
