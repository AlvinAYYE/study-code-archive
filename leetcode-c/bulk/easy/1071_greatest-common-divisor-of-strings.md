# LeetCode 1071. Greatest Common Divisor of Strings

**難度：Easy**

## 題意完整翻譯

若字串 t 可以重複串接一次或多次，剛好組成字串 s，就說 t 可以整除 s。給定 str1 和 str2，請找出能同時整除這兩個字串的最長字串；若不存在，回傳空字串。

## 範例

1. str1 = "ABCABC", str2 = "ABC" → "ABC"
2. str1 = "ABABAB", str2 = "ABAB" → "AB"
3. str1 = "LEET", str2 = "CODE" → ""

## 限制

- 1 <= str1.length, str2.length <= 1000
- str1 與 str2 只含大寫英文字母

## 解題思路

1. 若兩字串有共同的重複基底，先串接 str1 + str2 和 str2 + str1，兩者必須完全相同；若不同，就沒有共同基底。
2. 計算兩個字串長度的最大公因數 g。共同基底長度必須整除兩個長度，因此最長者長度就是 g。
3. 配置 g + 1 個字元，複製 str1 的前 g 個字元並補上結尾符號後回傳。

## 複雜度

- 時間：O(len1 + len2)
- 空間：O(g)（回傳字串，g 為字串長度最大公因數）

## C 函式簽名

~~~c
char* gcdOfStrings(char* str1, char* str2);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。
