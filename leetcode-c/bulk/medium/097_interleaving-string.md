# 0097. Interleaving String《交錯字串》

- **Difficulty**: Medium
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/interleaving-string/
- **程式碼**: [`097_interleaving-string.c`](./097_interleaving-string.c) — 社群解答（repo lightmen_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s1、s2、s3，判斷 s3 是否能由 s1 與 s2 交錯組成，且兩原字串各自的字元相對順序必須保持不變。若 s1 與 s2 的長度總和不等於 s3，必定無法組成。三個字串都可能為空。

**思路**：以二維 DP 記錄取用 s1 前 i 個與 s2 前 j 個字元是否能組成 s3 前 i+j 個字元。狀態可由上方匹配 s1 字元或左方匹配 s2 字元轉移而來。

## Problem Statement (English)

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
Note: a + b is the concatenation of strings a and b.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you solve it using only O(s2.length) additional memory space?

## 範例 Examples

```text
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.

Input: s1 = "", s2 = "", s3 = ""
Output: true
```

## 限制 Constraints

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool isInterleave(char* s1, char* s2, char* s3) {
    
}
```
