# 0087. Scramble String《擾亂字串》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/scramble-string/
- **程式碼**: [`087_scramble-string.c`](./087_scramble-string.c) — 社群解答（repo begeekmyfriend_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

可將字串反覆切成兩個非空子字串，並在每次切分後選擇交換或不交換兩部分，藉此形成擾亂字串。給定等長字串 `s1` 與 `s2`，請判斷 `s2` 是否能由 `s1` 依此規則形成。

## 解題思路

1. 若兩段長度不同，必定無法互為擾亂字串；若內容已完全相同，直接成功。
2. 擾亂只會改變排列，不會改變字元數量，因此先比較兩段字元頻率；不同時可立即剪枝。
3. 對每個切分長度 `i` 嘗試兩種情況：左右兩段保持順序互相配對，或 `s1` 左段配 `s2` 右段、`s1` 右段配 `s2` 左段。
4. 任一切點的兩個子問題都成立即可回傳 `true`；所有切點都失敗才回傳 `false`。

目前實作未使用記憶化，最壞時間為指數級，遞迴深度為 `O(n)`；每層使用固定大小的字元頻率表。

## Problem Statement (English)

We can scramble a string s to get a string t using the following algorithm:
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例

```text
輸入：s1 = "great", s2 = "rgeat"
輸出：true
說明：可將 "great" 分為 "gr" 與 "eat"，再交換 "gr" 內的兩部分，得到 "rg" + "eat" = "rgeat"。

輸入：s1 = "abcde", s2 = "caebd"
輸出：false

輸入：s1 = "a", s2 = "a"
輸出：true
```

## 限制

- `s1.length == s2.length`
- `1 <= s1.length <= 30`
- `s1` 與 `s2` 僅包含小寫英文字母。

## 官方 C 函式簽名 Signature

```c
bool isScramble(char* s1, char* s2) {
    
}
```
