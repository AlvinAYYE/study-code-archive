# 0852. Peak Index in a Mountain Array《山脈陣列的峰頂索引》

- **Difficulty**: Medium
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/peak-index-in-a-mountain-array/
- **程式碼**: [`852_peak-index-in-a-mountain-array.c`](./852_peak-index-in-a-mountain-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個保證先遞增後遞減的山脈陣列，回傳峰頂元素的索引。題目要求以 O(log n) 時間完成。

**思路**：此程式由左至右掃描，使用堆疊保存遞增段的索引；一旦偵測到下降，就取出該遞增段的峰頂並清空堆疊。最後回傳記錄到的峰頂索引。

## Problem Statement (English)

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: arr = [0,1,0]
Output: 1

Input: arr = [0,2,1,0]
Output: 1

Input: arr = [0,10,5,2]
Output: 1
```

## 限制 Constraints

3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.

## 官方 C 函式簽名 Signature

```c
int peakIndexInMountainArray(int* arr, int arrSize) {
    
}
```
