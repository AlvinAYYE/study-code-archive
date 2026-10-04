# 0401. Binary Watch《二進位手錶》

- **Difficulty**: Easy
- **Tags**: backtracking, bit-manipulation
- **題目連結**: https://leetcode.com/problems/binary-watch/
- **程式碼**: [`401_binary-watch.c`](./401_binary-watch.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

二進位手錶以 4 顆 LED 表示小時 0 至 11，以 6 顆 LED 表示分鐘 0 至 59；給定目前亮起的 LED 數 turnedOn，回傳所有可能時間。小時不可有前導零，分鐘必須為兩位數且可有前導零，輸出順序不限。

**思路**：預先計算每個合法小時與分鐘的 1 位元數，枚舉 12 x 60 種時間並保留兩者總和等於 turnedOn 的格式化結果。

## Problem Statement (English)

A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.
The hour must not contain a leading zero.
The minute must consist of two digits and may contain a leading zero.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

Input: turnedOn = 9
Output: []
```

## 限制 Constraints

0 <= turnedOn <= 10

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int turnedOn, int* returnSize) {
    
}
```
