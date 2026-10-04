# 0926. Flip String to Monotone Increasing《將字串翻轉為單調遞增》

- **Difficulty**: Medium
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/flip-string-to-monotone-increasing/
- **程式碼**: [`926_flip-string-to-monotone-increasing.c`](./926_flip-string-to-monotone-increasing.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

單調遞增二進位字串由零個或多個 0 後接零個或多個 1 組成。給定二進位字串 s，每次可將一個位元在 0 與 1 間翻轉。請回傳使字串單調遞增所需的最少翻轉次數。

**思路**：以兩個狀態維護目前前綴最後為 0 或最後為 1 時的最小翻轉數，逐字依當前位元更新後取兩者較小值。

## Problem Statement (English)

A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
Return the minimum number of flips to make s monotone increasing.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
```

## 限制 Constraints

1 <= s.length <= 105
s[i] is either '0' or '1'.

## 官方 C 函式簽名 Signature

```c
int minFlipsMonoIncr(char* s) {
    
}
```
