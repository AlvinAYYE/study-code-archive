# 412 Fizz Buzz：Fizz Buzz

**難度：** Easy

## 題意完整翻譯

給定整數 n，回傳長度為 n 的字串陣列，依序對應數字 1 到 n：若數字能被 3 整除，寫 Fizz；能被 5 整除，寫 Buzz；同時能被 3 與 5 整除，寫 FizzBuzz；其他數字則以十進位字串表示。

## 範例

### 範例 1

- 輸入：n = 3
- 輸出：["1","2","Fizz"]
- 說明：3 能被 3 整除，所以第三個字串是 Fizz。

### 範例 2

- 輸入：n = 5
- 輸出：["1","2","Fizz","4","Buzz"]
- 說明：5 能被 5 整除，所以第五個字串是 Buzz。

### 範例 3

- 輸入：n = 15
- 輸出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
- 說明：15 同時能被 3 與 5 整除，因此最後一項是 FizzBuzz。

## 限制

- 1 <= n <= 10^4

## 解題思路

1. 為答案配置 n 個字串位置。
2. 依序處理 1 到 n；先檢查能否同時被 3 和 5 整除，再分別檢查 3、5。
3. 以上條件都不符合時，將數字格式化成十進位字串。

## 複雜度

- 時間：O(n)，每個數字只檢查一次。
- 空間：O(n)，回傳 n 個字串及其內容。

## C 函式簽名

~~~c
char** fizzBuzz(int n, int* returnSize);
~~~

## 程式如何運作

~~~c
char** fizzBuzz(int n, int* returnSize) {
    char** answer = (char**)malloc(sizeof(char*) * (size_t)n);
    int i;

    *returnSize = n;

    for (i = 1; i <= n; ++i) {
        answer[i - 1] = (char*)malloc(9); /* FizzBuzz 最多 8 個字元。 */

        if (i % 15 == 0) {
            strcpy(answer[i - 1], "FizzBuzz");
        } else if (i % 3 == 0) {
            strcpy(answer[i - 1], "Fizz");
        } else if (i % 5 == 0) {
            strcpy(answer[i - 1], "Buzz");
        } else {
            sprintf(answer[i - 1], "%d", i);
        }
    }

    return answer;
}
~~~
