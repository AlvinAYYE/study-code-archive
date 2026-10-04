# 0006. Zigzag Conversion《Z 字形变换》

- **Difficulty**: Medium
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/zigzag-conversion/
- **程式碼**: [`006_zigzag-conversion.c`](./006_zigzag-conversion.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

將字串依指定的列數 numRows 以 Z 字形排列，再按照每一列由上到下讀出並回傳新字串。例如以 3 列排列後，會交錯經過直行與斜行的位置。

**思路**：程式逐列收集字元：首尾列固定以一個週期跳躍，中間列則交替使用兩種間距。結果寫入新配置的字串並回傳；只有一列時直接回傳原字串。

## Problem Statement (English)

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
P   A   H   N
A P L S I I G
Y   I   R

string convert(string s, int numRows);

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

## 限制 Constraints

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

## 官方 C 函式簽名 Signature

```c
char* convert(char* s, int numRows) {
    
}
```
