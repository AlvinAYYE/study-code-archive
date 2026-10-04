# 0784. Letter Case Permutation《字母大小寫排列》

- **Difficulty**: Medium
- **Tags**: string, backtracking, bit-manipulation
- **題目連結**: https://leetcode.com/problems/letter-case-permutation/
- **程式碼**: [`784_letter-case-permutation.c`](./784_letter-case-permutation.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

字串 s 的每個英文字母都可獨立轉為小寫或大寫，數字則不變。回傳所有可產生的字串，順序不限；s 長度最多為 12。

**思路**：以遞迴回溯逐一處理字元；遇到字母先切換大小寫走一個分支，再還原後走原大小寫分支，走到字尾便收集結果。

## Problem Statement (English)

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Input: s = "3z4"
Output: ["3z4","3Z4"]
```

## 限制 Constraints

1 <= s.length <= 12
s consists of lowercase English letters, uppercase English letters, and digits.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCasePermutation(char* s, int* returnSize) {
    
}
```
