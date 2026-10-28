# 389 Find the Difference：找出字串中的差異

**難度：** Easy

## 題意完整翻譯

給定字串 s 與 t。t 是將 s 的字母重新排列後，再額外插入一個小寫字母所形成的字串。請回傳新增的那個字母。

## 範例

### 範例 1

- 輸入：s = "abcd", t = "abcde"
- 輸出："e"
- 說明：e 是 t 中多出來的字母。

### 範例 2

- 輸入：s = "", t = "y"
- 輸出："y"
- 說明：s 是空字串，t 唯一的字母 y 就是新增字母。

## 限制

- 0 <= s.length <= 1000
- t.length == s.length + 1
- s 與 t 都只含小寫英文字母

## 解題思路

1. 用 26 個計數欄位記錄字母差異。
2. 掃描 s 時把字母計數加 1；掃描 t 時把字母計數減 1。
3. s 中原有字母會互相抵銷，唯一計數不為 0 的字母就是新增字母。

## 複雜度

- 時間：O(|s| + |t|)，各掃描一次。
- 空間：O(1)，只使用 26 個計數欄位。

## C 函式簽名

~~~c
char findTheDifference(char* s, char* t);
~~~

## 程式如何運作

~~~c
char findTheDifference(char* s, char* t) {
    int difference[26] = {0};
    int i;

    for (i = 0; s[i] != '\0'; ++i) {
        ++difference[s[i] - 'a'];
    }
    for (i = 0; t[i] != '\0'; ++i) {
        --difference[t[i] - 'a'];
    }

    for (i = 0; i < 26; ++i) {
        if (difference[i] != 0) {
            return (char)('a' + i);
        }
    }

    return '\0'; /* 題目保證 t 一定多出一個字母，不會走到這裡。 */
}
~~~
