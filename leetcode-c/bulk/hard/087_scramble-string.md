# 0087. Scramble String《擾亂字串》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/scramble-string/
- **程式碼**: [`087_scramble-string.c`](./087_scramble-string.c) — 社群解答（repo begeekmyfriend_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

可將字串反覆切成兩個非空子字串，並在每次切分後選擇交換或不交換兩部分，藉此形成擾亂字串。給定等長的小寫字串 s1 與 s2，判斷 s2 是否能由 s1 依此規則形成。字串長度介於 1 到 30。

**思路**：遞迴嘗試每個切分位置的未交換與交換兩種配對。每次遞迴前先比較兩段的字元計數，不同便立即剪枝。

## Problem Statement (English)

We can scramble a string s to get a string t using the following algorithm:
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.

Input: s1 = "abcde", s2 = "caebd"
Output: false

Input: s1 = "a", s2 = "a"
Output: true
```

## 限制 Constraints

s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool isScramble(char* s1, char* s2) {
    
}
```
