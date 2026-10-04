# 0319. Bulb Switcher《燈泡開關》

- **Difficulty**: Medium
- **Tags**: math, brainteaser
- **題目連結**: https://leetcode.com/problems/bulb-switcher/
- **程式碼**: [`319_bulb-switcher.c`](./319_bulb-switcher.c) — 社群解答（repo zeplios_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有 n 個初始關閉的燈泡；第 i 輪會切換所有編號為 i 倍數的燈泡，依序進行第 1 輪到第 n 輪。請回傳所有輪次結束後仍亮著的燈泡數量。

**思路**：程式以 i × i 不超過 n 的迴圈直接計算整數平方根。因為只有完全平方數的因數個數為奇數，最終亮著的燈泡數就是 floor(sqrt(n))。

## Problem Statement (English)

There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.
Return the number of bulbs that are on after n rounds.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.

Input: n = 0
Output: 0

Input: n = 1
Output: 1
```

## 限制 Constraints

0 <= n <= 109

## 官方 C 函式簽名 Signature

```c
int bulbSwitch(int n) {
    
}
```
