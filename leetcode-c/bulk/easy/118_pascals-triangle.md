# 0118. Pascal's Triangle《楊輝三角》

- 難度：Easy
- 題目連結：https://leetcode.com/problems/pascals-triangle/

## 題目翻譯

給定整數 numRows，回傳楊輝三角的前 numRows 列。每一列的第一個與最後一個數字都是 1；其餘位置的數字，是上一列正上方左右兩個數字的總和。

## 範例

~~~text
輸入：numRows = 5
輸出：[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

輸入：numRows = 1
輸出：[[1]]
~~~

## 限制

- 1 <= numRows <= 30

## 解題步驟

1. 配置 numRows 個列陣列，第 row 列的長度是 row + 1。
2. 將每列最左和最右設為 1。
3. 對中間位置 col，將上一列第 col-1 與第 col 個數字相加。
4. 回傳二維陣列、總列數，以及每列長度。

## 複雜度

- 時間：O(numRows²)，需填入三角形內所有數字。
- 空間：O(numRows²)，回傳的三角形本身需要這些空間。

## C 函式簽名

~~~c
int** generate(int numRows, int* returnSize, int** returnColumnSizes);
~~~
