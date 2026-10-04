# 0198. House Robber《打家劫舍》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/house-robber/
- **程式碼**: [`198_house-robber.c`](./198_house-robber.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

街道上的每間房屋都有金額，但不能在同一晚偷取相鄰房屋，否則會觸發警報。給定每間房屋的金額陣列，請回傳在不觸發警報下可偷得的最大金額。

**思路**：逐屋維護「偷本屋」與「不偷本屋」兩種最佳金額；前者接續前一屋未偷的狀態，後者取前一屋兩種狀態的較大值。

## Problem Statement (English)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

## 限制 Constraints

1 <= nums.length <= 100
0 <= nums[i] <= 400

## 官方 C 函式簽名 Signature

```c
int rob(int* nums, int numsSize) {
    
}
```
