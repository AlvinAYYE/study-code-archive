# 0151. Reverse Words in a String｜反轉字串中的單字

- **難度**：中等
- **標籤**：雙指標、字串
- **題目連結**：[LeetCode 0151](https://leetcode.com/problems/reverse-words-in-a-string/)
- **C 程式**：[151_reverse-words-in-a-string.c](./151_reverse-words-in-a-string.c)

## 題目說明

給定字串 `s`，將單字順序反轉後回傳。單字是由非空白字元組成的片段；輸入可能有開頭、結尾空白，或單字間有多個空白。輸出單字之間只能有一個空格，且不能有前後空格。

## 範例

```text
輸入：s = "the sky is blue"
輸出："blue is sky the"

輸入：s = "  hello world  "
輸出："world hello"

輸入：s = "a good   example"
輸出："example good a"
```

## 限制

- `1 <= s.length <= 10^4`。
- `s` 只包含英文字母、數字和空格。
- `s` 至少有一個單字。

## 解題步驟

1. 從字串最右邊開始掃描，先跳過空格，再找到一個單字的左右界。
2. 將該單字複製到新字串；如果前面已經複製過單字，先補上一個空格。
3. 繼續往左找下一個單字，直到掃描完整個輸入。
4. 在輸出結尾補上字串結束符號。因為只複製單字並自行插入分隔空格，輸出不會有多餘空格。

## 複雜度

- 時間：`O(n)`，輸入字元最多掃描一次並複製一次。
- 額外空間：`O(n)`，配置回傳字串。

## LeetCode C 函式簽名

```c
char* reverseWords(char* s);
```
