# 0917. Reverse Only Letters《僅反轉字母》

- **Difficulty**: Easy
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/reverse-only-letters/
- **程式碼**: [`917_reverse-only-letters.c`](./917_reverse-only-letters.c) — 社群解答（repo MainakRepositor_LeetCode-C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，請只反轉其中英文字母的相對順序。所有非字母字元必須保留在原本的位置，最後回傳處理後的字串。

**思路**：使用首尾雙指針，分別跳過非字母字元；兩端皆為字母時交換，再向中間推進。

## Problem Statement (English)

Given a string s, reverse the string according to the following rules:
Return s after reversing it.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "ab-cd"
Output: "dc-ba"

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
```

## 限制 Constraints

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.

## 官方 C 函式簽名 Signature

```c
char* reverseOnlyLetters(char* s) {
    
}
```
