# 345 Reverse Vowels of a String：反轉字串中的母音

**難度：** Easy

## 題意完整翻譯

給定字串 s，只反轉其中所有母音的位置，然後回傳字串。母音是 a、e、i、o、u，大小寫都算；其他字元（包含 y）保持原位。

## 範例

### 範例 1

- 輸入：s = "IceCreAm"
- 輸出："AceCreIm"
- 說明：從左右兩端找到母音並交換；其他字母不動。

### 範例 2

- 輸入：s = "leetcode"
- 輸出："leotcede"
- 說明：只交換 e、e、o、e 這些母音的前後位置。

## 限制

- 1 <= s.length <= 3 * 10^5
- s 只含可列印 ASCII 字元

## 解題思路

1. 用 left、right 指標分別從字串左右兩端往中間移動。
2. 左指標跳過非母音，右指標也跳過非母音。
3. 兩邊都停在母音時交換它們，再讓兩個指標繼續往中間走。
4. 指標相遇或交錯時結束；原字串已完成修改，直接回傳 s。

## 複雜度

- 時間：O(n)，左右指標合計最多走過字串一次。
- 空間：O(1)，只使用兩個指標與一個暫存字元。

## C 函式簽名

~~~c
char* reverseVowels(char* s);
~~~

## 程式如何運作

~~~c
static int isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

char* reverseVowels(char* s) {
    int left = 0;
    int right = (int)strlen(s) - 1;

    while (left < right) {
        char temp;

        // 往內找左側第一個母音。
        while (left < right && !isVowel(s[left])) {
            ++left;
        }

        // 往內找右側第一個母音。
        while (left < right && !isVowel(s[right])) {
            --right;
        }

        if (left < right) {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
    }

    return s;
}
~~~
