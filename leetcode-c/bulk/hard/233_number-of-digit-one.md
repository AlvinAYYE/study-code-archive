# 0233. 數字 1 的個數（Number of Digit One）

- **難度**：Hard
- **標籤**：數學、動態規劃、遞迴
- **題目連結**：[LeetCode 233](https://leetcode.com/problems/number-of-digit-one/)
- **解答檔案**：[233_number-of-digit-one.c](./233_number-of-digit-one.c)

## 題目完整翻譯

給定非負整數 `n`，請計算從 `0` 到 `n`（包含兩端）的所有整數表示中，數字 `1` 總共出現幾次。

## 範例

```text
輸入：n = 13
輸出：6
說明：1、10、11、12、13 中共有六個數字 1。

輸入：n = 0
輸出：0
```

## 限制

- `0 <= n <= 10^9`

## 解題思路

1. 分別計算個位、十位、百位等每個位置上的 `1` 出現次數。
2. 對目前位，拆出 `higher`（左側高位）、`current`（目前數字）、`lower`（右側低位）。
3. 若目前位小於 1，該位貢獻 `higher × 位權`；若等於 1，貢獻 `higher × 位權 + lower + 1`；若大於 1，貢獻 `(higher + 1) × 位權`。
4. 把每個位數的貢獻加總。

以 `n = 13` 的十位為例：`higher = 0`、`current = 1`、`lower = 3`，所以十位的 1 出現 `0 × 10 + 3 + 1 = 4` 次；個位再貢獻 2 次，總共 6 次。

## 複雜度

- 時間：`O(log n)`。
- 額外空間：`O(1)`。

## C 函式介面

```c
int countDigitOne(int n);
```
