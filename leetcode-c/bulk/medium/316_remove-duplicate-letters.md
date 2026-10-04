# 0316. Remove Duplicate Letters《移除重複字母》

- **Difficulty**: Medium
- **Tags**: string, stack, greedy, monotonic-stack
- **題目連結**: https://leetcode.com/problems/remove-duplicate-letters/
- **程式碼**: [`316_remove-duplicate-letters.c`](./316_remove-duplicate-letters.c) — 社群解答（repo lightmen_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定小寫字串 s，請移除重複字母，使每個出現過的字母恰好保留一次。所有可行結果中，必須回傳字典序最小的字串。

**思路**：先統計每個字元尚未掃描的次數，並用遞增單調堆疊建立答案。若新字元較小且堆頂之後仍會再出現，就彈出堆頂；另以 visited 避免重複放入。

## Problem Statement (English)

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
Example 1:
Example 2:
Constraints:
Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

## 範例 Examples

```text
Input: s = "bcabc"
Output: "abc"

Input: s = "cbacdcbc"
Output: "acdb"
```

## 限制 Constraints

1 <= s.length <= 104
s consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
char* removeDuplicateLetters(char* s) {
    
}
```
