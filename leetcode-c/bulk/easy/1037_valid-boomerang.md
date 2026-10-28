# LeetCode 1037. Valid Boomerang

**難度：Easy**

## 題意完整翻譯

給定平面上的三個點 points[i] = [xi, yi]。若三個點彼此不同，且不在同一直線上，這組點就稱為迴力鏢。請判斷給定三點是否為迴力鏢。

## 範例

1. points = [[1,1],[2,3],[3,2]] → true
2. points = [[1,1],[2,2],[3,3]] → false（三點共線）

## 限制

- points.length == 3
- points[i].length == 2
- 0 <= xi, yi <= 100

## 解題思路

1. 把第一個點當原點，分別計算指向第二、第三點的兩個位移向量。
2. 計算二維叉積 dx1 × dy2 - dy1 × dx2。
3. 叉積不為 0 表示兩向量不平行，三點不共線；若有兩點重合，叉積也會是 0，因此同樣判為 false。

## 複雜度

- 時間：O(1)
- 空間：O(1)

## C 函式簽名

~~~c
bool isBoomerang(int** points, int pointsSize, int* pointsColSize);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式中的註解對應每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。
