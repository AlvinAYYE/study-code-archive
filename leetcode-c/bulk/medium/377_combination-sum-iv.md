# 0377. Combination Sum IV《組合總和 IV》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/combination-sum-iv/
- **程式碼**: [`377_combination-sum-iv.c`](./377_combination-sum-iv.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定不重複正整數陣列 nums 與目標值 target，計算元素總和恰為 target 的可能組合數。不同順序視為不同組合，且答案保證可放入 32 位元整數。

**思路**：令 dp[t] 為湊出 t 的有序組合數，從小到大枚舉目標 t，對每個可用數字累加 dp[t - num]。

## Problem Statement (English)

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.
Example 1:
Example 2:
Constraints:
Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

## 範例 Examples

```text
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

Input: nums = [9], target = 3
Output: 0
```

## 限制 Constraints

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000

## 官方 C 函式簽名 Signature

```c
int combinationSum4(int* nums, int numsSize, int target) {
    
}
```
