# 0482. License Key Formatting《密鑰格式化》

- **Difficulty**: Easy
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/license-key-formatting/
- **程式碼**: [`482_license-key-formatting.c`](./482_license-key-formatting.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含英數字元與連字號的授權密鑰 s，以及整數 k，請重新格式化它。移除原有連字號並將小寫轉大寫後，各組應有 k 個字元；第一組可較短但不可為空。回傳以連字號分隔各組的結果。

**思路**：程式先計算非連字號字元數以決定第一組長度，再由左至右略過連字號、轉大寫並在分組邊界插入連字號。最後移除可能多出的尾端連字號。

## Problem Statement (English)

You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
Return the reformatted license key.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "5F3Z-2e-9-w", k = 4
Output: "5F3Z-2E9W"
Explanation: The string s has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.

Input: s = "2-5g-3-J", k = 2
Output: "2-5G-3J"
Explanation: The string s has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
```

## 限制 Constraints

1 <= s.length <= 105
s consists of English letters, digits, and dashes '-'.
1 <= k <= 104

## 官方 C 函式簽名 Signature

```c
char* licenseKeyFormatting(char* s, int k) {
    
}
```
