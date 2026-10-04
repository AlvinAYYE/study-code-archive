# 0403. Frog Jump《青蛙過河》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/frog-jump/
- **程式碼**: [`403_frog-jump.c`](./403_frog-jump.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

河中石頭的位置以遞增陣列 stones 給出，青蛙從第一顆石頭開始，第一跳必須為 1 單位，且只能落在石頭上。若上一次跳 k 單位，下一跳只能是 k - 1、k 或 k + 1 單位且必須向前；判斷能否落到最後一顆石頭。

**思路**：為每顆石頭記錄所有可到達時的上次跳躍距離，對每個距離嘗試 k-1、k、k+1，並以二分搜尋確認目標位置是否有石頭。

## Problem Statement (English)

A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
```

## 限制 Constraints

2 <= stones.length <= 2000
0 <= stones[i] <= 231 - 1
stones[0] == 0
stones is sorted in a strictly increasing order.

## 官方 C 函式簽名 Signature

```c
bool canCross(int* stones, int stonesSize) {
    
}
```
