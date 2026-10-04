# 0495. Teemo Attacking《提莫攻擊》

- **Difficulty**: Easy
- **Tags**: array, simulation
- **題目連結**: https://leetcode.com/problems/teemo-attacking/
- **程式碼**: [`495_teemo-attacking.c`](./495_teemo-attacking.c) — 社群解答（repo BlackDragonF_LeetcodeSolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

提莫在時間 t 攻擊時，艾希會在含端點區間 [t, t + duration - 1] 中中毒。若下一次攻擊發生在毒效結束前，毒效計時會重設。回傳艾希總共中毒了多少秒。

**思路**：程式記錄目前毒效結束的下一個時間點；新攻擊不重疊時加完整 duration，重疊時只加延長部分。每次攻擊後更新結束時間即可。

## Problem Statement (English)

Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration seconds. More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration seconds after the new attack.
You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries[i], and an integer duration.
Return the total number of seconds that Ashe is poisoned.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: timeSeries = [1,4], duration = 2
Output: 4
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 4, Teemo attacks, and Ashe is poisoned for seconds 4 and 5.
Ashe is poisoned for seconds 1, 2, 4, and 5, which is 4 seconds in total.

Input: timeSeries = [1,2], duration = 2
Output: 3
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 2 however, Teemo attacks again and resets the poison timer. Ashe is poisoned for seconds 2 and 3.
Ashe is poisoned for seconds 1, 2, and 3, which is 3 seconds in total.
```

## 限制 Constraints

1 <= timeSeries.length <= 104
0 <= timeSeries[i], duration <= 107
timeSeries is sorted in non-decreasing order.

## 官方 C 函式簽名 Signature

```c
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    
}
```
