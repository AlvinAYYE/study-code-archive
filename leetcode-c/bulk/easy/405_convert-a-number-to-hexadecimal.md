# 405 Convert a Number to Hexadecimal：將數字轉成十六進位

**難度：** Easy

## 題意完整翻譯

給定 32 位元整數 num，回傳代表其十六進位表示的字串。負數使用二補數表示。結果中的英文字母必須是小寫，除了數字 0 本身以外不能有前導零；不可使用直接完成轉換的內建函式。

## 範例

### 範例 1

- 輸入：num = 26
- 輸出："1a"
- 說明：26 的十六進位是 1a。

### 範例 2

- 輸入：num = -1
- 輸出："ffffffff"
- 說明：32 位元二補數中的 -1，其 8 個十六進位數字都是 f。

## 限制

- -2^31 <= num <= 2^31 - 1

## 解題思路

1. 將 num 轉成 unsigned int，讓負數以 32 位元二補數位元模式處理。
2. 每次取最低 4 個位元（value & 0xf），查表得到一個十六進位數字，再將 value 右移 4 位。
3. 取出的數字順序相反，最後反向放入新字串。使用 do-while 確保 num 為 0 時也會產生字元 0。

## 複雜度

- 時間：O(1)，最多處理 8 個十六進位數字。
- 空間：O(1) 額外空間；回傳字串最多 8 個字元。

## C 函式簽名

~~~c
char* toHex(int num);
~~~

## 程式如何運作

~~~c
char* toHex(int num) {
    const char digits[] = "0123456789abcdef";
    char reversed[8];
    char* result;
    unsigned int value = (unsigned int)num;
    int length = 0;
    int i;

    // 每次取最低 4 位，轉成一個十六進位數字。
    do {
        reversed[length] = digits[value & 0x0f];
        ++length;
        value >>= 4;
    } while (value != 0);

    result = (char*)malloc((size_t)length + 1);
    for (i = 0; i < length; ++i) {
        result[i] = reversed[length - 1 - i];
    }
    result[length] = '\0';

    return result;
}
~~~
