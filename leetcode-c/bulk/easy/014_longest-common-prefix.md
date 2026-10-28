# 0014. Longest Common Prefix《最長共同前綴》

- **難度**：Easy
- **標籤**：array、string、trie
- **題目連結**：https://leetcode.com/problems/longest-common-prefix/
- **程式碼**：[`014_longest-common-prefix.c`](./014_longest-common-prefix.c)

## 題目說明

給定字串陣列 `strs`，找出所有字串共同擁有的最長開頭部分。若第一個字元就不同，回傳空字串 `""`。

## 範例

```text
輸入：strs = ["flower","flow","flight"]
輸出："fl"

輸入：strs = ["dog","racecar","car"]
輸出：""
說明：三個字串沒有共同前綴。
```

## 限制

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- 非空字串只包含小寫英文字母。

## 直觀解題思路

1. 以第一個字串作為候選答案，從索引 0 開始逐欄比較。
2. 對每一欄，檢查其餘字串在相同位置的字元；若字串已結束，讀到的 `\0` 也會形成不相同。
3. 第一次不同的位置就是共同前綴終點，在第一個字串該處寫入 `\0` 並回傳。

- 時間複雜度：`O(S)`，`S` 為實際比較的總字元數
- 額外空間複雜度：`O(1)`

## 官方 C 函式簽名

```c
char* longestCommonPrefix(char** strs, int strsSize);
```
