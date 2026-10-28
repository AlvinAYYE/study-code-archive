# LeetCode 0201. Bitwise AND of Numbers Range

Title-CN: 範圍內數字的按位 AND

## 題目

給定兩個整數 left 和 right，請計算從 left 到 right（包含兩端）所有整數的按位 AND。

## 範例

1. 輸入：left = 5，right = 7；輸出：4。因為 5 AND 6 AND 7 = 4。
2. 輸入：left = 0，right = 0；輸出：0。
3. 輸入：left = 1，right = 2147483647；輸出：0。

## 限制

- 0 <= left <= right <= 2^31 - 1

## 解題思路

1. 把 left 和 right 同時右移，直到兩者相同。右移會保留共同的高位前綴，並逐步移除可能不同的低位。
2. 記錄右移次數 shift；相同前綴就是整個區間 AND 後一定保留的位元。
3. 最後把共同前綴左移 shift 位，低位補 0，得到區間 AND。

## 複雜度

時間 O(31)，額外空間 O(1)。

## C 函式簽名

int rangeBitwiseAnd(int left, int right)
