# 0941. Valid Mountain Array《有效的山脈陣列》

- **Difficulty**: Easy
- **Tags**: array
- **題目連結**: https://leetcode.com/problems/valid-mountain-array/
- **程式碼**: [`941_valid-mountain-array.c`](./941_valid-mountain-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 arr，判斷它是否為有效山脈陣列。有效山脈的長度至少為 3，且存在峰頂索引 i，使前段嚴格遞增、後段嚴格遞減，峰頂不能位於兩端。

**思路**：線性掃描時先驗證嚴格遞增，第一次下降後切換為遞減狀態；若出現相等、遞減後再上升，或從未下降即判為無效。

## Problem Statement (English)

Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: arr = [2,1]
Output: false

Input: arr = [3,5,5]
Output: false

Input: arr = [0,3,2,1]
Output: true
```

## 限制 Constraints

1 <= arr.length <= 104
0 <= arr[i] <= 104

## 官方 C 函式簽名 Signature

```c
bool validMountainArray(int* arr, int arrSize){

}
```
