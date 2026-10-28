# 0076. Minimum Window Substring《最小覆蓋子字串》

- **Difficulty**: Hard
- **Tags**: hash-table, string, sliding-window
- **題目連結**: https://leetcode.com/problems/minimum-window-substring/
- **程式碼**: [`076_minimum-window-substring.c`](./076_minimum-window-substring.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定長度分別為 `m`、`n` 的字串 `s` 與 `t`，請找出 `s` 中最短的連續子字串，使它包含 `t` 的所有字元及各字元的需求次數。若不存在則回傳空字串 `""`；測試資料保證最短答案唯一。

## 解題思路

1. `cnt[c]` 起初記錄 `t` 還需要幾個字元 `c`；`n` 記錄尚未滿足的字元總數。
2. `tail` 向右擴張。若加入字元前 `cnt[c] > 0`，代表補到一個需求，將 `n` 減一；無論是否需要，都將 `cnt[c]` 減一以反映視窗內數量。
3. `n == 0` 時視窗已涵蓋 `t`，持續右移 `head` 收縮並更新最短區間。
4. 移出字元後將 `cnt[c]` 加一；若變成正數，表示移掉必要字元，視窗失效，再回到擴張階段。
5. 找到答案時在原字串的區間尾端寫入字串結尾並回傳起點；否則回傳空字串。

`head`、`tail` 各走過 `s` 至多一次，時間複雜度為 `O(m+n)`，固定計數表使額外空間為 `O(1)`。

## Problem Statement (English)

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you find an algorithm that runs in O(m + n) time?

## 範例

```text
輸入：s = "ADOBECODEBANC", t = "ABC"
輸出："BANC"
說明："BANC" 包含 A、B、C，且長度最短。

輸入：s = "a", t = "a"
輸出："a"
說明：整個 `s` 就是最小覆蓋子字串。

輸入：s = "a", t = "aa"
輸出：""
說明：`t` 需要兩個 a，但 `s` 只有一個，因此不存在合法視窗。
```

## 限制

- `m == s.length`，`n == t.length`
- `1 <= m, n <= 10^5`
- `s` 與 `t` 僅包含大寫及小寫英文字母。

## 官方 C 函式簽名 Signature

```c
char* minWindow(char* s, char* t) {
    
}
```
