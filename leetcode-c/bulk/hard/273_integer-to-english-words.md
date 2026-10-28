# 0273. 整數轉英文單字（Integer to English Words）

- **難度**：Hard
- **標籤**：數學、字串
- **題目連結**：[LeetCode 273](https://leetcode.com/problems/integer-to-english-words/)
- **解答檔案**：[273_integer-to-english-words.c](./273_integer-to-english-words.c)

## 題目完整翻譯

給定非負整數 `num`，請把它轉成英文單字表示並回傳。單字首字母大寫，單字之間以一個空格分隔，不包含連字號或「and」。

## 範例

```text
輸入：num = 123
輸出："One Hundred Twenty Three"

輸入：num = 12345
輸出："Twelve Thousand Three Hundred Forty Five"

輸入：num = 1234567
輸出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
```

## 限制

- `0 <= num <= 2^31 - 1`

## 解題思路

1. 把數字由高位切成每組三位：Billion、Million、Thousand、個位組。
2. 對每組 0 到 999，依序輸出百位、十位與個位；10 到 19 有各自的英文單字。
3. 數值為 0 的組別跳過，避免多出空格或多餘的單位名稱。
4. 若整個數值是 0，答案就是 `Zero`。

例如 `1234567` 切成 `1 | 234 | 567`，分別轉成 `One Million`、`Two Hundred Thirty Four Thousand`、`Five Hundred Sixty Seven`，再依序接起來。

## 複雜度

- 時間：`O(1)`，最多處理四組三位數。
- 額外空間：`O(1)`，不含回傳字串。

## C 函式介面

```c
char* numberToWords(int num);
```

回傳字串由解答配置，呼叫端需負責釋放。
