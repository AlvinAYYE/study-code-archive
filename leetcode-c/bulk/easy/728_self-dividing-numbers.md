# 0728. Self Dividing Numbers《自除數》

- **Difficulty**: Easy
- **Tags**: math
- **題目連結**: https://leetcode.com/problems/self-dividing-numbers/
- **程式碼**: [`728_self-dividing-numbers.c`](./728_self-dividing-numbers.c) — 社群解答（repo ourhouchmohamed97_LeetCode_in_C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

自除數能被其十進位表示中的每一個數字整除，且數字中不得出現 0。給定 left 與 right，回傳閉區間 [left, right] 內所有自除數。

**思路**：逐一檢查區間中的每個數，拆出各位數後排除 0 並測試原數是否可被該位數整除。符合者依序加入結果。

## Problem Statement (English)

A self-dividing number is a number that is divisible by every digit it contains.
A self-dividing number is not allowed to contain the digit zero.
Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]

Input: left = 47, right = 85
Output: [48,55,66,77]
```

## 限制 Constraints

1 <= left <= right <= 104

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    
}
```
