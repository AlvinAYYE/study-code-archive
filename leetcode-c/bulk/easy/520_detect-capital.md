# 0520. Detect Capital《偵測大寫字母》

- **Difficulty**: Easy
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/detect-capital/
- **程式碼**: [`520_detect-capital.c`](./520_detect-capital.c) — 社群解答（repo 6lc_git），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定由大小寫英文字母組成的單字，判斷其大寫使用方式是否正確。合法情況為全部大寫、全部小寫，或只有第一個字母大寫。

**思路**：掃描字串計算大寫字母數量，並以大寫數是否為 0、全長，或僅首字母大寫來判定。

## Problem Statement (English)

We define the usage of capitals in a word to be right when one of the following cases holds:
Given a string word, return true if the usage of capitals in it is right.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: word = "USA"
Output: true

Input: word = "FlaG"
Output: false
```

## 限制 Constraints

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.

## 官方 C 函式簽名 Signature

```c
bool detectCapitalUse(char* word) {
    
}
```
