# 0168. Excel Sheet Column Title《Excel 欄位標題》

- 難度：Easy
- 題目連結：https://leetcode.com/problems/excel-sheet-column-title/

## 題目翻譯

給定正整數 columnNumber，回傳 Excel 表格中對應的欄位名稱。欄號 1 到 26 對應 A 到 Z；第 27 欄開始使用 AA、AB 等字母組合。

## 範例

~~~text
A -> 1, B -> 2, ..., Z -> 26, AA -> 27, AB -> 28

輸入：columnNumber = 1
輸出："A"

輸入：columnNumber = 28
輸出："AB"

輸入：columnNumber = 701
輸出："ZY"
~~~

## 限制

- 1 <= columnNumber <= 2^31 - 1

## 解題步驟

1. 這種欄號從 1 開始，沒有代表 0 的字母，所以每次先把數字減 1。
2. 對 26 取餘數，餘數 0 到 25 對應 A 到 Z，將字母由低位開始存起來。
3. 將數字除以 26，繼續處理更高位。
4. 把倒著存的字母反轉後回傳。

## 複雜度

- 時間：O(log26 n)，每輪處理一個 26 進位位數。
- 空間：O(log26 n)，用來存放結果字串。

## C 函式簽名

~~~c
char* convertToTitle(int columnNumber);
~~~

回傳字串由呼叫端負責釋放。
~~~
