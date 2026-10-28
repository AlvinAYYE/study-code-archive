# 0028. Find the Index of the First Occurrence in a String《找出字串中第一個符合項的索引》

- **難度**：Easy
- **標籤**：two-pointers、string、string-matching
- **題目連結**：https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
- **程式碼**：[`028_find-the-index-of-the-first-occurrence-in-a-string.c`](./028_find-the-index-of-the-first-occurrence-in-a-string.c)

## 題目說明

給定字串 `haystack` 與 `needle`，回傳 `needle` 在 `haystack` 中第一次出現的起始索引；若 `needle` 不是 `haystack` 的子字串，回傳 `-1`。

## 範例

```text
輸入：haystack = "sadbutsad", needle = "sad"
輸出：0
說明："sad" 出現在索引 0 與 6，第一次出現的位置是 0。

輸入：haystack = "leetcode", needle = "leeto"
輸出：-1
說明："leeto" 並未出現在 "leetcode" 中。
```

## 限制

- `1 <= haystack.length, needle.length <= 10^4`
- `haystack` 與 `needle` 只包含小寫英文字母。

## 直觀解題思路

1. `needle` 長度為 `l2`，因此起點最多枚舉到 `l1 - l2`；再往後的剩餘字元不足。
2. 對每個可能起點 `i`，從 `needle[0]` 開始逐字元比較。
3. 若 `l2` 個字元全部相同，立即回傳 `i`；由左往右搜尋可保證這是第一次出現的位置。
4. 所有位置都失敗時回傳 `-1`。

- 最壞時間複雜度：`O((l1-l2+1) * l2)`
- 額外空間複雜度：`O(1)`

## 官方 C 函式簽名

```c
int strStr(char* haystack, char* needle);
```
