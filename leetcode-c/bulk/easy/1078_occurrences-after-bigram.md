# LeetCode 1078. Occurrences After Bigram

**難度：Easy**

## 題意完整翻譯

給定文字 text，以及兩個單字 first、second。找出所有連續出現為「first second third」的三個單字組合，並依照它們在文字中出現的順序，回傳每次符合時的第三個單字 third。相同的第三個單字若出現多次，也要重複放入答案。

## 範例

1. text = "alice is a good girl she is a good student", first = "a", second = "good" → ["girl","student"]
2. text = "we will we will rock you", first = "we", second = "will" → ["we","rock"]

## 限制

- 1 <= text.length <= 1000
- text 只含小寫英文字母與空格，單字之間恰好一個空格，且沒有開頭或結尾空格
- 1 <= first.length, second.length <= 10
- first 與 second 只含小寫英文字母

## 解題思路

1. 由左至右掃描 text，每次找到一個單字的起點與結尾，不修改原字串。
2. 保留最近兩個單字的起點和長度。讀到新單字時，檢查前兩個是否依序等於 first、second。
3. 符合時，配置新字串複製目前單字，加入答案；接著把最近兩個單字往前更新。

## 複雜度

- 時間：O(text 長度 + 回傳文字總長度)
- 空間：O(text 長度 + 回傳資料)

## C 函式簽名

~~~c
char** findOcurrences(char* text, char* first, char* second, int* returnSize);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。
