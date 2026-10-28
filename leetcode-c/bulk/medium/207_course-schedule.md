# LeetCode 0207. Course Schedule

Title-CN: 課程表

## 題目

共有 numCourses 門課，課號為 0 到 numCourses-1。prerequisites[i] = [a, b] 表示必須先修完課程 b，才能修課程 a。判斷是否能修完所有課程；若先修關係形成循環，就無法完成。

## 範例

1. 輸入：numCourses = 2，prerequisites = [[1,0]]；輸出：true。先修 0 再修 1 即可。
2. 輸入：numCourses = 2，prerequisites = [[1,0],[0,1]]；輸出：false。兩門課互相要求先修，形成循環。

## 限制

- 1 <= numCourses <= 2000
- 0 <= prerequisites.length <= 5000
- 每列長度為 2；課號介於 0 和 numCourses-1 之間
- 先修組合不重複

## 解題思路

1. 把課程視為圖上的節點；每個 [課程, 先修課] 轉成先修課指向課程的一條有向邊。
2. 記錄每門課還有幾個先修條件（入度），把入度為 0 的課放進佇列。
3. 每修完一門課，就沿著它的邊減少後續課程入度；入度降到 0 時即可入列。
4. 若最後處理的課數等於 numCourses，代表沒有循環，可以修完；否則有課仍被循環卡住。

## 複雜度

時間 O(V + E)，額外空間 O(V + E)；V 是課程數，E 是先修關係數。

## C 函式簽名

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
