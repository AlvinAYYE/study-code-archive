# 0125. Valid Palindrome《有效回文》

- 難度：Easy
- 題目連結：https://leetcode.com/problems/valid-palindrome/

## 題目翻譯

先把大寫字母視為小寫，再移除所有非英文字母與數字的字元。若剩下的內容從左到右和從右到左相同，就回傳 true；否則回傳 false。移除字元後若成為空字串，也算回文。

## 範例

~~~text
輸入：s = "A man, a plan, a canal: Panama"
輸出：true
整理後為 "amanaplanacanalpanama"，正反讀相同。

輸入：s = "race a car"
輸出：false

輸入：s = " "
輸出：true
移除空格後是空字串。
~~~

## 限制

- 1 <= s.length <= 2 * 10^5
- s 只包含可列印 ASCII 字元。

## 解題步驟

1. 用 left、right 分別指向字串左右兩端。
2. 遇到非英數字元時，移動該側指標跳過它。
3. 比較兩側字元的小寫形式；不同就不是回文。
4. 相同時兩指標都向中央移動，直到交會。

## 複雜度

- 時間：O(n)，每個字元最多檢查一次。
- 空間：O(1)，只使用兩個指標及暫存字元。

## C 函式簽名

~~~c
bool isPalindrome(char* s);
~~~
