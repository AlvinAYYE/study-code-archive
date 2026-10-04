# 0944. Delete Columns to Make Sorted《刪除欄位以使其有序》

- **Difficulty**: Easy
- **Tags**: array, string
- **題目連結**: https://leetcode.com/problems/delete-columns-to-make-sorted/
- **程式碼**: [`944_delete-columns-to-make-sorted.c`](./944_delete-columns-to-make-sorted.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n 個等長字串，可將它們逐列排成一個字元網格。若某一欄自上而下不是非遞減字典序，便必須刪除該欄。請回傳需要刪除的欄位數量。

**思路**：逐一比較每對相鄰列，將任何出現下方字元小於上方字元的欄位標記，最後計算被標記欄位數。

## Problem Statement (English)

You are given an array of n strings strs, all of the same length.
The strings can be arranged such that there is one on each line, making a grid.
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted, while column 1 ('b', 'c', 'a') is not, so you would delete column 1.
Return the number of columns that you will delete.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
abc
bce
cae

Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.

Input: strs = ["a","b"]
Output: 0
Explanation: The grid looks as follows:
  a
  b
Column 0 is the only column and is sorted, so you will not delete any columns.

Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
  zyx
  wvu
  tsr
All 3 columns are not sorted, so you will delete all 3.
```

## 限制 Constraints

n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 1000
strs[i] consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
int minDeletionSize(char** strs, int strsSize) {
    
}
```
