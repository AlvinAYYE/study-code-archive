# 0949. Largest Time for Given Digits《由給定數字組成的最大時間》

- **Difficulty**: Medium
- **Tags**: array, string, backtracking, enumeration
- **題目連結**: https://leetcode.com/problems/largest-time-for-given-digits/
- **程式碼**: [`949_largest-time-for-given-digits.c`](./949_largest-time-for-given-digits.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定四個數字，必須各使用一次來組成最晚的 24 小時制時間。時間格式為 HH:MM，HH 必須介於 00 到 23，MM 必須介於 00 到 59；若無法組成合法時間，回傳空字串。

**思路**：統計各數字的可用數量，從時、分的高位到低位以遞迴回溯嘗試可放入的最大數字，並依 23:59 的位置上限剪枝。

## Problem Statement (English)

Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: arr = [1,2,3,4]
Output: "23:41"
Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.

Input: arr = [5,5,5,5]
Output: ""
Explanation: There are no valid 24-hour times as "55:55" is not valid.
```

## 限制 Constraints

arr.length == 4
0 <= arr[i] <= 9

## 官方 C 函式簽名 Signature

```c
char* largestTimeFromDigits(int* arr, int arrSize) {
    
}
```
