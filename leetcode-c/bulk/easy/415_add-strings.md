# 415 Add Strings：字串相加

**難度：** Easy

## 題意完整翻譯

給定以字串表示的兩個非負整數 num1 與 num2，請回傳它們相加後的字串。不可直接將輸入轉成整數，也不可使用大整數函式庫；請像直式加法一樣逐位計算。

## 範例

### 範例 1

- 輸入：num1 = "11", num2 = "123"
- 輸出："134"
- 說明：11 + 123 = 134。

### 範例 2

- 輸入：num1 = "456", num2 = "77"
- 輸出："533"
- 說明：從右向左逐位相加並處理進位，結果為 533。

### 範例 3

- 輸入：num1 = "0", num2 = "0"
- 輸出："0"
- 說明：兩個零相加仍是字串 0。

## 限制

- 1 <= num1.length, num2.length <= 10^4
- num1 與 num2 只含數字
- 除了字串 0 本身，輸入沒有前導零

## 解題思路

1. 配置可容納較長輸入長度加一位的結果緩衝區，並從兩字串最右端開始。
2. 逐位將兩個數字與 carry 相加；目前位寫入總和除以 10 的餘數，carry 更新為總和除以 10。
3. 其中一個字串用完後，把缺少的位數當成 0；直到兩個字串都用完且 carry 為 0。
4. 結果目前是倒著寫入，將有效部分移到緩衝區開頭並回傳。

## 複雜度

- 時間：O(max(m,n))，逐位處理兩個字串。
- 空間：O(max(m,n))，結果字串需要額外儲存。

## C 函式簽名

~~~c
char* addStrings(char* num1, char* num2);
~~~

## 程式如何運作

~~~c
char* addStrings(char* num1, char* num2) {
    int length1 = (int)strlen(num1);
    int length2 = (int)strlen(num2);
    int maxLength = length1 > length2 ? length1 : length2;
    char* answer = (char*)malloc((size_t)maxLength + 2);
    int i = length1 - 1;
    int j = length2 - 1;
    int position = maxLength;
    int carry = 0;

    answer[maxLength + 1] = '\0';

    while (i >= 0 || j >= 0 || carry != 0) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        answer[position] = (char)('0' + sum % 10);
        carry = sum / 10;
        --position;
        --i;
        --j;
    }

    // 有效答案從 position + 1 開始，將它連同結尾字元移到字串開頭。
    memmove(answer, answer + position + 1, (size_t)(maxLength - position + 1));
    return answer;
}
~~~
