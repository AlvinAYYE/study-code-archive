# 0424. Longest Repeating Character Replacement《替換後的最長重複字元》

- **Difficulty**: Medium
- **Tags**: hash-table, string, sliding-window
- **題目連結**: https://leetcode.com/problems/longest-repeating-character-replacement/
- **程式碼**: [`424_longest-repeating-character-replacement.c`](./424_longest-repeating-character-replacement.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含大寫英文字母的字串 s 與整數 k，每次可將任一字元改成另一個大寫字母，最多可操作 k 次。回傳操作後可得到、且所有字元相同的最長子字串長度。

**思路**：以滑動視窗維護 26 個字母的出現次數及視窗內最高頻率。若視窗長度超過最高頻率加 k，便從左端縮小；掃描結束時的視窗即為最大長度。

## Problem Statement (English)

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
```

## 限制 Constraints

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

## 官方 C 函式簽名 Signature

```c
int characterReplacement(char* s, int k) {
    
}
```
