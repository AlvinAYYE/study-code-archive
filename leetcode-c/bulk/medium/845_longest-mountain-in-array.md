# 0845. Longest Mountain in Array《陣列中的最長山脈》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, dynamic-programming, enumeration
- **題目連結**: https://leetcode.com/problems/longest-mountain-in-array/
- **程式碼**: [`845_longest-mountain-in-array.c`](./845_longest-mountain-in-array.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

山脈子陣列必須先嚴格遞增再嚴格遞減，因此上坡與下坡都不可缺少。給定整數陣列，回傳最長山脈子陣列的長度；若不存在則回傳 0。

**思路**：程式從各起點連續掃描嚴格上坡，若有上坡再掃描連續下坡並更新長度。掃描後會跳過已處理的下坡區段，避免重複計算。

## Problem Statement (English)

You may recall that an array arr is a mountain array if and only if:
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.
Example 1:
Example 2:
Constraints:
Follow up:

## 範例 Examples

```text
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
```

## 限制 Constraints

1 <= arr.length <= 104
0 <= arr[i] <= 104

## 官方 C 函式簽名 Signature

```c
int longestMountain(int* arr, int arrSize) {
    
}
```
