# LeetCode 1160. Find Words That Can Be Formed by Characters

**難度：Easy**

## 題意完整翻譯

給定字串陣列 words 和字串 chars。若某個 word 的每個字母都能從 chars 取得，而且 chars 中每個字母每個 word 最多只能使用一次，該 word 就是可組成的字串。請回傳所有可組成字串的長度總和。

## 範例

1. words = ["cat","bt","hat","tree"], chars = "atach" → 6（可組成 "cat" 與 "hat"，長度為 3 + 3）
2. words = ["hello","world","leetcode"], chars = "welldonehoneyr" → 10（可組成 "hello" 與 "world"）

## 限制

- 1 <= words.length <= 1000
- 1 <= words[i].length, chars.length <= 100
- words[i] 與 chars 只含小寫英文字母

## 解題思路

1. 統計 chars 中 a 到 z 每個字母可用幾次。
2. 逐一處理每個 word，統計它需要的字母數量。
3. 只要任何字母需求量超過 chars 的可用量，這個 word 就不能組成；否則把它的長度加到總和。不同 word 可以各自重複使用 chars，因為每個字只獨立判斷。

## 複雜度

- 時間：O(chars 長度 + words 總字元數 + 26 × words.length)
- 空間：O(26)，也就是 O(1) 額外空間

## C 函式簽名

~~~c
int countCharacters(char** words, int wordsSize, char* chars);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。
