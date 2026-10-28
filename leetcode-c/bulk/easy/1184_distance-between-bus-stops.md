# LeetCode 1184. Distance Between Bus Stops

**難度：Easy**

## 題意完整翻譯

有 n 個公車站沿著環狀路線排列，distance[i] 表示第 i 站到下一站（第 (i+1) % n 站）之間的距離。給定起點 start 和終點 destination，請回傳沿環狀路線前往目的地的兩條路徑中較短的距離。

## 範例

1. distance = [1,2,3,4], start = 0, destination = 1 → 1
2. distance = [1,2,3,4], start = 0, destination = 2 → 3（兩條路徑長度為 3 與 7）
3. distance = [1,2,3,4], start = 0, destination = 3 → 4（兩條路徑長度為 6 與 4）

## 限制

- 1 <= n <= 10⁴
- distance.length == n
- 0 <= start, destination < n
- 0 <= distance[i] <= 10⁴

## 解題思路

1. 先把所有路段距離加總，得到環路總長。
2. 從 start 出發，沿著索引增加方向走到 destination，累加走過的路段距離。
3. 另一條路的距離是環路總長減去剛才的路程；回傳兩者較小值。

## 複雜度

- 時間：O(n)
- 空間：O(1)

## C 函式簽名

~~~c
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。
