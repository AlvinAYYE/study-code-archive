# 0494. Target Sum《目標和》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, backtracking
- **題目連結**: https://leetcode.com/problems/target-sum/
- **程式碼**: [`494_target-sum.c`](./494_target-sum.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與目標值 target，必須在每個數字前選擇加號或減號並串成運算式。回傳運算結果恰為 target 的不同符號指派數量。

**思路**：程式將問題轉成尋找和為 (總和 + target) / 2 的子集合數量，並先檢查可行性與奇偶性。之後以倒序的一維 0/1 背包 DP 累加各和的方案數。

## Problem Statement (English)

You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
Return the number of different expressions that you can build, which evaluates to target.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Input: nums = [1], target = 1
Output: 1
```

## 限制 Constraints

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

## 官方 C 函式簽名 Signature

```c
int findTargetSumWays(int* nums, int numsSize, int target) {
    
}
```
