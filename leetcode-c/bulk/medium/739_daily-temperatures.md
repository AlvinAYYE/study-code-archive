# 0739. Daily Temperatures《每日溫度》

- **Difficulty**: Medium
- **Tags**: array, stack, monotonic-stack
- **題目連結**: https://leetcode.com/problems/daily-temperatures/
- **程式碼**: [`739_daily-temperatures.c`](./739_daily-temperatures.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定每日氣溫 temperatures，answer[i] 應表示第 i 天之後還要等幾天才會出現更高溫。若未來沒有更高溫，該位置應為 0。

**思路**：使用儲存索引的單調遞減堆疊；新溫度高於堆疊頂端時，持續彈出並以索引差填入等待天數。掃描結束後仍在堆疊中的位置皆填 0。

## Problem Statement (English)

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Input: temperatures = [30,60,90]
Output: [1,1,0]
```

## 限制 Constraints

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
}
```
