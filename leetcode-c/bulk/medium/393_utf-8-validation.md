# 0393. UTF-8 Validation《UTF-8 驗證》

- **Difficulty**: Medium
- **Tags**: array, bit-manipulation
- **題目連結**: https://leetcode.com/problems/utf-8-validation/
- **程式碼**: [`393_utf-8-validation.c`](./393_utf-8-validation.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 data，判斷其是否能表示合法的 UTF-8 編碼序列。每個元素只使用最低 8 位元作為一個位元組；字元可由 1 至 4 個位元組組成，多位元組字元後續位元組必須以 10 開頭。

**思路**：掃描每個位元組並記錄尚需的續接位元組數；新字元先由前導連續 1 的數量判定長度，續接位元組則驗證前兩位為 10。

## Problem Statement (English)

Given an integer array data representing the data, return whether it is a valid UTF-8 encoding (i.e. it translates to a sequence of valid UTF-8 encoded characters).
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
This is how the UTF-8 encoding would work:
x denotes a bit in the binary form of a byte that may be either 0 or 1.
Note: The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Number of Bytes   |        UTF-8 Octet Sequence
                       |              (binary)
   --------------------+-----------------------------------------
            1          |   0xxxxxxx
            2          |   110xxxxx 10xxxxxx
            3          |   1110xxxx 10xxxxxx 10xxxxxx
            4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Input: data = [197,130,1]
Output: true
Explanation: data represents the octet sequence: 11000101 10000010 00000001.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.

Input: data = [235,140,4]
Output: false
Explanation: data represented the octet sequence: 11101011 10001100 00000100.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
```

## 限制 Constraints

1 <= data.length <= 2 * 104
0 <= data[i] <= 255

## 官方 C 函式簽名 Signature

```c
bool validUtf8(int* data, int dataSize) {
    
}
```
