# 0005. Longest Palindromic Substring｜最長迴文子字串

- **難度**：中等
- **標籤**：雙指標、字串、動態規劃
- **題目連結**：[LeetCode 0005](https://leetcode.com/problems/longest-palindromic-substring/)
- **C 程式**：[005_longest-palindromic-substring.c](./005_longest-palindromic-substring.c)

## 題目說明

給定字串 `s`，回傳其中最長的連續迴文子字串。迴文從左往右或從右往左讀都相同；例如 `"abba"` 是迴文。

## 範例

```text
輸入：s = "babad"
輸出："bab"
說明："aba" 也是正確答案。

輸入：s = "cbbd"
輸出："bb"
```

## 限制

- `1 <= s.length <= 1000`。
- `s` 只包含數字與英文字母。

## 解題步驟

1. 每個迴文都能從中心往兩側擴展：奇數長度的中心是一個字元，偶數長度的中心是兩字元間的空隙。
2. 對每個索引 `i`，分別從 `(i, i)` 和 `(i, i + 1)` 開始檢查。
3. 只要左右字元相同，就繼續向外；失配或碰到字串邊界時停止。
4. 用 `bestStart`、`bestLength` 記住最長區間，最後配置新字串並複製該區間。

例如 `"cbbd"` 的偶數中心從兩個 `b` 開始，向外擴展後得到 `"bb"`。

## 複雜度

- 時間：`O(n^2)`，共有 `2n - 1` 個中心，每次最多擴展 `O(n)`。
- 額外空間：`O(1)`；回傳字串需要 `O(n)` 空間。

## LeetCode C 函式簽名

```c
char* longestPalindrome(char* s);
```
