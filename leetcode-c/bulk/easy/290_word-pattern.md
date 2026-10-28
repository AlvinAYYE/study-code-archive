# 290 Word Pattern：單詞規律

**難度：** Easy

## 題意完整翻譯

給定由小寫英文字母組成的 pattern，以及由單字和單一空格組成的字串 s，判斷 s 是否符合 pattern。符合代表一對一對應：pattern 中每種字母固定對應一個非空單字，而且不同字母不能對應到同一個單字。

## 範例

### 範例 1

- 輸入：pattern = "abba", s = "dog cat cat dog"
- 輸出：true
- 說明：a 對應 dog，b 對應 cat，兩邊一對一且順序相符。

### 範例 2

- 輸入：pattern = "abba", s = "dog cat cat fish"
- 輸出：false
- 說明：最後一個 a 對應 fish，與前面 a 對應的 dog 不同。

### 範例 3

- 輸入：pattern = "aaaa", s = "dog cat cat dog"
- 輸出：false
- 說明：同一個字母 a 對應到了不同單字。

## 限制

- 1 <= pattern.length <= 300
- pattern 只含小寫英文字母
- 1 <= s.length <= 3000
- s 只含小寫英文字母與空格，且沒有首尾空格
- s 中相鄰單字恰以一個空格分隔

## 解題思路

1. 用 26 個欄位記錄每個字母第一次對應到的單字起點與長度。
2. 依序取出 pattern 字母與 s 的下一個單字。若字母已經對應，確認單字內容完全相同。
3. 若字母還沒對應，檢查這個單字是否已被其他字母使用；若有就不符合，否則建立對應。
4. 最後確認 pattern 與 s 的單字都剛好用完。

## 複雜度

- 時間：O(pattern 長度 + s 長度)；每個字母最多與固定 26 個映射比較。
- 空間：O(1)，只存固定 26 個字母的映射，不修改 s。

## C 函式簽名

~~~c
bool wordPattern(char* pattern, char* s);
~~~

## 程式如何運作

~~~c
static int sameWord(const char* first, int firstLength,
                    const char* second, int secondLength) {
    return firstLength == secondLength &&
           memcmp(first, second, (size_t)firstLength) == 0;
}

bool wordPattern(char* pattern, char* s) {
    const char* wordStart[26] = {0};
    int wordLength[26] = {0};
    int patternIndex = 0;
    int position = 0;
    int i;

    while (pattern[patternIndex] != '\0') {
        int start;
        int length;
        int letter;

        // pattern 還有字母時，s 必須還有下一個單字。
        if (s[position] == '\0') {
            return false;
        }

        start = position;
        while (s[position] != '\0' && s[position] != ' ') {
            ++position;
        }
        length = position - start;
        letter = pattern[patternIndex] - 'a';

        if (wordStart[letter] != NULL) {
            // 已建立的字母只能再次對應到同一個單字。
            if (!sameWord(wordStart[letter], wordLength[letter],
                          s + start, length)) {
                return false;
            }
        } else {
            // 不同字母不能共用同一個單字。
            for (i = 0; i < 26; ++i) {
                if (wordStart[i] != NULL &&
                    sameWord(wordStart[i], wordLength[i], s + start, length)) {
                    return false;
                }
            }
            wordStart[letter] = s + start;
            wordLength[letter] = length;
        }

        ++patternIndex;
        if (s[position] == ' ') {
            ++position;
        }
    }

    // pattern 用完後，s 也必須沒有剩餘單字。
    return s[position] == '\0';
}
~~~
