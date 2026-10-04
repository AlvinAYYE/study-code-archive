# 0791. Custom Sort String《自訂字串排序》

- **Difficulty**: Medium
- **Tags**: hash-table, string, sorting
- **題目連結**: https://leetcode.com/problems/custom-sort-string/
- **程式碼**: [`791_custom-sort-string.c`](./791_custom-sort-string.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 order 與 s，order 的字元皆互異並定義其先後順序。重新排列 s，讓凡是在 order 中 x 排在 y 前的字元，在結果中 x 也排在 y 前；可回傳任一合法排列。

**思路**：先統計 s 中各字母數量並記錄 order 指定的起始位置，將不在 order 的字元留在尾端，再依 order 的位置與次數填回前段。

## Problem Statement (English)

You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: "a" , "b" , "c" appear in order, so the order of "a" , "b" , "c" should be "c" , "b" , and "a" .
Since "d" does not appear in order , it can be at any position in the returned string. "dcba" , "cdba" , "cbda" are also valid outputs.

Input: order = "bcafg", s = "abcd"
Output: "bcad"
Explanation: The characters "b" , "c" , and "a" from order dictate the order for the characters in s . The character "d" in s does not appear in order , so its position is flexible.
Following the order of appearance in order , "b" , "c" , and "a" from s should be arranged as "b" , "c" , "a" . "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "dbca" or "bcda" would also be valid, as long as "b" , "c" , "a" maintain their order.
```

## 限制 Constraints

1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique.

## 官方 C 函式簽名 Signature

```c
char* customSortString(char* order, char* s) {
    
}
```
