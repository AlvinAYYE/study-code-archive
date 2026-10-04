# 0132. Palindrome Partitioning II《回文分割 II》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/palindrome-partitioning-ii/
- **程式碼**: [`132_palindrome-partitioning-ii.c`](./132_palindrome-partitioning-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

將字串 s 分割成多個子字串，使每個子字串都是回文。請回傳完成這種回文分割所需的最少切割次數。s 長度介於 1 至 2000，且只包含小寫英文字母。

**思路**：以 dp 記錄各前綴的最少切割數，並以每個位置為中心向兩側擴展奇數與偶數長度的回文，同步更新其右端前綴的答案。

## Problem Statement (English)

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Input: s = "a"
Output: 0

Input: s = "ab"
Output: 1
```

## 限制 Constraints

1 <= s.length <= 2000
s consists of lowercase English letters only.

## 官方 C 函式簽名 Signature

```c
int minCut(char* s) {
    
}
```
