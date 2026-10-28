# 392 Is Subsequence：判斷子序列

**難度：** Easy

## 題意完整翻譯

給定字串 s 與 t，判斷 s 是否為 t 的子序列。子序列是從原字串刪除零個或多個字元後形成的字串，但保留下來的字元相對順序必須不變。例如 ace 是 abcde 的子序列，aec 則不是。

## 範例

### 範例 1

- 輸入：s = "abc", t = "ahbgdc"
- 輸出：true
- 說明：依序可在 t 中找到 a、b、c。

### 範例 2

- 輸入：s = "axc", t = "ahbgdc"
- 輸出：false
- 說明：找到 a 後，後面沒有 x，因此無法按順序找到整個 s。

## 限制

- 0 <= s.length <= 100
- 0 <= t.length <= 10^4
- s 與 t 都只含小寫英文字母

## 解題思路

1. 用 i 指向 s 目前要比對的字元。
2. 從左到右掃描 t；若 t[j] 等於 s[i]，就讓 i 前進，表示成功配對一個字元。
3. t 掃描完後，若 s[i] 已到結尾，表示所有字元都按順序找到，回傳 true。空字串也是任何字串的子序列。

## 複雜度

- 時間：O(|s| + |t|)，每個字串最多掃描一次。
- 空間：O(1)，只使用索引變數。

## C 函式簽名

~~~c
bool isSubsequence(char* s, char* t);
~~~

## 程式如何運作

~~~c
bool isSubsequence(char* s, char* t) {
    int sIndex = 0;
    int tIndex = 0;

    while (s[sIndex] != '\0' && t[tIndex] != '\0') {
        if (s[sIndex] == t[tIndex]) {
            ++sIndex; /* 配對到下一個需要的字元。 */
        }
        ++tIndex;
    }

    return s[sIndex] == '\0';
}
~~~
