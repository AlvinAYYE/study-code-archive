# LeetCode 1266. Minimum Time Visiting All Points

**難度：Easy**

## 題意完整翻譯

給定平面上的 points，必須依照陣列順序逐一拜訪所有點。每秒可以往上下左右移動一格，或沿對角線移動一格。請回傳完成所有拜訪所需的最短秒數。

## 範例

1. points = [[1,1],[3,4],[-1,0]] → 7（兩段路程分別需要 3 秒與 4 秒）
2. points = [[3,2],[-2,2]] → 5

## 限制

- 1 <= points.length <= 100
- 每個點恰有 x、y 兩個座標
- -1000 <= x, y <= 1000

## 解題思路

1. 依序處理相鄰的兩個點，計算水平距離 dx 和垂直距離 dy。
2. 每秒可同時沿 x、y 方向各移動一格，因此先沿對角線走 min(dx, dy) 秒。
3. 剩下較長方向的差距再直線走完；這一段兩點間最短時間就是 max(dx, dy)。
4. 把每一段的 max(dx, dy) 加總並回傳。

## 複雜度

- 時間：O(n)
- 空間：O(1)

## C 函式簽名

~~~c
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。
