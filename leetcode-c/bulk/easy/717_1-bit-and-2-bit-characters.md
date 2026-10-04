# 0717. 1-bit and 2-bit Characters《1 位元與 2 位元字元》

- **Difficulty**: Easy
- **Tags**: array
- **題目連結**: https://leetcode.com/problems/1-bit-and-2-bit-characters/
- **程式碼**: [`717_1-bit-and-2-bit-characters.c`](./717_1-bit-and-2-bit-characters.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

編碼中，0 表示一個 1 位元字元，而 10 或 11 表示一個 2 位元字元。給定最後一位必為 0 的位元陣列，判斷最後一個字元是否必定為 1 位元字元。

**思路**：從開頭依目前位元前進：遇到 0 前進一格，遇到 1 前進兩格。最後指標正好停在末位時，代表最後字元是 1 位元字元。

## Problem Statement (English)

We have two special characters:
Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.

Input: bits = [1,1,1,0]
Output: false
Explanation: The only way to decode it is two-bit character and two-bit character.
So the last character is not one-bit character.
```

## 限制 Constraints

1 <= bits.length <= 1000
bits[i] is either 0 or 1.

## 官方 C 函式簽名 Signature

```c
bool isOneBitCharacter(int* bits, int bitsSize) {
    
}
```
