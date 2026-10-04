# 0066. Plus One《加一》

- **Difficulty**: Easy
- **Tags**: array, math
- **題目連結**: https://leetcode.com/problems/plus-one/
- **程式碼**: [`066_plus-one.c`](./066_plus-one.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

以整數陣列 digits 表示一個大整數，數字由最高有效位到最低有效位排列，且除零外沒有前導零。將此整數加一後，回傳結果的數字陣列。

**思路**：從最低有效位開始加上進位 1，逐位保存餘數並更新進位。若最高位仍有進位，將既有結果右移並在前方補上 1。

## Problem Statement (English)

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
```

## 限制 Constraints

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
}
```
