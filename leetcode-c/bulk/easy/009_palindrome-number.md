# 0009. Palindrome Number《回文數》

- **Difficulty**: Easy
- **Tags**: math
- **題目連結**: https://leetcode.com/problems/palindrome-number/
- **程式碼**: [`009_palindrome-number.c`](./009_palindrome-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 x，若其由左至右與由右至左讀取相同則回傳 true，否則回傳 false。負數不是回文數，因為負號在反向後的位置不同。

**思路**：程式排除負數後，將整數的各位數完整反轉，再與原值比較。反轉過程也會先檢查是否會超出 int 範圍，若會則判定為 false。

## Problem Statement (English)

Given an integer x, return true if x is a palindrome, and false otherwise.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

## 限制 Constraints

-231 <= x <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool isPalindrome(int x) {
    
}
```
