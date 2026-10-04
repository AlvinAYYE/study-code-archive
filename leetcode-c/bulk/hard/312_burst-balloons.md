# 0312. Burst Balloons《戳破氣球》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/burst-balloons/
- **程式碼**: [`312_burst-balloons.c`](./312_burst-balloons.c) — 社群解答（repo lightmen_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定數列 nums 代表一排氣球，戳破第 i 顆可得到當下左右相鄰氣球值與自身值的乘積；超出邊界時視為值為 1 的氣球。請選擇戳破順序，以取得最多硬幣。

**思路**：在兩端補上值為 1 的哨兵，使用區間動態規劃。對每個區間枚舉最後被戳破的氣球 k，收益為左右子區間最佳值加上兩端與 k 的乘積。

## Problem Statement (English)

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Input: nums = [1,5]
Output: 10
```

## 限制 Constraints

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100

## 官方 C 函式簽名 Signature

```c
int maxCoins(int* nums, int numsSize) {
    
}
```
