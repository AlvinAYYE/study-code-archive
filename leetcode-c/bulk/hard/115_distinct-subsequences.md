# 0115. Distinct Subsequences《不同的子序列》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/distinct-subsequences/
- **程式碼**: [`115_distinct-subsequences.c`](./115_distinct-subsequences.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與 t，求 s 中有多少個不同的子序列恰好等於 t。子序列可刪除 s 的部分字元，但必須保留其相對順序。測資保證答案可放入 32 位元帶符號整數。兩字串長度各介於 1 至 1000，且只包含英文字母。

**思路**：使用二維 DP，dp[i][j] 記錄 s 前綴中形成 t 前綴的方式數；字元相等時加上略過與配對兩種來源，不等時只略過 s 的字元。

## Problem Statement (English)

Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
```

## 限制 Constraints

1 <= s.length, t.length <= 1000
s and t consist of English letters.

## 官方 C 函式簽名 Signature

```c
int numDistinct(char* s, char* t) {
    
}
```
