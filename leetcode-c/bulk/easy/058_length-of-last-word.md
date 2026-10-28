# 0058. Length of Last Word《最後一個單字的長度》

- **難度**：Easy
- **標籤**：string
- **題目連結**：https://leetcode.com/problems/length-of-last-word/
- **程式碼**：[`058_length-of-last-word.c`](./058_length-of-last-word.c)

## 題目說明

給定由英文字母與空格組成、且至少含一個單字的字串 `s`，回傳最後一個單字的長度。單字是只由非空格字元組成的最長連續子字串。

## 範例

```text
輸入：s = "Hello World"
輸出：5
說明：最後一個單字是 "World"。

輸入：s = "   fly me   to   the moon  "
輸出：4
說明：最後一個單字是 "moon"。

輸入：s = "luffy is still joyboy"
輸出：6
說明：最後一個單字是 "joyboy"。
```

## 限制

- `1 <= s.length <= 10^4`
- `s` 只包含英文字母與空格。
- `s` 至少包含一個單字。

## 直觀解題思路

1. 從字串最後一個字元向前掃描。
2. 尚未開始計數時，略過尾端空格。
3. 遇到非空格後開始累計長度；之後再次遇到空格，代表最後一個單字已完整掃完。

- 時間複雜度：`O(n)`
- 額外空間複雜度：`O(1)`

## 官方 C 函式簽名

```c
int lengthOfLastWord(char* s);
```
