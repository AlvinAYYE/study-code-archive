# 0013. Roman to Integer《羅馬數字轉整數》

- **Difficulty**: Easy
- **Tags**: hash-table, math, string
- **題目連結**: https://leetcode.com/problems/roman-to-integer/
- **程式碼**: [`013_roman-to-integer.c`](./013_roman-to-integer.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定有效的羅馬數字字串，將其轉換為整數。字串只含 I、V、X、L、C、D、M，且保證代表 1 到 3999 的有效數值，包括 IV、IX 等減法記法。

**思路**：程式由左至右把每個羅馬符號映射成數值並累加。若目前數值大於前一個數值，便扣回前一值的兩倍，以將先前的加法改成減法。

## Problem Statement (English)

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
Given a roman numeral, convert it to an integer.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Input: s = "III"
Output: 3
Explanation: III = 3.

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

## 限制 Constraints

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

## 官方 C 函式簽名 Signature

```c
int romanToInt(char* s) {
    
}
```
