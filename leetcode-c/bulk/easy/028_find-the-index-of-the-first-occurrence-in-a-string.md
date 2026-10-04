# 0028. Find the Index of the First Occurrence in a String《找出字串中第一個符合項的下標》

- **Difficulty**: Easy
- **Tags**: two-pointers, string, string-matching
- **題目連結**: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
- **程式碼**: [`028_find-the-index-of-the-first-occurrence-in-a-string.c`](./028_find-the-index-of-the-first-occurrence-in-a-string.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 haystack 與 needle，回傳 needle 在 haystack 中首次出現的起始索引。若 needle 不是 haystack 的子字串，則回傳 -1。

**思路**：程式逐一枚舉 haystack 中可能的起始位置，並以內層迴圈逐字元比較 needle。若整個 needle 都相符便立即回傳該位置，否則最終回傳 -1。

## Problem Statement (English)

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```

## 限制 Constraints

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

## 官方 C 函式簽名 Signature

```c
int strStr(char* haystack, char* needle) {
    
}
```
