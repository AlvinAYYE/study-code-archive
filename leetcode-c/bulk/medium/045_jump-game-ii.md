# 0045. Jump Game II《跳躍遊戲 II》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, greedy
- **題目連結**: https://leetcode.com/problems/jump-game-ii/
- **程式碼**: [`045_jump-game-ii.c`](./045_jump-game-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

從 0 索引陣列 nums 的第一個位置出發，nums[i] 表示在索引 i 最多可向前跳的距離。回傳到達最後一個索引所需的最少跳躍次數，且測資保證一定可到達終點。

**思路**：線性掃描目前這一步可覆蓋的區間，持續更新能到達的最遠位置。掃描到目前區間右界時便必須多跳一步，並將右界延伸到最遠位置。

## Problem Statement (English)

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [2,3,0,1,4]
Output: 2
```

## 限制 Constraints

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].

## 官方 C 函式簽名 Signature

```c
int jump(int* nums, int numsSize) {
    
}
```
