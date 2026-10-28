# LeetCode 1030. Matrix Cells in Distance Order

**難度：Easy**

## 題意完整翻譯

給定 rows × cols 的矩陣，以及中心格座標 (rCenter, cCenter)。請回傳矩陣內所有格子的座標，依照與中心格的曼哈頓距離由小到大排列。兩格 (r1,c1)、(r2,c2) 的距離是 |r1-r2| + |c1-c2|；距離相同時順序不限。

## 範例

1. rows = 1, cols = 2, rCenter = 0, cCenter = 0 → [[0,0],[0,1]]
2. rows = 2, cols = 2, rCenter = 0, cCenter = 1 → [[0,1],[0,0],[1,1],[1,0]]（同距離格子的先後可互換）
3. rows = 2, cols = 3, rCenter = 1, cCenter = 2 → [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]（距離依序為 0、1、1、2、2、3）

## 限制

- 1 <= rows, cols <= 100
- 0 <= rCenter < rows
- 0 <= cCenter < cols

## 解題思路

1. 從中心格開始做廣度優先搜尋（BFS），並只往上、下、左、右四個方向移動。
2. 第一次取出的格子距離最小；BFS 每一層代表距離增加 1，因此取出順序已符合題目要求。
3. 用 visited 陣列避免重複加入格子；每取出一格，就配置一個長度為 2 的座標列放進答案。

## 複雜度

- 時間：O(rows × cols)
- 空間：O(rows × cols)（佇列、標記及輸出）

## C 函式簽名

~~~c
int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式中的註解對應每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。
