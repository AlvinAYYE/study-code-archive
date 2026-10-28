# 0205. Isomorphic Strings《同構字串》

- 難度：Easy
- 題目連結：https://leetcode.com/problems/isomorphic-strings/

## 題目翻譯

判斷字串 s 和 t 是否同構。若能將 s 中每種字元一致地替換成另一個字元，使結果等於 t，兩字串就同構。替換必須保持字元順序；同一來源字元不能在不同位置映射到不同字元，也不能讓兩種來源字元映射到同一個目標字元。字元可以映射到自己。

## 範例

~~~text
輸入：s = "egg", t = "add"
輸出：true

輸入：s = "foo", t = "bar"
輸出：false
因為 s 中兩個 o 無法同時映射到 a 和 r。

輸入：s = "paper", t = "title"
輸出：true
~~~

## 限制

- 1 <= s.length <= 5 * 10^4
- t.length == s.length
- s 和 t 只包含有效 ASCII 字元。

## 解題步驟

1. 建立兩張 128 格的表：一張記錄 s 字元對應到哪個 t 字元，另一張記錄反向對應。
2. 逐位置檢查字元。若兩側都還沒有映射，就同時建立正向與反向映射。
3. 若任一側已經有映射，兩張表都必須符合目前這一對字元；否則回傳 false。
4. 全部位置都符合時回傳 true。

## 複雜度

- 時間：O(n)，每個字元檢查一次。
- 空間：O(1)，兩張表大小固定為 ASCII 字元數。

## C 函式簽名

~~~c
bool isIsomorphic(char* s, char* t);
~~~
