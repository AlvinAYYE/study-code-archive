# 0139. Word Break｜單字拆分

- **難度**：中等
- **標籤**：陣列、雜湊表、字串、動態規劃
- **題目連結**：[LeetCode 0139](https://leetcode.com/problems/word-break/)
- **C 程式**：[139_word-break.c](./139_word-break.c)

## 題目說明

給定字串 `s` 和字典 `wordDict`，判斷 `s` 是否能切成一個或多個字典中的單字。字典中的同一個單字可以重複使用；切分後所有字元都必須剛好用完。

## 範例

```text
輸入：s = "leetcode", wordDict = ["leet","code"]
輸出：true
說明：可切成 "leet code"。

輸入：s = "applepenapple", wordDict = ["apple","pen"]
輸出：true
說明：可重複使用 "apple"，切成 "apple pen apple"。

輸入：s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
輸出：false
```

## 限制

- `1 <= s.length <= 300`。
- `1 <= wordDict.length <= 1000`。
- `1 <= wordDict[i].length <= 20`。
- `s` 和字典單字只包含小寫英文字母；字典中的字串互不相同。

## 解題步驟

1. `dp[i]` 表示 `s` 的前 `i` 個字元能否被字典單字完整切分，先令 `dp[0] = true`，代表空前綴可以作為切分起點。
2. 對每個結尾位置 `end`，逐一檢查字典單字 `word`。
3. 若單字長度不超過 `end`、其前方前綴 `dp[end - length]` 可達，且 `s` 對應片段與單字相同，就令 `dp[end] = true`。
4. 所有位置都檢查後，`dp[s.length]` 就是整個字串能否拆分的答案。

## 複雜度

- 時間：`O(n × d × L)`，`n` 是字串長度、`d` 是字典大小、`L` 是單字最大長度。
- 額外空間：`O(n)`，保存每個前綴的可拆分狀態。

## LeetCode C 函式簽名

```c
bool wordBreak(char* s, char** wordDict, int wordDictSize);
```
