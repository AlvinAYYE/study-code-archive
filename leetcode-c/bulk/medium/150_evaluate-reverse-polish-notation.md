# 0150. Evaluate Reverse Polish Notation｜計算逆波蘭表示法

- **難度**：中等
- **標籤**：陣列、數學、堆疊
- **題目連結**：[LeetCode 0150](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
- **C 程式**：[150_evaluate-reverse-polish-notation.c](./150_evaluate-reverse-polish-notation.c)

## 題目說明

給定字串陣列 `tokens`，內容是逆波蘭表示法（RPN）的算式。數字先放入，運算子出現時就對前面兩個運算元計算；請回傳算式結果。除法結果向 0 截斷。

## 範例

```text
輸入：tokens = ["2","1","+","3","*"]
輸出：9
說明：(2 + 1) × 3 = 9。

輸入：tokens = ["4","13","5","/","+"]
輸出：6
說明：4 + (13 / 5) = 6。

輸入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
輸出：22
```

## 限制

- `1 <= tokens.length <= 10^4`。
- token 是 `+`、`-`、`*`、`/` 其中一個運算子，或介於 `-200` 到 `200` 的整數。
- 除法不會除以 0；中間值與最終答案可放入 32 位元有號整數。

## 解題步驟

1. 從左到右讀取 token，使用陣列模擬堆疊。
2. 遇到數字就轉成整數推入堆疊。
3. 遇到運算子時，先彈出右運算元，再彈出左運算元；順序不能顛倒，尤其是減法和除法。
4. 計算 `left operator right`，再把結果推回堆疊。
5. 所有 token 處理完成後，堆疊頂端就是答案。

## 複雜度

- 時間：`O(n)`，每個 token 處理一次。
- 額外空間：`O(n)`，堆疊最多保存所有數字。

## LeetCode C 函式簽名

```c
int evalRPN(char** tokens, int tokensSize);
```
