# 0696. Count Binary Substrings《計數二進位子字串》

- **Difficulty**: Easy
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/count-binary-substrings/
- **程式碼**: [`696_count-binary-substrings.c`](./696_count-binary-substrings.c) — 社群解答（repo 6lc_git），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二進位字串 s，計算非空子字串中 0 與 1 數量相同，且所有 0 與所有 1 各自連續成群的數量。相同內容若出現在不同位置，仍要分別計入。

**思路**：線性掃描連續相同字元的群組，維護前一群與目前群的長度。每當目前群長度不超過前一群時，就新增一個符合條件的子字串。

## Problem Statement (English)

Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
Substrings that occur multiple times are counted the number of times they occur.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
```

## 限制 Constraints

1 <= s.length <= 105
s[i] is either '0' or '1'.

## 官方 C 函式簽名 Signature

```c
int countBinarySubstrings(char* s) {
    
}
```
