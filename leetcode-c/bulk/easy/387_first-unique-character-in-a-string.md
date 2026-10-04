# 0387. First Unique Character in a String《字串中的第一個唯一字元》

- **Difficulty**: Easy
- **Tags**: hash-table, string, queue, counting
- **題目連結**: https://leetcode.com/problems/first-unique-character-in-a-string/
- **程式碼**: [`387_first-unique-character-in-a-string.c`](./387_first-unique-character-in-a-string.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，找出第一個只出現一次的字元並回傳其索引。若不存在不重複字元，回傳 -1。

**思路**：統計 26 個小寫字母的出現次數與最後索引，再在所有只出現一次的字母中取最小索引。

## Problem Statement (English)

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "leetcode"
Output: 0
Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.

Input: s = "loveleetcode"
Output: 2

Input: s = "aabb"
Output: -1
```

## 限制 Constraints

1 <= s.length <= 105
s consists of only lowercase English letters.

## 官方 C 函式簽名 Signature

```c
int firstUniqChar(char* s) {
    
}
```
