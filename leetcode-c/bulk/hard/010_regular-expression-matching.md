# 0010. Regular Expression Matching《正規表示式匹配》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming, recursion
- **題目連結**: https://leetcode.com/problems/regular-expression-matching/
- **程式碼**: [`010_regular-expression-matching.c`](./010_regular-expression-matching.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定輸入字串 `s` 與模式 `p`，請實作支援下列規則的完整匹配：

- `.` 可匹配任意單一字元。
- `*` 可讓它前面的元素出現零次或多次。

匹配必須涵蓋整個輸入字串，不能只匹配其中一部分。

## 解題思路

1. 定義 `dp[i][j]`：`s` 的前 `i` 個字元能否被 `p` 的前 `j` 個字元完整匹配；空字串與空模式相符。
2. 一般字元或 `.` 必須匹配目前字元，再承接左上角 `dp[i-1][j-1]`。
3. 遇到 `*` 時，可讓「前一元素 + `*`」出現零次；若前一元素能匹配目前字元，也可讓 `*` 再吃掉一個字元並停在同一模式位置。
4. `a*b*` 這類模式能匹配空字串，因此需先初始化 DP 的空字串列。
5. 表格右下角就是完整字串與模式的答案。

時間複雜度為 `O(|s||p|)`，空間複雜度為 `O(|s||p|)`。

## Problem Statement (English)

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
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

輸入：s = "aa", p = "a*"
輸出：true
說明：`*` 讓前面的 `a` 可重複多次，因此能匹配兩個 `a`。

輸入：s = "ab", p = ".*"
輸出：true
說明：`.` 可代表任意字元，`*` 再讓它出現零次或多次。
```

## 限制

- `1 <= s.length, p.length <= 20`
- `s` 僅包含小寫英文字母。
- `p` 僅包含小寫英文字母、`.` 與 `*`。
- 每個 `*` 前面都保證有一個可供它修飾的有效元素。

## 官方 C 函式簽名 Signature

```c
bool isMatch(char* s, char* p) {
    
}
```
