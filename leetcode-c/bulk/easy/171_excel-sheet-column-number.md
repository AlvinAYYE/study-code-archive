# 0171. Excel Sheet Column Number《Excel 欄位序號》

- 難度：Easy
- 題目連結：https://leetcode.com/problems/excel-sheet-column-number/

## 題目翻譯

給定 Excel 欄位名稱 columnTitle，回傳對應的欄號。字母 A 到 Z 代表 1 到 26，因此 AA 是 27、AB 是 28。

## 範例

~~~text
A -> 1, B -> 2, ..., Z -> 26, AA -> 27, AB -> 28

輸入：columnTitle = "A"
輸出：1

輸入：columnTitle = "AB"
輸出：28

輸入：columnTitle = "ZY"
輸出：701
~~~

## 限制

- 1 <= columnTitle.length <= 7
- 只包含大寫英文字母 A-Z。
- columnTitle 的範圍是 A 到 FXSHRXW。

## 解題步驟

1. 從左到右讀取每個字母。
2. 將已累積的欄號乘 26，為新字母空出一位。
3. 把新字母的值加上去：A=1、B=2，依此類推。

例如 AB：先得到 A 的值 1，再計算 1*26+2，答案為 28。

## 複雜度

- 時間：O(n)，每個字母處理一次。
- 空間：O(1)。

## C 函式簽名

~~~c
int titleToNumber(char* columnTitle);
~~~
