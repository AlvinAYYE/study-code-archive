# 0467. Unique Substrings in Wraparound String《環繞字串中的唯一子字串》

- **Difficulty**: Medium
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/unique-substrings-in-wraparound-string/
- **程式碼**: [`467_unique-substrings-in-wraparound-string.c`](./467_unique-substrings-in-wraparound-string.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

base 是無限循環的字串「abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz...」。給定字串 s，計算 s 的非空子字串中，有多少個不同子字串也會出現在 base。

**思路**：程式掃描 s，維護連續符合字母環繞順序的片段長度。對每個結尾字母只保留最長長度，最後加總 26 個最大值以避免重複計數。

## Problem Statement (English)

We define the string base to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so base will look like this:
Given a string s, return the number of unique non-empty substrings of s are present in base.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "a"
Output: 1
Explanation: Only the substring "a" of s is in base.

Input: s = "cac"
Output: 2
Explanation: There are two substrings ("a", "c") of s in base.

Input: s = "zab"
Output: 6
Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of s in base.
```

## 限制 Constraints

1 <= s.length <= 105
s consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
int findSubstringInWraproundString(char* s) {
    
}
```
