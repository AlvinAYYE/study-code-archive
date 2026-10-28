# 0029. Divide Two Integers｜兩數相除

- **難度**：中等
- **標籤**：數學、位元運算
- **題目連結**：[LeetCode 0029](https://leetcode.com/problems/divide-two-integers/)
- **C 程式**：[029_divide-two-integers.c](./029_divide-two-integers.c)

## 題目說明

給定整數 `dividend` 與非零整數 `divisor`，求兩者相除的商。不能使用乘法、除法或取餘數運算子。小數部分直接捨去，方向朝 0；例如 `7 / -3` 得到 `-2`。若商大於 `INT_MAX`，回傳 `INT_MAX`；若商小於 `INT_MIN`，回傳 `INT_MIN`。32 位元輸入中唯一會超過上界的情況是 `INT_MIN / -1`。

## 範例

```text
輸入：dividend = 10, divisor = 3
輸出：3
說明：10 / 3 = 3.333...，小數部分捨去。

輸入：dividend = 7, divisor = -3
輸出：-2
說明：商向 0 捨去，而不是向負無限大取整。
```

## 限制

- `-2^31 <= dividend, divisor <= 2^31 - 1`。
- `divisor != 0`。

## 解題步驟

1. 先處理唯一會超出正整數上界的情況：`INT_MIN / -1`，回傳 `INT_MAX`。
2. 將兩個數都保留在非正數範圍。這樣 `INT_MIN` 不必取絕對值，也不會溢位。
3. 從 `divisor` 開始連續加倍（等同於左移），同時把對應商的倍數也加倍；直到再加倍會超過剩餘被除數。
4. 從剩餘值扣掉最大的一塊，將對應倍數累加到負商，繼續處理剩餘部分。
5. 依兩個輸入的符號決定是否將負商取反。負商累加能正確涵蓋 `INT_MIN`。

## 複雜度

- 時間：`O(log^2 |dividend|)`，每次扣除一塊，並用加倍搜尋最大區塊。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int divide(int dividend, int divisor);
```
