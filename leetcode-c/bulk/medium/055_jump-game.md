# 0055. Jump Game《跳躍遊戲》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, greedy
- **題目連結**: https://leetcode.com/problems/jump-game/
- **程式碼**: [`055_jump-game.c`](./055_jump-game.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非負整數陣列 nums，從第一個索引出發，每個元素表示該位置可向前跳躍的最大距離。若能到達最後一個索引則回傳 true，否則回傳 false。

**思路**：由左至右維護目前可到達的最遠索引 reach。若掃描過程無法再延伸範圍便停止，最後判斷 reach 是否已覆蓋終點。

## Problem Statement (English)

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```

## 限制 Constraints

1 <= nums.length <= 104
0 <= nums[i] <= 105

## 官方 C 函式簽名 Signature

```c
bool canJump(int* nums, int numsSize) {
    
}
```
