# 0119. Pascal's Triangle II《楊輝三角 II》

- 難度：Easy
- 題目連結：https://leetcode.com/problems/pascals-triangle-ii/

## 題目翻譯

給定從 0 開始的列索引 rowIndex，回傳楊輝三角中該列的所有數字。例如 rowIndex=0 是第一列 [1]，rowIndex=3 是 [1,3,3,1]。

## 範例

~~~text
輸入：rowIndex = 3
輸出：[1,3,3,1]

輸入：rowIndex = 0
輸出：[1]

輸入：rowIndex = 1
輸出：[1,1]
~~~

## 限制

- 0 <= rowIndex <= 33
- 進階要求：額外空間只使用 O(rowIndex)。

## 解題步驟

1. 配置 rowIndex + 1 個整數，先令 row[0] = 1。
2. 依序建立第 1 列到第 rowIndex 列。
3. 每一列從最右邊往左更新：row[col] += row[col - 1]。
4. 必須由右往左，這樣 row[col - 1] 還是上一列的值，不會被提前改掉。

## 複雜度

- 時間：O(rowIndex²)。
- 空間：O(rowIndex)，只保存目前的一列。

## C 函式簽名

~~~c
int* getRow(int rowIndex, int* returnSize);
~~~
