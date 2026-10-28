# LeetCode 0210. Course Schedule II

Title-CN: 課程表 II

## 題目

共有 numCourses 門課，prerequisites[i] = [a, b] 表示必須先修完 b 才能修 a。請回傳一個能修完所有課程的順序；若無法完成（有循環），回傳空陣列。答案順序不唯一時，回傳任何一種都可以。

## 範例

1. 輸入：numCourses = 2，prerequisites = [[1,0]]；輸出：[0,1]。
2. 輸入：numCourses = 4，prerequisites = [[1,0],[2,0],[3,1],[3,2]]；輸出：[0,1,2,3] 或 [0,2,1,3]。
3. 輸入：numCourses = 1，prerequisites = []；輸出：[0]。

## 限制

- 1 <= numCourses <= 2000
- 0 <= prerequisites.length <= numCourses * (numCourses - 1)
- 每列長度為 2，且 ai != bi
- 先修組合不重複

## 解題思路

1. 把每個先修條件轉成「先修課 -> 後續課」的邊，並計算每門課的入度。
2. 先把所有入度為 0 的課放入佇列；這些課目前都可以直接修。
3. 逐一取出課程加入答案，再沿著它的邊降低後續課程入度；入度歸零就加入佇列。
4. 若答案包含所有課，回傳答案；若處理完仍有課未加入，表示有循環，釋放答案並回傳 NULL、將 returnSize 設為 0。

## 複雜度

時間 O(V + E)，額外空間 O(V + E)。

## C 函式簽名

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
