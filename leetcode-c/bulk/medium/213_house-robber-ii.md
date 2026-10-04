# 0213. House Robber II《打家劫舍 II》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/house-robber-ii/
- **程式碼**: [`213_house-robber-ii.c`](./213_house-robber-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

房屋排列成環狀，因此第一間與最後一間也相鄰，不能在同一晚同時偷取相鄰房屋。給定各房屋金額，請回傳不觸發警報時可取得的最大金額。

**思路**：將環拆成兩種互斥情況：排除最後一間或排除第一間；各自以記憶化遞迴求線性房屋的最佳結果，再取較大值。

## Problem Statement (English)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: nums = [1,2,3]
Output: 3
```

## 限制 Constraints

1 <= nums.length <= 100
0 <= nums[i] <= 1000

## 官方 C 函式簽名 Signature

```c
int rob(int* nums, int numsSize) {
    
}
```
