# 0771. Jewels and Stones《寶石與石頭》

- **Difficulty**: Easy
- **Tags**: hash-table, string
- **題目連結**: https://leetcode.com/problems/jewels-and-stones/
- **程式碼**: [`771_jewels-and-stones.c`](./771_jewels-and-stones.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

jewels 表示寶石種類，stones 表示手上的每顆石頭，求 stones 中屬於寶石的數量。英文字母大小寫視為不同種類，且 jewels 中的字元皆互異。

**思路**：以 256 大小的陣列標記所有寶石字元，再掃描 stones 累計被標記的字元。

## Problem Statement (English)

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Input: jewels = "z", stones = "ZZ"
Output: 0
```

## 限制 Constraints

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.

## 官方 C 函式簽名 Signature

```c
int numJewelsInStones(char* jewels, char* stones) {
    
}
```
