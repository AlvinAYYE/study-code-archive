# 0044. Wildcard Matching《萬用字元匹配》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming, greedy, recursion
- **題目連結**: https://leetcode.com/problems/wildcard-matching/
- **程式碼**: [`044_wildcard-matching.c`](./044_wildcard-matching.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定輸入字串 `s` 與模式 `p`，請實作支援下列規則的萬用字元完整匹配：

- `?` 可匹配任意單一字元。
- `*` 可匹配任意長度的字元序列，包含空字串。

匹配必須涵蓋整個 `s`，不能只比對其中一段。

## 解題思路

1. 一般字元必須相同，`?` 可匹配任意非結尾字元；成功後讓字串與模式指標一起前進。
2. 遇到 `*` 時先略過連續星號，因為多個相鄰 `*` 與單一 `*` 的效果相同。
3. 若 `*` 已位於模式尾端，它可以吞掉 `s` 的所有剩餘字元，直接回傳 `true`。
4. 否則依序嘗試讓 `*` 吞掉 0、1、2……個字元，每個位置都遞迴比對剩餘模式；任一分支成功即匹配成功。
5. 模式耗盡時，只有字串也同時耗盡才算完整匹配。

目前 `ALG == 1` 選用遞迴版本，最壞時間為指數級，遞迴深度為 `O(|s|+|p|)`；檔案內亦保留雙指標與動態規劃版本供比較。

## Problem Statement (English)

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
The matching should cover the entire input string (not partial).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例

```text
輸入：s = "aa", p = "a"
輸出：false
說明：模式 "a" 無法匹配完整字串 "aa"。

輸入：s = "aa", p = "*"
輸出：true
說明：`*` 可以匹配任意字元序列。

輸入：s = "cb", p = "?a"
輸出：false
說明：`?` 能匹配 `c`，但模式中的 `a` 無法匹配字串中的 `b`。
```

## 限制

- `0 <= s.length, p.length <= 2000`
- `s` 僅包含小寫英文字母。
- `p` 僅包含小寫英文字母、`?` 或 `*`。

## 官方 C 函式簽名 Signature

```c
bool isMatch(char* s, char* p) {
    
}
```
