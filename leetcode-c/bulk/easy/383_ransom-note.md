# 383 Ransom Note：贖金信

**難度：** Easy

## 題意完整翻譯

給定字串 ransomNote 與 magazine，判斷能否只使用 magazine 中的字母拼出 ransomNote。magazine 的每個字母最多只能使用一次。

## 範例

### 範例 1

- 輸入：ransomNote = "a", magazine = "b"
- 輸出：false
- 說明：magazine 沒有字母 a。

### 範例 2

- 輸入：ransomNote = "aa", magazine = "ab"
- 輸出：false
- 說明：magazine 只有一個 a，不足以拼出兩個 a。

### 範例 3

- 輸入：ransomNote = "aa", magazine = "aab"
- 輸出：true
- 說明：magazine 有兩個 a，可以各使用一次。

## 限制

- 1 <= ransomNote.length, magazine.length <= 10^5
- 兩個字串都只含小寫英文字母

## 解題思路

1. 建立 26 個計數欄位，掃描 magazine 並記下每個字母可用幾次。
2. 掃描 ransomNote；每需要一個字母，就將該字母的剩餘數量減 1。
3. 若某字母減完小於 0，表示 magazine 不夠用，回傳 false；全部用完仍足夠則回傳 true。

## 複雜度

- 時間：O(m + n)，m、n 分別是兩個字串的長度。
- 空間：O(1)，只使用 26 個計數欄位。

## C 函式簽名

~~~c
bool canConstruct(char* ransomNote, char* magazine);
~~~

## 程式如何運作

~~~c
bool canConstruct(char* ransomNote, char* magazine) {
    int available[26] = {0};
    int i;

    // 統計 magazine 中各字母可以使用的次數。
    for (i = 0; magazine[i] != '\0'; ++i) {
        ++available[magazine[i] - 'a'];
    }

    // 每拼出一個字母，就消耗一次可用數量。
    for (i = 0; ransomNote[i] != '\0'; ++i) {
        int letter = ransomNote[i] - 'a';
        --available[letter];

        if (available[letter] < 0) {
            return false;
        }
    }

    return true;
}
~~~
