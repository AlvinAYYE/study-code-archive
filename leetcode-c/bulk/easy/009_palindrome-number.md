# 0009. Palindrome Number《回文數》

- **難度**：Easy
- **標籤**：math
- **題目連結**：https://leetcode.com/problems/palindrome-number/
- **程式碼**：[`009_palindrome-number.c`](./009_palindrome-number.c)

## 題目說明

給定整數 `x`。若它由左至右與由右至左讀取都相同，回傳 `true`；否則回傳 `false`。

## 範例

```text
輸入：x = 121
輸出：true
說明：正讀與反讀都是 121。

輸入：x = -121
輸出：false
說明：反讀會成為 121-，與原數不同。

輸入：x = 10
輸出：false
說明：反讀是 01。
```

## 限制

- `-2^31 <= x <= 2^31 - 1`

## 直觀解題思路

1. 負數的負號反向後位置不同，可直接回傳 `false`。
2. 保留原值 `x`，再從副本 `n` 逐位取出個位數，組成反轉值 `k`。
3. 每次計算 `k * 10 + d` 前先檢查是否超過 `int` 上限；若會溢位，反轉值不可能等於原數。
4. 最後比較 `k` 與 `x` 是否相同。

- 時間複雜度：`O(log |x|)`
- 額外空間複雜度：`O(1)`

## 官方 C 函式簽名

```c
bool isPalindrome(int x);
```
