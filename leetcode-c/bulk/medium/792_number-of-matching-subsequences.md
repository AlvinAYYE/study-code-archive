# LeetCode 0792. Number of Matching Subsequences

Title-CN: 符合子序列條件的字串數

## 題目

給定字串 `s` 和字串陣列 `words`，請計算有多少個 `words[i]` 是 `s` 的子序列。子序列可刪除原字串中的任意字元（也可以不刪），但留下的字元相對順序必須保持不變；不要求連續。

## 範例

1. 輸入：`s = "abcde"`、`words = ["a","bb","acd","ace"]`；輸出：`3`。符合的字串是 `a`、`acd`、`ace`。
2. 輸入：`s = "dsahjpjauf"`、`words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]`；輸出：`2`。

## 限制

- `1 <= s.length <= 5 * 10^4`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 50`
- `s` 和所有 `words[i]` 只含小寫英文字母

## 解題思路

1. 為 `s` 的每個索引預先記錄 26 個字母各自的下一次出現位置。若某字母之後不再出現，記成 `-1`。
2. 從每個 word 的第一個字母開始，在表中查它於目前位置之後的最近位置；找到後就把搜尋起點移到該位置的下一格。
3. 若所有字母都依序找到，這個 word 就是子序列，答案加一；任何字母找不到便不符合。
4. 預處理一次 `s`，再逐字查詢各 word，避免每個字都重新掃描整個 `s`。

## 複雜度

令 `n = s.length`、`T` 為所有 word 的字元總數。時間 `O(26n + T)`，額外空間 `O(26n)`。

## C 函式簽名

`int numMatchingSubseq(char* s, char** words, int wordsSize)`
