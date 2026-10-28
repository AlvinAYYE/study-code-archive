# LeetCode 1232. Check If It Is a Straight Line

**難度：Easy**

## 題意完整翻譯

給定平面上至少兩個互不相同的點 coordinates，判斷所有點是否位於同一條直線上。若共線回傳 true，否則回傳 false。

## 範例

1. coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]] → true
2. coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]] → false

## 限制

- 2 <= coordinates.length <= 1000
- 每個座標恰有 x、y 兩個整數
- -10⁴ <= x, y <= 10⁴
- coordinates 不含重複點

## 解題思路

1. 取前兩個點作為基準，計算它們的方向向量 (dx, dy)。
2. 逐一計算基準第一點到其他點的向量 (x, y)。
3. 若每個向量與基準方向的叉積 dx × y - dy × x 都是 0，表示所有點共線；只要有一個不為 0 就不是直線。

## 複雜度

- 時間：O(n)
- 空間：O(1)

## C 函式簽名

~~~c
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。
