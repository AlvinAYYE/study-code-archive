# 0207. Course Schedule《課程表》

- **Difficulty**: Medium
- **Tags**: depth-first-search, breadth-first-search, graph, topological-sort
- **題目連結**: https://leetcode.com/problems/course-schedule/
- **程式碼**: [`207_course-schedule.c`](./207_course-schedule.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

共有編號 0 至 numCourses - 1 的課程，prerequisites 中的 [a, b] 表示修習 a 前必須先修 b。請判斷是否能完成所有課程。若先修關係形成循環，則無法完成。

**思路**：以鄰接矩陣表示有向圖，並進行 DFS；節點在目前遞迴路徑中標記為造訪中，若再次走到此類節點即偵測到環。

## Problem Statement (English)

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
Return true if you can finish all courses. Otherwise, return false.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```

## 限制 Constraints

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

## 官方 C 函式簽名 Signature

```c
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
}
```
