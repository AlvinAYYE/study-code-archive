# 367 Valid Perfect Square：有效的完全平方數

**難度：** Easy

## 題意完整翻譯

給定正整數 num，判斷它是否為完全平方數。完全平方數可以寫成某個整數乘上自身，例如 16 = 4 × 4。不可使用 sqrt 等內建平方根函式。

## 範例

### 範例 1

- 輸入：num = 16
- 輸出：true
- 說明：4 × 4 = 16，且 4 是整數。

### 範例 2

- 輸入：num = 14
- 輸出：false
- 說明：14 的平方根不是整數，因此不是完全平方數。

## 限制

- 1 <= num <= 2^31 - 1

## 解題思路

1. 在 1 到 num 之間二分搜尋可能的整數平方根 middle。
2. 用 64 位元計算 middle × middle，避免 32 位元整數乘法溢位。
3. 若平方等於 num 就回傳 true；若平方太大，往左半部找；平方太小則往右半部找。
4. 搜尋範圍用完仍找不到時回傳 false。

## 複雜度

- 時間：O(log num)，二分搜尋每次將範圍縮小一半。
- 空間：O(1)。

## C 函式簽名

~~~c
bool isPerfectSquare(int num);
~~~

## 程式如何運作

~~~c
bool isPerfectSquare(int num) {
    int left = 1;
    int right = num;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        long long square = (long long)middle * middle;

        if (square == num) {
            return true;
        }
        if (square < num) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return false;
}
~~~
