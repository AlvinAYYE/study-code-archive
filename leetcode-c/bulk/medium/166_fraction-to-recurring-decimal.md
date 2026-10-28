# 0166. Fraction to Recurring Decimal｜分數轉循環小數

- **難度**：中等
- **標籤**：雜湊表、數學、字串
- **題目連結**：[LeetCode 0166](https://leetcode.com/problems/fraction-to-recurring-decimal/)
- **C 程式**：[166_fraction-to-recurring-decimal.c](./166_fraction-to-recurring-decimal.c)

## 題目說明

給定分子 `numerator` 和非零分母 `denominator`，回傳除法結果的字串。有限小數直接輸出；若小數部分開始循環，將循環的那一段用括號括起來，例如 `0.333...` 表示為 `0.(3)`。答案長度保證小於 `10^4`。

## 範例

```text
輸入：numerator = 1, denominator = 2
輸出："0.5"

輸入：numerator = 2, denominator = 1
輸出："2"

輸入：numerator = 4, denominator = 333
輸出："0.(012)"
```

## 限制

- `-2^31 <= numerator, denominator <= 2^31 - 1`。
- `denominator != 0`。
- 答案字串長度小於 `10^4`。

## 解題步驟

1. 先用較寬的整數型別取分子、分母的絕對值，避免直接對最小 32 位元整數取負造成溢位；再輸出符號和整數部分。
2. 取餘數後逐位產生小數：每輪把餘數乘 10，商數就是下一位，新的餘數繼續處理。
3. 用雜湊表記錄每個餘數第一次出現的位置。若餘數為 0，小數結束；若餘數重複，代表從第一次出現的位置開始循環。
4. 發現重複餘數時，在第一次出現的位置插入左括號，並在目前輸出末尾加右括號。

## 複雜度

- 時間：`O(L)` 平均，`L` 是小數位數；每個餘數平均常數時間查表。
- 額外空間：`O(L)`，保存餘數首次出現位置及輸出字串。

## LeetCode C 函式簽名

```c
char* fractionToDecimal(int numerator, int denominator);
```
