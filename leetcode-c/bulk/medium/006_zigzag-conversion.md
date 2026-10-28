# 0006. Zigzag Conversion｜Z 字形變換

- **難度**：中等
- **標籤**：字串
- **題目連結**：[LeetCode 0006](https://leetcode.com/problems/zigzag-conversion/)
- **C 程式**：[006_zigzag-conversion.c](./006_zigzag-conversion.c)

## 題目說明

將字串 `s` 依 `numRows` 列寫成 Z 字形：先往下填滿，再斜向上填回第一列，反覆進行。最後把每一列由上到下串起來回傳。

## 範例

```text
輸入：s = "PAYPALISHIRING", numRows = 3
排列：
P   A   H   N
A P L S I I G
Y   I   R
輸出："PAHNAPLSIIGYIR"

輸入：s = "PAYPALISHIRING", numRows = 4
輸出："PINALSIGYAHRPI"

輸入：s = "A", numRows = 1
輸出："A"
```

## 限制

- `1 <= s.length <= 1000`。
- `s` 由大小寫英文字母、逗號與句點組成。
- `1 <= numRows <= 1000`。

## 解題步驟

1. 先沿著 Z 字形走一次，統計每一列會收到幾個字元；`row` 是目前列，`direction` 是向下 `1` 或向上 `-1`。
2. 累加各列起始位置，讓 `nextPosition[row]` 指向該列下一個可填入的答案索引。
3. 再按相同路徑走一次，把每個字元寫進它所屬列的答案區段。
4. 因為答案區段按照列的順序排列，第二次走訪完成後就是所求結果。只有一列或列數不小於字串長度時，直接複製原字串。

## 複雜度

- 時間：`O(n + r)`，兩次走訪字串並初始化 `r` 列。
- 額外空間：`O(n + r)`，包含回傳字串和每列的位置資料。

## LeetCode C 函式簽名

```c
char* convert(char* s, int numRows);
```
