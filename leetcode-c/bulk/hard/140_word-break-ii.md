# 0140. 單字拆分 II（Word Break II）

- **難度**：Hard
- **標籤**：字串、動態規劃、回溯、記憶化
- **題目連結**：[LeetCode 140](https://leetcode.com/problems/word-break-ii/)
- **解答檔案**：[140_word-break-ii.c](./140_word-break-ii.c)

## 題目完整翻譯

給定字串 `s` 和字典 `wordDict`。請在 `s` 的字元之間加入空格，把整個字串切成數個單字，並回傳所有可能的句子。每個切出的單字都必須出現在 `wordDict` 中。字典裡的同一個單字可以重複使用。

如果沒有任何切法，回傳空陣列。答案的排列順序不限。

## 範例

```text
輸入：s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
輸出：["cats and dog","cat sand dog"]

輸入：s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
輸出：["pine apple pen apple","pineapple pen apple","pine applepen apple"]
說明：同一個字典單字可以重複使用。

輸入：s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
輸出：[]
```

## 限制

- `1 <= s.length <= 20`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 10`
- `s` 和字典單字只包含小寫英文字母；字典中的字串互不相同。
- 所有答案字串的總長度不超過 `10^5`。

## 解題思路

1. 把每個字串位置視為一個節點。若從位置 `i` 開始的某個字典單字能匹配，就建立 `i -> 單字結尾位置` 的邊。
2. 從左到右建立這張圖；只有能從位置 0 到達的位置才需要繼續比對。
3. 從位置 0 做深度優先搜尋，沿著每條邊記下目前選到的單字；到達字串結尾時，把單字以空格接成一個答案。
4. 若位置 `s.length` 無法到達，就沒有可組成的句子。

例如 `catsanddog`，第一個單字可選 `cat` 或 `cats`；沿著每種選擇繼續找，最後分別得到 `cat sand dog` 和 `cats and dog`。

## 複雜度

- 建立切分圖：`O(L × D × W)`，其中 `L` 是 `s` 長度、`D` 是字典單字數、`W` 是單字最大長度。
- 列出答案還需與輸出總長度成正比；答案數量本身可能很大。
- 額外空間：`O(L + E)`，`E` 是圖上的可行切分邊，不含答案輸出。

## C 函式介面

```c
char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize);
```

回傳陣列及其中的字串都由解答配置；呼叫端需負責釋放。
