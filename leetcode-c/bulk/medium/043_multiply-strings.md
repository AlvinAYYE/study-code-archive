# 0043. Multiply Strings｜字串相乘

- **難度**：中等
- **標籤**：數學、字串、模擬
- **題目連結**：[LeetCode 0043](https://leetcode.com/problems/multiply-strings/)
- **C 程式**：[043_multiply-strings.c](./043_multiply-strings.c)

## 題目說明

給定兩個以字串表示的非負整數 `num1`、`num2`，回傳它們相乘後的字串。不能使用大數套件，也不能把整個輸入直接轉成整數。

## 範例

```text
輸入：num1 = "2", num2 = "3"
輸出："6"

輸入：num1 = "123", num2 = "456"
輸出："56088"
```

## 限制

- `1 <= num1.length, num2.length <= 200`。
- 兩個字串只包含數字。
- 除了數字 0 本身，不會有前導零。

## 解題步驟

1. 兩個長度為 `m`、`n` 的數相乘，結果最多有 `m + n` 位；先建立一個整數陣列存每一位。
2. 從個位數開始，逐對相乘。`num1[i] * num2[j]` 的結果會影響 `digits[i + j + 1]`，進位加到前一格 `digits[i + j]`。
3. 乘完後略過結果陣列最前面的 0，再將每位數轉成字元。
4. 若任一輸入是 0，直接回傳字串 `"0"`。

## 複雜度

- 時間：`O(m × n)`，逐對相乘每一位數。
- 額外空間：`O(m + n)`，存放乘積各位數與回傳字串。

## LeetCode C 函式簽名

```c
char* multiply(char* num1, char* num2);
```
