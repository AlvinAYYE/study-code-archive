# 0187. Repeated DNA Sequences｜重複的 DNA 序列

- **難度**：中等
- **標籤**：雜湊表、字串、位元運算、滑動視窗
- **題目連結**：[LeetCode 0187](https://leetcode.com/problems/repeated-dna-sequences/)
- **C 程式**：[187_repeated-dna-sequences.c](./187_repeated-dna-sequences.c)

## 題目說明

DNA 字串只由 `A`、`C`、`G`、`T` 組成。給定 DNA 序列 `s`，找出所有長度恰好為 10、且在字串中出現超過一次的連續片段。每種重複片段只需回傳一次，順序不限。

## 範例

```text
輸入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
輸出：["AAAAACCCCC","CCCCCAAAAA"]

輸入：s = "AAAAAAAAAAAAA"
輸出：["AAAAAAAAAA"]
```

## 限制

- `1 <= s.length <= 10^5`。
- 每個字元都是 `A`、`C`、`G` 或 `T`。

## 解題步驟

1. 每個 DNA 字母可編成 2 個位元：A、C、G、T 分別用 00、01、10、11 表示；長度 10 的片段因此可編成 20 位元整數。
2. 從左到右滑動長度 10 的視窗。每讀一個字元，就把編碼左移 2 位、加入新字母，再用遮罩保留最近 20 位元。
3. 用編碼當索引記錄片段出現次數。第一次記為 1，第二次遇到時複製原字串片段加入答案；之後不再重複加入。
4. 編碼唯一對應一段 10 字母 DNA，因此無須為所有視窗建立字串鍵。

## 複雜度

- 時間：`O(n)`，每個字元更新一次編碼。
- 額外空間：`O(4^10 + n)`，固定大小的片段計數表及回傳結果。

## LeetCode C 函式簽名

```c
char** findRepeatedDnaSequences(char* s, int* returnSize);
```
