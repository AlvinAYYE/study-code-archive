# 0172. Factorial Trailing Zeroes｜階乘後綴零

- **難度**：中等
- **標籤**：數學
- **題目連結**：[LeetCode 0172](https://leetcode.com/problems/factorial-trailing-zeroes/)
- **C 程式**：[172_factorial-trailing-zeroes.c](./172_factorial-trailing-zeroes.c)

## 題目說明

給定非負整數 `n`，計算 `n!` 十進位表示法末尾有幾個連續的零。`n!` 是從 1 到 `n` 所有整數的乘積；不需要真的算出階乘。

## 範例

```text
輸入：n = 3
輸出：0
說明：3! = 6，末尾沒有零。

輸入：n = 5
輸出：1
說明：5! = 120，末尾有一個零。

輸入：n = 0
輸出：0
```

## 限制

- `0 <= n <= 10^4`。

## 解題步驟

1. 每個末尾的 0 都來自一組因數 `2 × 5`；階乘中的 2 比 5 多，所以只需計算因數 5 的數量。
2. `n`、`n/5`、`n/25` 等整除結果，分別計算因數中至少含一個、兩個、三個 5 的數字。
3. 反覆令 `n = n / 5` 並累加商，直到商為 0。

## 複雜度

- 時間：`O(log_5 n)`。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int trailingZeroes(int n);
```
