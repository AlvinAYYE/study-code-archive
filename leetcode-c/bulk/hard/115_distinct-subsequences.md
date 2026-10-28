# 0115. Distinct Subsequences《不同的子序列》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/distinct-subsequences/
- **程式碼**: [`115_distinct-subsequences.c`](./115_distinct-subsequences.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 `s` 與 `t`，請計算 `s` 中有多少個不同的子序列恰好等於 `t`。子序列可以刪除 `s` 的部分字元，但剩餘字元必須維持原本的相對順序。測試資料保證答案可放入 32 位元帶符號整數。

## 解題思路

1. 定義 `dp[i][j]`：使用 `s[0..i]` 形成 `t[0..j]` 的不同方式數。
2. 無論字元是否相同，都可以略過 `s[i]`，因此先承接 `dp[i-1][j]`。
3. 若 `s[i] == t[j]`，也可使用這兩個字元配對，再加上 `dp[i-1][j-1]`。
4. 第一欄只需累計 `t[0]` 在 `s` 前綴中的出現次數；其餘狀態依列向後填表。
5. `dp[slen-1][tlen-1]` 就是完整 `t` 的形成方式數。

時間複雜度為 `O(|s||t|)`，二維 DP 表使用 `O(|s||t|)` 空間。

## Problem Statement (English)

Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.
Example 1:
Example 2:
Constraints:

## 範例

```text
輸入：s = "rabbbit", t = "rabbit"
輸出：3
說明：三個 b 中選擇兩個，有 3 種方式形成 "rabbit"。

輸入：s = "babgbag", t = "bag"
輸出：5
說明：從原字串選出 b、a、g 且保持相對順序，共有 5 種選法。
```

## 限制

- `1 <= s.length, t.length <= 1000`
- `s` 與 `t` 僅包含英文字母。

## 官方 C 函式簽名 Signature

```c
int numDistinct(char* s, char* t) {
    
}
```
