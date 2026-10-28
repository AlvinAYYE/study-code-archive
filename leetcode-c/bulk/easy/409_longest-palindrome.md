# 409 Longest Palindrome：最長回文

**難度：** Easy

## 題意完整翻譯

給定只含大小寫英文字母的字串 s，使用其中的字母可以組成的最長回文，最多能有多長？大小寫視為不同字母，例如 A 與 a 不能互相配對。只需回傳最長回文的長度，不必建立回文字串。

## 範例

### 範例 1

- 輸入：s = "abccccdd"
- 輸出：7
- 說明：可組成 "dccaccd"，長度為 7。

### 範例 2

- 輸入：s = "a"
- 輸出：1
- 說明：唯一的字母 a 可放在回文中央，長度為 1。

## 限制

- 1 <= s.length <= 2000
- s 只含大小寫英文字母

## 解題思路

1. 分別統計 26 個小寫字母與 26 個大寫字母的次數。
2. 每種字母可放入左右兩側的數量是其出現次數向下取偶數，例如 5 個可用 4 個。
3. 若有任一字母出現奇數次，可從其中一種字母取 1 個放在回文中央。

## 複雜度

- 時間：O(n + 52)，掃描字串並檢查固定 52 種字母。
- 空間：O(1)，只使用 52 個計數欄位。

## C 函式簽名

~~~c
int longestPalindrome(char* s);
~~~

## 程式如何運作

~~~c
int longestPalindrome(char* s) {
    int frequency[52] = {0};
    int length = 0;
    bool hasMiddle = false;
    int i;

    for (i = 0; s[i] != '\0'; ++i) {
        int letter;

        if (s[i] >= 'a') {
            letter = s[i] - 'a';
        } else {
            letter = s[i] - 'A' + 26;
        }
        ++frequency[letter];
    }

    for (i = 0; i < 52; ++i) {
        length += (frequency[i] / 2) * 2;
        if (frequency[i] % 2 == 1) {
            hasMiddle = true;
        }
    }

    return length + (hasMiddle ? 1 : 0);
}
~~~
